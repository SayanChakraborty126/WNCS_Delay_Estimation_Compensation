byte x;
byte y;
boolean a =false;
void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
  delay(5000);
}

void loop() {

  
  if(a == false)
  {
    //x = random(10);
    Serial1.write(100);
  }
  
  if (Serial1.available())
  {

    y = Serial1.read();
    Serial.println(y);
    Serial1.write(y);
    a = true;
    
  }
  
}

