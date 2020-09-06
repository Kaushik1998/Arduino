#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <SoftwareSerial.h>
#define FIREBASE_HOST "root-anvil-262211.firebaseio.com"
#define FIREBASE_AUTH "fCMKWSY7OycbDmWcmdrIntHRzqIof0HtqCh1Aq8O"
#define WIFI_SSID "Kaushik"
#define WIFI_PASSWORD "9137312358"
#include <BlynkSimpleEsp8266.h>
#define BLYNK_PRINT s
char auth[] = "Ydy3_D7VXgfgMdO9Fb09zqISTwcoy_Xm";
SoftwareSerial s(10,9);
String apiWritekey = "LD2DV33OSZWOHDNL"; // replace with your THINGSPEAK WRITEAPI key here
const char* server = "api.thingspeak.com";

WiFiClient client;

int k;
String s1,s2,s3,s4,s5,s6,s7;

int sensorPin=A0;
int ledPin=12;
unsigned int sensorValue=0;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  s.begin(115200);
    pinMode(ledPin,OUTPUT);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
      Blynk.begin(auth,WIFI_SSID, WIFI_PASSWORD);
}

void loop() { // run over and over
    Blynk.run();
    
  if (Serial.available()) {
    //Serial.write(Serial.read());
char gfg[100];
String ksn = Serial.readString(); 
  ksn.toCharArray(gfg,100);
    // Declaration of delimeter 
    const char s[4] = ","; 
    char* tok; 
    String arr[2];
    int i=0;
  
    // Use of strtok 
    // get first token 
    tok = strtok(gfg, s); 

    // Checks for delimeter 
    while (tok != 0) { 
        Serial.println(tok);
        arr[i]=tok;
        i+=1; 
        // Use of strtok 
        // go through other tokens 
        tok = strtok(0, s); 
    } 
    s1=arr[0];

    s2=arr[1];

    s3=arr[2];

    
    firebaseUpload("Distance",s1);
    firebaseUpload("Water",s2);
    Serial.println("------------------------------------------------------------------------");
    Serial.println(s3);
  }
  firebaseUpload("Temperature","32.0");
  firebaseUpload("Location","Inside");
  firebaseUpload("LED D8",getD8());
  firebaseUpload("LED D7",getD7());
  firebaseUpload("LDR",getLDR());

}

String getD8(){
  if(digitalRead(D8) == HIGH)
  {
    return "HIGH";
  }
  else{
    return "LOW";
  }
}
String getD7(){
  if(digitalRead(D7) == HIGH)
  {
    return "HIGH";
  }
  else{
    return "LOW";
  }
}

String getD5(){
  if(digitalRead(D5) == HIGH)
  {
    return "Inside";
  }
  else{
    return "Outside";
  }
}

void firebaseUpload(String field,String data){
        Firebase.setString(field, data);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /"+field+" failed:");
      Serial.println(Firebase.error());  
      return;
  }
}
void uploadDist(String data){
    if (client.connect(server,80))
  {  
    String tsData = apiWritekey;
           tsData +="&field1=";//"&field1="
           tsData += String(data);
           tsData += "\r\n\r\n";
 
     client.print("POST /update HTTP/1.1\n");
     client.print("Host: api.thingspeak.com\n");
     client.print("Connection: close\n");
     client.print("X-THINGSPEAKAPIKEY: "+apiWritekey+"\n");
     client.print("Content-Type: application/x-www-form-urlencoded\n");
     client.print("Content-Length: ");
     client.print(tsData.length());
     client.print("\n\n");  // the 2 carriage returns indicate closing of Header fields & starting of data
     client.print(tsData);
  }
  client.stop();
}

void uploadWater(String data){
    if (client.connect(server,80))
  {  
    String tsData = apiWritekey;
           tsData +="&field2=";//"&field1="
           tsData += String(data);
           tsData += "\r\n\r\n";
 
     client.print("POST /update HTTP/1.1\n");
     client.print("Host: api.thingspeak.com\n");
     client.print("Connection: close\n");
     client.print("X-THINGSPEAKAPIKEY: "+apiWritekey+"\n");
     client.print("Content-Type: application/x-www-form-urlencoded\n");
     client.print("Content-Length: ");
     client.print(tsData.length());
     client.print("\n\n");  // the 2 carriage returns indicate closing of Header fields & starting of data
     client.print(tsData);
  }
  client.stop();
}



/*------------------------------------------------------------------------------------------------------------*/
String getField(int a){
  String message = "&field";
  message+=a;
  message+="=";
  return message;
}

String getLDR(){
  sensorValue=analogRead(sensorPin);
  Serial.println(sensorValue);
if(sensorValue<30)
{
digitalWrite(ledPin,HIGH);
return "HIGH";
}
else
{
digitalWrite(ledPin,LOW);
return "LOW";
}
}


String thingSpeakWater(String s){
  if (s.equals("Low")||s.equals("Medium")||s.equals("High")){
    return "1";
  }
  else{
    return "0";
  }
}
void types(String a){Serial.println("it's a String");}
void types(int a)   {Serial.println("it's an int");}
void types(char* a) {Serial.println("it's a char*");}
void types(float a) {Serial.println("it's a float");} 
