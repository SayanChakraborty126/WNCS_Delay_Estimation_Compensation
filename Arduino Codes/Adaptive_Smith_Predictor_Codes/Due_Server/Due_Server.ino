byte drive1;
unsigned long tslr = 0;
int interval_one = 20;
int spd = 8;
int Dpwm = 9;
byte RPM;
float x;
int i;

void setup() {
  delay(5000);
  Serial.begin(115200);
  Serial1.begin(115200);
  pinMode(spd, INPUT);

  // pinMode(Dpwm, OUTPUT);

}

void loop() {
  if ( Serial1.available() ) {
    drive1 = Serial1.read();
    analogWrite(Dpwm, drive1);
  }

  int count = 0;
  tslr = millis();
  while ( millis() - tslr < 20)
  {
    if (digitalRead(spd) == HIGH)
    {
      count ++;
      while (digitalRead(spd) == HIGH);
    }
  }

  RPM = count * 2.5;
  Serial1.write(RPM);
  Serial.print(RPM);
  Serial.print("\t");
  Serial.println(drive1);

}



