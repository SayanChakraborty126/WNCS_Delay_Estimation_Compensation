byte drive = 100;
unsigned long t;
byte rpm;
unsigned long t2 = 0;
unsigned long t1 = 0;
unsigned long t3 = 0;
unsigned long tr;
boolean a = false;
void setup() {
  delay(5000);
  Serial.begin(115200);
  Serial1.begin(115200);
}

void loop() {


  if (a == true)
  {
    while (Serial1.available() == 0) {}
  }


  if (Serial1.available() )
  {
    rpm = Serial1.read();
    if (rpm == 0)
    {
      tr++;
    }
    t2 = millis() - 5000;
    t = t2 - t1;

    Serial.print(t1);
    Serial.print("\t");
    Serial.print(t2);
    Serial.print("\t");
    Serial.print(t);
    Serial.print("\t");
    Serial.print(tr);
    Serial.print("\t");
    Serial.println(rpm);
    t1 = millis() - 5000;
    Serial1.write(drive);
    a = true;
  }







}
