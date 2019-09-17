#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>

RF24 radio(9, 10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
String str;
int r=7;
int t=0;

void setup() {
  Serial.begin(9600);
  mp3_set_serial(Serial);
  delay (100);
  mp3_set_volume(25);
  delay (100);
  mp3_play(1);
  delay (100);
  delay(10000);
  radio.begin();
  radio.openReadingPipe(1, pipe);
  radio.startListening();
  pinMode(r,OUTPUT);
  digitalWrite(r, HIGH);
}

void loop() {
//radio.openReadingPipe(1, pipe);
if (radio.available()){
//  Serial.println("in port");
  char d[32]="" ;
  radio.read(&d, sizeof(d));
  str = d;
// Serial.println(str);
  if (str == "911"){
    digitalWrite(r, LOW);
    t=1;
   }}
if (t>0){
 t=0;
 delay (100);
  mp3_play(2);
   delay (10000);
}}

