String inputString = "";
boolean stringComplete = false;
int a = 0;
byte x = 0;
byte y;

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
  delay(5000);
}

void loop() {

  serialEvent();
  if (stringComplete)
  {
    x = inputString.toInt();
    inputString = "";
    stringComplete = false;
  }

  if (Serial1.available())
  {
    y = Serial1.read();
    Serial.print(y);
    byte z = x + 10;
    Serial1.write(z);
    Serial.print("\t");
    Serial.println(z);

  }
  a++;
}


void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}





