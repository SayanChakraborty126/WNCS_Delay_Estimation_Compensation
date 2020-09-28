byte rpm = 100;
unsigned long t;
byte received;
unsigned long t2 = 0;
unsigned long t1 = 0;
unsigned long t3 = 0;
unsigned long trV;
unsigned long trD;
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
    received = Serial1.read();
    t2 = millis() - 5000;

    tr = tr + t;
    if (received == 0 && (a == true))
    {
      trV = 20 + trV;
    }
    t = t2 - t1;
    if (received != 0 && (a == true))
    {
      trD = t + tr;
    }


    Serial.print(t1);
    Serial.print("\t");
    Serial.print(t2);
    Serial.print("\t");
    Serial.print(t);
    Serial.print("\t");
    Serial.print(tr);
    Serial.print("\t");
    Serial.print(trV);
    Serial.print("\t");
    Serial.print(trD);
    Serial.print("\t");
    Serial.println(received);
    a = true;
  }

  t1 = millis() - 5000;
  Serial1.write(rpm);





}
