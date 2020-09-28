byte drive;
unsigned long t2;
unsigned long t3;
unsigned long t4;
void setup() {
  delay(5000);
  Serial.begin(115200);
  Serial1.begin(115200);

}

void loop() {

  if (Serial1.available())
  {

    drive = Serial1.read();


  }
  delay(20);
  int x = random(15);
  delay(x);
  Serial1.write(drive);


}
