unsigned long tslr = 0;
int interval_one = 1000;
int spd = 8;
float actual;
int potpin=A0;
int Dpwm=9;
int Dpin=7;
float e;
float I;
float P;
float D;
float integral = 0;
float Kp=0.09334;
float Ki=2.65036;
float Kd=0.0001199;
float last;

int i;


void setup() {
  pinMode(potpin, INPUT);
 pinMode(Dpwm, OUTPUT);
 pinMode(Dpin, OUTPUT);
  Serial.begin(9600);
  Serial.print("RPM\tINPUT");
  Serial.println("RPM\tsetpoint");
  // put your setup code here, to run once:

}

void loop() 
{
 float setpoint=(70./1023.)*analogRead(potpin);
  //c=(255./1023.)*analogRead(potpin);
  
  
  
  tslr = millis();
  bool barray[250]={0};
  float count=0;
  bool array[2];
  array[0]=0;
  array[1]=1;
 
  while (millis() - tslr < interval_one)
  {
    boolean b= digitalRead(spd);
    if(b>0)
    {
      if(b != array[0])
      {
        count= count+1;
        array[0]=1;
        array[1]=0;
      }
    }
    if(b==0)
    {
      array[0]=0;
      array[1]=1;
    }
  }
  
  actual=(count/20)*60;
 e=setpoint-actual;
  integral=integral+e;
  P=e*Kp;
  I=integral*Ki;
  D=(last-actual)*Kd;
  float drive= (P + I+ D)*(255./70.);
  if ((drive)>255) 
  {
           drive=255;
  }
  analogWrite(Dpwm, drive);
  last=actual;
 //Serial.println("RPM\tsetpoint");
  Serial.print(actual);
  Serial.print("\t");
  Serial.println(setpoint);
  //Serial.print(drive);
 // Serial.print("\t");
 // Serial.println(e);
  
  
  
  
}
