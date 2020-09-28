int setpoint;
byte actual;
byte preAct;
double e;
double I;
double P;
double D;
int integral = 0;
double Kp = 1.69; //0.003295;
double Ki = 0.1488; //0.069;
double Kd = 0.031;
double last;
double derivative;
int drive;
double x1 = 0;
double x2 = 0;
double x3 = 0;
double x4;
double y = 0;
double yh = 0;
double eh;
double x;

void setup() {
  delay(5000);
  Serial1.begin(115200);
  Serial.begin(115200);

}

void loop() {

  setpoint = 50;

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
    drive = constrain(drive , 0 , 255);
    last = actual;
    byte drive1 = drive;
    Serial.print(e);
    Serial.print("\t");
    Serial.print(integral);
    Serial.print("\t");
    Serial.println(drive);

    Serial1.write(drive1);

    x = drive * (12. / 255.);
    yh = (0.914 * y) + (1.339 * x1) - (1.339 * x4);
    y = yh;
    x4 = x3;
    x3 = x2;
    x2 = x1;
    x1 = x;




  }

}



