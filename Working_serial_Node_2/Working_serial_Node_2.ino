#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "root-anvil-262211.firebaseio.com"
#define FIREBASE_AUTH "fCMKWSY7OycbDmWcmdrIntHRzqIof0HtqCh1Aq8O"
#define WIFI_SSID "Kaushik"
#define WIFI_PASSWORD "9137312358"


int k;
String s1,s2,s3,s4,s5,s6,s7;
void setup() {
  // Open serial communications and wait for port to open:
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
    Serial.print(s7);
    Serial.print("   ");    
    Serial.print("--------------------------------------------------");
    
      Firebase.setString("LED", s1);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /LED failed:");
      Serial.println(Firebase.error());  
      return;
  }


  Firebase.setString("Temp", s2);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /Temp failed:");
      Serial.println(Firebase.error());  
      return;
  }

    Firebase.setString("Temperature", s3);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /Temp failed:");
      Serial.println(Firebase.error());  
      return;
  }

      Firebase.setString("LED1", s4);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /Dist failed:");
      Serial.println(Firebase.error());  
      return;
  }
        Firebase.setString("LED2", s5);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /Dist failed:");
      Serial.println(Firebase.error());  
      return;
  }

        Firebase.setString("WaterSensor", s6);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /Dist failed:");
      Serial.println(Firebase.error());  
      return;
  }
          Firebase.setString("Location", s7);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /Location failed:");
      Serial.println(Firebase.error());  
      return;
  }
    delay(5000);
    

  }
}

void types(String a){Serial.println("it's a String");}
void types(int a)   {Serial.println("it's an int");}
void types(char* a) {Serial.println("it's a char*");}
void types(float a) {Serial.println("it's a float");} 
