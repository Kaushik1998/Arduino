#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <SoftwareSerial.h>
#define FIREBASE_HOST "root-anvil-262211.firebaseio.com"
#define FIREBASE_AUTH "fCMKWSY7OycbDmWcmdrIntHRzqIof0HtqCh1Aq8O"
#define WIFI_SSID "Kaushik"
#define WIFI_PASSWORD "9137312358"


String apiWritekey = "LD2DV33OSZWOHDNL"; // replace with your THINGSPEAK WRITEAPI key here
const char* server = "api.thingspeak.com";
float resolution=3.3/1023;// 3.3 is the supply volt  & 1023 is max analog read value
WiFiClient client;

SoftwareSerial s(10,9);


int k;
String s1,s2,s3,s4,s5,s6,s7;
void setup() {
  // Open serial communications and wait for port to open:
  s.begin(115200);
  Serial.begin(115200);
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
}

void loop() { // run over and over
  if (Serial.available()) {
    //Serial.write(Serial.read());
char gfg[100];
String ksn = Serial.readString(); 
  ksn.toCharArray(gfg,100);
    // Declaration of delimeter 
    const char s[4] = ","; 
    char* tok; 
    String arr[10];
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
    Serial.println("------------------------------This is demo-----------------------------");
    s1=arr[0];
    Serial.print(s1);
    Serial.print("   ");
    s2=arr[1];
    Serial.print(s2);
    Serial.print("   ");
    s3=arr[2];
    Serial.print(s3);
    Serial.print("   ");
    s4=arr[3];
    Serial.print(s4);
    Serial.print("   ");
    s5=arr[4];
    Serial.print(s5);
    Serial.print("   ");
    s6=arr[5];
    Serial.print(s6);
    Serial.print("   "); 
    s7=arr[6];
    Serial.print(s7);
    Serial.print("   ");    
    Serial.print("--------------------------------------------------");


    firebaseUpload("LDR",s1);
    firebaseUpload("Distance",s2);
    firebaseUpload("Temperature",s3);
    firebaseUpload("LED1",s4);
    firebaseUpload("LED2",s5);
    firebaseUpload("Water",s6);
    firebaseUpload("Location",s7);

/*---------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------*/

  uploadThingSpeak(s2,1);
    delay(5000);

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
void uploadThingSpeak(String data, int field){
    if (client.connect(server,80))
  {  
    String tsData = apiWritekey;
           tsData +=getField(field);
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
     Serial.println("uploaded to Thingspeak server....");
  }
  client.stop();
  Serial.println("Uploaded : ");
  Serial.println(data);

}



/*------------------------------------------------------------------------------------------------------------*/
String getField(int a){
  String message = "&field";
  message+=a;
  message+="=";
  return message;
}


void types(String a){Serial.println("it's a String");}
void types(int a)   {Serial.println("it's an int");}
void types(char* a) {Serial.println("it's a char*");}
void types(float a) {Serial.println("it's a float");} 
