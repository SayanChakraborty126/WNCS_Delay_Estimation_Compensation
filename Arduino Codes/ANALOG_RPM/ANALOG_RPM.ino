unsigned long tslr = 0;
int interval_one = 100;
int spd = 8;
//unsigned int counter = 0;
float RPM;
int AI=4;
int i;


void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  pinMode(AI, INPUT);
  // put your setup code here, to run once:

}

void loop() 
{
 float pwm = (255./1023.)*1023;
  analogWrite(9,pwm);
  tslr = millis();
  bool barray[250]={0};
  float count=0;
  bool array[2];
  array[0]=0;
  array[1]=1;
 
  while (millis() - tslr < interval_one)
  {
    boolean b= digitalRead(spd);
    //int x=digitalRead(AI);
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
   Serial.println(b);
   /*Serial.print(" ");
   Serial.println(x);*/
   
  
   }
   /*Serial.print("\t");
   Serial.println((count/20)*6000);*/
  /* Serial.print("\t");
   Serial.println((5./1023.)*analogRead(A0));*/
   delay(250);
 Serial.println(" aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa ");
  
}
