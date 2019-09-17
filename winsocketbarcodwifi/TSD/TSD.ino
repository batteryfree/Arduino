#include <usbhid.h>
#include <usbhub.h>
#include <hiduniversal.h>
#include <hidboot.h>
#include <SPI.h>
void SendMessage();
void(* resetFunc) (void) = 0;
unsigned long timing;
String Message;
int Relay=7;
class MyParser : public HIDReportParser {
  public:
    MyParser();
    void Parse(USBHID *hid, bool is_rpt_id, uint8_t len, uint8_t *buf);
  protected:
    uint8_t KeyToAscii(bool upper, uint8_t mod, uint8_t key);
    virtual void OnKeyScanned(bool upper, uint8_t mod, uint8_t key);
    virtual void OnScanFinished();
};

MyParser::MyParser() {}

void MyParser::Parse(USBHID *hid, bool is_rpt_id, uint8_t len, uint8_t *buf) {

  if (buf[2] == 1 || buf[2] == 0) return;
  for (uint8_t i = 7; i >= 2; i--) {

    if (buf[i] == 0) continue;

    if (buf[i] == UHS_HID_BOOT_KEY_ENTER) {
      OnScanFinished();
    }

    else {

      OnKeyScanned(i > 2, buf, buf[i]);
    }
    return;
  }
}

uint8_t MyParser::KeyToAscii(bool upper, uint8_t mod, uint8_t key) {

  if (VALUE_WITHIN(key, 0x04, 0x1d)) {
    if (upper) return (key - 4 + 'A');
    else return (key - 4 + 'a');
  }

  else if (VALUE_WITHIN(key, 0x1e, 0x27)) {
    return ((key == UHS_HID_BOOT_KEY_ZERO) ? '0' : key - 0x1e + '1');
  } else if(VALUE_WITHIN(key, 0x2d, 0x38)) {
            return (key - 0x2d + '-');   
               

        }
  
  return 0;
}

void MyParser::OnKeyScanned(bool upper, uint8_t mod, uint8_t key) {
  uint8_t ascii = KeyToAscii(upper, mod, key);
  Message+=(char)ascii;
}

void MyParser::OnScanFinished() {
   digitalWrite(Relay, LOW);
   
   SendMessage();


  
  Message="";
  
}

USB          Usb;
USBHub       Hub(&Usb);
HIDUniversal Hid(&Usb);
MyParser     Parser;

void setup() {
  Serial.begin(115200);
  while (!StartRST())
  {delay(1000);}
  while (!ConnetToServer("192.168.23.14",3333))
  {delay(1000);}
  if (Usb.Init() == -1) {

  }
  delay( 200 );
  Hid.SetReportParser(0, &Parser);
  pinMode(Relay,OUTPUT);
}
boolean StartRST(void){ 
  boolean result = false;
  Serial.flush();
  Serial.setTimeout(3000);
  Serial.println("AT+RST");
  result = Serial.find("eady");
  if(result){
    return 1;
  }
  else{
    digitalWrite(Relay, LOW);
    return 0;
  }
}



void SendMessage(){
  boolean result = false;
  digitalWrite(Relay, LOW);
  Serial.flush();
  Serial.setTimeout(3000);
  Serial.println("AT+CIPSEND="+String(Message.length()));
  result = Serial.find(">");
  if (result){
    Serial.println(Message); 
    digitalWrite(Relay,HIGH);
    timing = millis();  
  }
  else{ int i = 0;
     while (!ConnetToServer("192.168.23.14",3333)){
      delay(1000);
      i++;
      if (i = 20){
        resetFunc();
      } 
    }
    SendMessage();  
  }
}


boolean ConnetToServer(String IP,int Port){
  boolean result = false;
  Serial.flush();
  Serial.setTimeout(3000);
  Serial.println("AT+CIPSTART=\"TCP\",\""+IP+"\","+String(Port));
  result = Serial.find("OK");
  if(result){
    digitalWrite(Relay, HIGH);
    timing = millis();
    return 1;
  }
  else{
    digitalWrite(Relay, LOW);
    return 0;
  } 
}





void loop() {
  Usb.Task();
if (millis() - timing > 10000){
  timing = millis();
  if (digitalRead(Relay)){
    
    digitalWrite(Relay, LOW);
    delay(100);
    digitalWrite(Relay, HIGH);
  }
}

}

