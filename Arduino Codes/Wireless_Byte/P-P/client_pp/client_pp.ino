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
float Kd = 0.031;
float last;
float derivative;
int drive;
void setup() {
  delay(5000);
  Serial1.begin(115200);
  Serial.begin(115200);
}

void loop() {

  setpoint = 100;

  if ( Serial1.available() ) {
    actual = Serial1.read();

    Serial.print(actual);
    Serial.print("\t");
    Serial.println((setpoint));
    e = setpoint - actual;
    //e = abs(e);
    drive = map(e, 0, 187.5, 0, 255);
    Serial1.write(drive);

  }

}



