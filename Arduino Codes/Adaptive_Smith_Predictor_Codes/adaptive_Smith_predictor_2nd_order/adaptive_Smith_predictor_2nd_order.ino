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
double y4= 0;
double y2 = 0;
double y3 = 0;
double x;
double x0;
double x1 = 0;
double x2 = 0;
double x3 = 0;
double yh = 0;
double eh;
double trV; //= 0.240;

void setup() {
  delay(10000);
  Serial1.begin(115200);
  Serial.begin(115200);
}

void loop() {

  setpoint = 80;

  if ( Serial1.available() ) {
    actual = Serial1.read();
    
    if (actual == 0)
    {
      trV = 20 + trV;
      
    }
    double tr = trV/1000;
    Serial.print(actual);
    Serial.print("\t");
    Serial.print(trV);
    Serial.print("\t");
    Serial.print((setpoint));
    Serial.print("\t");
    eh = setpoint - actual;
    e = eh - yh;
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
    
    x0 = drive * (12. / 255.);
    double a = ( 100* tr );
    double b = ( 24 - (2* a * a) );
    double c = ( 12 + (6*a) + (a*a) );
    double A = ( 12 - (6*a) + (a*a) );
    double B = ( b - (0.914*c) );
    double K = ( A - (0.914*b) );
    
    yh = ((-B*y2) - (K*y3) + (0.914*A*y4) + (2*8.03256*a*x1) - (2*8.03256*a*x3))/c;
    
    x3 = x2;
    x2 = x1;
    x1 = x0;
    
    y4 = y3;
    y3 = y2;
    y2 = yh;
    

  }

}



