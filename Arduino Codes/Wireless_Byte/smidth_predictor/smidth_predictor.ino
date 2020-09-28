
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

float x1 = 0;
float x2 = 0;
float x3 = 0;
float x4;
float y1 = 0;
float yh = 0;
float eh;
float x;

void setup() {
  delay(5000);
  Serial1.begin(115200);
  Serial.begin(115200);
}

void loop() {

  setpoint = 60;

  if ( Serial1.available() ) {
    actual = Serial1.read();

    Serial.print(actual);
    Serial.print("\t");
    Serial.print((setpoint));
    Serial.print("\t");
    eh = setpoint - actual;
    e = eh - yh;
    P = e * Kp;
    I = integral * Ki;
    D = (last - actual) * Kd;
    drive = (P + I + D);
    integral = integral + e;
    if ((drive) > 255)
    {
      drive = 255;
      integral = 600;//2600;
    }

    if (drive < 0)
    {
      drive = 0;
      //integral = 0;
    }
    last = actual;
    byte drive1 = drive;
    Serial.print(e);
    Serial.print("\t");
    Serial.print(integral);
    Serial.print("\t");
    Serial.println(drive);

    Serial1.write(drive1);

    x = drive * (12. / 255.);
    yh = (0.914 * y1) + (1.339 * x1) - (1.339 * x4);
    y1 = yh;
    x4 = x3;
    x3 = x2;
    x2 = x1;
    x1 = x;




  }

}



