byte drive;
unsigned long t2;
unsigned long t3;
unsigned long t4;
void setup() {
  delay(10000);
  Serial.begin(115200);
  //Serial1.begin(115200);

}

void loop() {

  if (Serial.available())
  {

    drive = Serial.read();


  }
  delay(20);
  //  int x = random(100);
  //  delay(x);
  byte rpm = drive;
  Serial.write(rpm);


}
