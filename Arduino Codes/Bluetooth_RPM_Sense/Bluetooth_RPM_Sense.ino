
String inputString = "";
boolean stringComplete = false;
unsigned int pwm;
unsigned long tslr = 0;
int interval_one = 1000;
int spd = 8;
//unsigned int counter = 0;
float RPM;

int i;

void setup() {
  Serial.begin(9600);
  inputString.reserve(200);
}

void loop() {
  serialEvent();
  if (stringComplete) {
    inputString = inputString.substring(0, inputString.length()-1);
    pwm = inputString.toInt();
    pwm = map(pwm, 0, 1023, 0, 255);
    analogWrite(9, pwm);
    //Serial.print("Received: ");
   // Serial.print(inputString);
   // Serial.print('#');
        
    inputString = "";
    stringComplete = false;
  }
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
   //Serial.println(b);
   }
   RPM=(count/20)*600;
   Serial.print(RPM);
   Serial.print('#');
   
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if (inChar == '#') {
      stringComplete = true;
    }
  }
}


