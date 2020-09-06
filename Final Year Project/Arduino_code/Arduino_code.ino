#include<SoftwareSerial.h> //Included SoftwareSerial Library
//Started SoftwareSerial at RX and TX pin of ESP8266/NodeMCU
SoftwareSerial s(3,1);
int k;
void setup() {
  pinMode(13,OUTPUT);
  //Serial S Begin at 9600 Baud
  s.begin(9600);
  Serial.begin(9600);
}

void loop() {
  //Write '123' to Serial
  k=Serial.read();
  Serial.println(k);
  if (k==1){
    digitalWrite(13,HIGH);
  }
  else{
    digitalWrite(13,LOW);
  }

}
