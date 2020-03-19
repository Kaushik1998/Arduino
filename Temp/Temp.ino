float temp;
int sensor=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
temp=analogRead(sensor);
temp=temp*0.48828125;

Serial.print("\nThe Temperature is  ");
Serial.println(temp);
Serial.print("  Deg.Celsius");
delay(1000);
}
