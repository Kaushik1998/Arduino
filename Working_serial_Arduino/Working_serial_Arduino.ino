#include<SoftwareSerial.h>
SoftwareSerial Serial1(0,1);
int temp,humi;

String str;
void setup(){
 Serial.begin(115200);
 Serial1.begin(115200);
 Serial.print(char(169)); // Copyright Symbol
 Serial.println(" Myengineeringstuffs.com");
 delay(2000);
}
void loop()
{

  humi=123;
  temp=6969;
  Serial.print("H: ");
  Serial.print(humi); 
  Serial.print("% ");
  Serial.print(" T: ");
  Serial.print(temp); 
  Serial.print(char(176));
  Serial.println("C");
  //str =String('H')+String(humi)+String('T')+String(temp);
  Serial1.println("1,1,39.00,85,ON");
  delay(5000);
}
