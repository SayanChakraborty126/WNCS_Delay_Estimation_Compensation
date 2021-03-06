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
double y4 = 0;
double y5 = 0;
double y2 = 0;
double y3 = 0;
double x;
double x0;
double x1 = 0;
double x2 = 0;
double x3 = 0;
double x4 = 0;
double yh = 0;
double eh;
double trV; //= 0.240;
double t2 = 0;
double t1 = 0;
double t3 = 0;
double trD;
double tr;
double t;
boolean a = false;
int count;
int n;
int A[20];

void setup() {
  delay(10000);
  Serial1.begin(115200);
  Serial.begin(115200);
}

void loop() {

  setpoint = 50;
  tr = 0;
  if (a == true)
  {
    while (Serial1.available() == 0) {}
  }
  
  if ( Serial1.available() ) {
    actual = Serial1.read();
    t2 = millis() - 10000;

    if (actual == 0)
    {
      n++;
      a = true;
      trV = 20 + trV;

    }
    t = t2 - t1;
    if ((a == true) && (count <= n))
    {
      A[count] = t;
      count++;
    }
    for (int i = 0; i < n; i++)
    {
      tr = A[i] + tr;
    }
    if (count > n)
    {
      count = 0;
      A[count] = t;
      count++;
    }
    if (actual != 0)
    {
      trD = t + tr;
      trV = trD;
    }
    
    
    double tr1 = trV / 1000;
    Serial.print(actual);
    Serial.print("\t");
    Serial.print(trV);
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
    drive = constrain(drive, 0, 255);

    if ((integral) > 880)
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
    a = true;
    t1 = millis() - 10000;
    Serial1.write(drive1);

    x0 = drive * (12. / 255.);
    double a = ( 12 - (100 * tr1) );
    double b = ( 12 + (100 * tr1) );
    double c = ( 100 * tr1 * a );
    double d = ( 100 * tr1 * b );
    double e = ( c - 60 );
    double f = ( -120 + d - c );
    double g = ( 60 + d );
    double h = ( 120 + (100 * tr1 * e) );
    double i = ( 360 + (100 * tr1 * f) - (100 * tr1 * e) );
    double j = ( 360 - (100 * tr1 * f) - (100 * tr1 * g) );
    double k = ( 120 + (100 * tr1 * g) );

    a = (1.33876 * (k - h) * x1) / k;
    b = (1.33876 * (j - i) * x2) / k;
    c = (1.33876 * (i - j) * x3) / k;
    d = (1.33876 * (h - k) * x4) / k;
    e =  -((j - (0.914 * k)) * y2) / k;
    f = - ((i - (0.914 * j)) * y3) / k;
    g = - ((h - (0.914 * i)) * y4) / k;
    h =  ((0.914 * h) * y5) / k;

    //yh = ( (1.33876 * (k - h) * x1) + (1.33876 * (j - i) * x2) + (1.33876 * (i - j) * x3) + (1.33876 * (h - k) * x4) - ((j - (0.914 * k)) * y2) - ((i - (0.914 * j)) * y3) - ((h - (0.914 * i)) * y4) + ((0.914 * h) * y5) ) / k;
    
    yh = a + b + c + d + e + f + g + h ; 
    
    x4 = x3;
    x3 = x2;
    x2 = x1;
    x1 = x0;

    y5 = y4;
    y4 = y3;
    y3 = y2;
    y2 = yh;


  }

}



