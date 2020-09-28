int RPM1=A0;
int RPM2=8;
//int pin1=8;
//int pin2=7;
void setup()
{
Serial.begin(9600);
pinMode(RPM1, INPUT);
pinMode(RPM2, INPUT);
//pinMode(pin1, OUTPUT);
//pinMode(pin2, OUTPUT);
}

void loop() 
{
  
  //digitalWrite(pin1, HIGH);
  //digitalWrite(pin2, LOW);
//float a=analogRead(RPM1);
//Serial.print(a);
boolean b=digitalRead(RPM2);
Serial.print(" ");
Serial.println(b);
delay(250);
}
