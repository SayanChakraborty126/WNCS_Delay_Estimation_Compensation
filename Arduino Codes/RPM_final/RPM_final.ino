unsigned long tslr = 0;
int interval_one = 10;
int spd = 8;
int low = 7;
//int pwm=9;
//unsigned int counter = 0;
float RPM;

int i;


void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  // put your setup code here, to run once:

}

void loop()
{
  //digitalWrite(7, LOW);
  float pwm = 150;//(255. / 1023.) * analogRead(A0);
  //Serial.println(pwm);
  analogWrite(9, pwm);
  tslr = millis();
  int count = 0;
  while ( millis() - tslr < 20)
  {
    if (digitalRead(spd) == HIGH)
    {
      count ++;
      while (digitalRead(spd) == HIGH);
    }
  }

  //Serial.print("\t");

  Serial.println((count * 2.5));
  //Serial.print("\t");
  //Serial.println((5./1023.)*analogRead(A0));
  //delay(250);
  // Serial.println(" aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa ");


}
