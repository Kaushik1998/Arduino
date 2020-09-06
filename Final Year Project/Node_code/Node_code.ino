char k;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
k=Serial.read();
Serial.println(k);
delay(1000);
}
