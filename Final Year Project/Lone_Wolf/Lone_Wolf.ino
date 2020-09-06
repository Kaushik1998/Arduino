#include<SoftwareSerial.h>
SoftwareSerial s(2,3);

//Water Sensor
int resval = 0;  // holds the value
int respin = A0; // sensor pin used

//Temperature
float temp;
int sensor=0;
//LDR
int sensorPin=A1;
int ledPin=13;
unsigned int sensorValue=0;

// Ultrasonic
const int trigPin=9;
const int echoPin=10;
long duration;
int distance;


void setup() {
  // put your setup code here, to run once:
//LDR
  pinMode(ledPin,OUTPUT);
  //Ultrasonic
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
    Serial.begin(115200);
    s.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  /*
Serial.println(getTemp());
Serial.println(setLDR());
Serial.println(getDist());
  */
  Serial.println(getKey("Bright",getDist(),32,"OFF","ON",water(), "Inside"));

delay(5000);
}

float getTemp()
{
  temp=analogRead(sensor);
  temp=temp*0.48828125;
  return temp;
}

String setLDR()
{
sensorValue=analogRead(sensorPin);
if(sensorValue<15)
{
digitalWrite(ledPin,HIGH);
return "ON";
}
else
{
digitalWrite(ledPin,LOW);
return "OFF";
}
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
 
  if (resval<=100){ return "EMPTY"; } else if (resval>100 && resval<=650){ return "Low"; } else if (resval>650 && resval<=700){ return "Medium"; } else if (resval>700){ 
    return "High"; 
  }
}

String getKey(String ldr,String dist,int temp, String led1, String led2, String water , String location)
{
  String message="";
  String dilimeter=",";
  message+=ldr+dilimeter;
  message+=String(dist)+dilimeter;
  message+=String(temp)+dilimeter;
  message += led1 + dilimeter;
  message += led2 + dilimeter;
  message += water + dilimeter;
  message += location + dilimeter;
  return message;
}
