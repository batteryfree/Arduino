//work
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
char alarm[]="911";
String str; 
int switchPin = 2;

void setup() {
  radio.begin();
  radio.openWritingPipe(pipe);
  pinMode(switchPin, INPUT);
}

void loop() {
  if (digitalRead(switchPin) == HIGH){
  str="911";
  str.toCharArray(alarm,sizeof(alarm)+2);
  radio.powerUp();
    for (int i=1;i<10;i++){
      radio.write(alarm, sizeof(alarm)+2);  
      delay(100);
}}}
