int k;
String a;
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
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
    Serial.println("-----------------------This Is Array----------------------------");
    for (int i =0; i<4; i++) Serial.println(arr[i]);
    Serial.println("------------------------------This is demo-----------------------------");
    Serial.println(arr[0]);
    Serial.println(arr[1]);
    Serial.println(arr[2]);
    Serial.println("--------------------------------------------------");
    delay(5000);

  }
}

void types(String a){Serial.println("it's a String");}
void types(int a)   {Serial.println("it's an int");}
void types(char* a) {Serial.println("it's a char*");}
void types(float a) {Serial.println("it's a float");} 
