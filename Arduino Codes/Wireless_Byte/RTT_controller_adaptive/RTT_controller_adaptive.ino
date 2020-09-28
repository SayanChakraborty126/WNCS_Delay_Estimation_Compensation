byte rpm = 100;
unsigned long t;
byte received;
unsigned long t2 = 0;
unsigned long t1 = 0;
unsigned long t3 = 0;
unsigned long trV;
unsigned long trD;
unsigned long tr;
boolean a = false;
int count;
int n;
int A[20];
void setup() {
  delay(10000);
  Serial.begin(115200);
  Serial1.begin(115200);
  //Serial.println("t1""\t""t2""\t""t""\t""trV""\t""trD""\t""received");
}

void loop() {

  tr=0;
  if (a == true)
  {
    while (Serial1.available() == 0) {}
  }


  if (Serial1.available() )
  {
    received = Serial1.read();
    t2 = millis() - 10000;

    
    if (received == 0 && (a == true))
    {
      n++;
      a= true;
      trV=20+trV;
    }
    t = t2 - t1;
    
    if ((a == true) && (count <= n))
    {
      A[count] = t;
      count++;
    } 
    for(int i=0; i<n; i++)
    {
      tr= A[i]+tr;
    }
    if(count>n)
    {
      count = 0;
      A[count]=t;
      count++;
    }
    if(received != 0)
    {
      trD = t + tr;
    }
    Serial.print(t1);
    Serial.print("\t");
    Serial.print(t2);
    Serial.print("\t");
    Serial.print(t);
    Serial.print("\t");
    Serial.print(trV);
    Serial.print("\t");
    Serial.print(trD);
    Serial.print("\t");
    Serial.println(received);
    a = true;
  }

  t1 = millis() - 10000;
  Serial1.write(rpm);





}
  


