#include<SoftwareSerial.h>
SoftwareSerial s(2,3);

//Water Sensor
int resval = 0;  // holds the value
int respin = A0; // sensor pin used
int waterValue=1;

// Ultrasonic
const int trigPin=9;
const int echoPin=10;
long duration;
int distance;


void setup() {
  // put your setup code here, to run once:

  //Ultrasonic
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
    Serial.begin(115200);
    s.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:


 Serial.print(getKey(getDist(),water(),waterValue));
 delay(5000);

}





String getDist()
{
digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(2);
delay(250);
digitalWrite(trigPin,LOW);
duration=pulseIn(echoPin,HIGH);
distance=duration*0.034/2;
if (distance >=15){
  return "Out_Of_Range";
}
else{
  return String(distance);
}
}

String water(){
    resval = analogRead(respin); //Read data from analog pin and store it to resval variable
 
  if (resval<=100){ waterValue=0; return "EMPTY";  } else if (resval>100 && resval<=650){ waterValue=1;return "Low"; } else if (resval>650 && resval<=700){ waterValue=1; return "Medium"; } else if (resval>700){ 
    waterValue=1; return "High"; 
  }
}

void setWV(int i){
  waterValue=i;
}
String getKey(String dist,String water,int wv)
{
  String message="";
  String dilimeter=",";
  message+=dist+dilimeter;
  message += water+dilimeter;
  message += String(wv)+dilimeter;
  return message;
}
