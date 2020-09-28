int setpoint;
byte actual;
byte preAct;
float e;
float I;
float P;
float D;
int integral = 0;
float Kp = 1.69; //0.003295;
float Ki = 0.1488; //0.069;
float Kd = 0;
float last;
float derivative;
int drive;
void setup() {
  delay(5000);
  Serial1.begin(115200);
  Serial.begin(115200);
}

void loop() {

  setpoint = 80;

  if ( Serial1.available() ) {
    actual = Serial1.read();

    Serial.print(actual);
    Serial.print("\t");
    Serial.print((setpoint));
    Serial.print("\t");
    e = setpoint - actual;
    integral = integral + e;
    P = e * Kp;
    I = integral * Ki;
    D = (last - actual) * Kd;
    drive = (P + I + D);
    drive = constrain(drive, 0, 255);
    
    if( abs(integral) > 880)
    {
      integral = 880;
    }
    
    last = actual;
    byte drive1 = drive;
    Serial.print(e);
    Serial.print("\t");
    Serial.print(integral);
    Serial.print("\t");
    Serial.println(drive);
    Serial1.write(drive1);
    //delay(20);

  }

}



