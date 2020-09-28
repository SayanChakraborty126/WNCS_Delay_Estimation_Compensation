byte z;
void setup() {
  Serial.begin(115200);
  //Serial1.begin(115200);
  //delay(10000);
}

void loop() {
  if (Serial.available())
  {
    z = Serial.read();


  }
  delay(20);
  //byte x = random(10);
  Serial.write(z);

}
