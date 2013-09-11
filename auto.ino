void setup()
{
  Serial.begin(115200);
  analogReference(INTERNAL);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
}

void loop()
{

}

void serialEvent()
{
  while (Serial.available() > 0)
  {
    char state;
    char device[1];
    int dev;
    
    delay(10);
    state = Serial.read();
    delay(10);
    device[0] = Serial.read();
    dev = atoi(device)+1;
    
    switch (state)
    {
    case 'a':
      digitalWrite(dev, LOW);
      break;
    case 'b':
      digitalWrite(dev, HIGH);
      break;    
    case 'c':
      if (digitalRead(dev) == LOW)
        digitalWrite(dev, HIGH);
      else
        digitalWrite(dev, LOW);
      break;
    case 'r':
      printTempRaw();
      break;
    case 'd':
      printDeviceState();
      break;
    case 'e':
      printDeviceState();
      Serial.print("*");
      printTempRaw();
      break;
    }
  }
}

void printTempRaw()
{  
  Serial.print(analogRead(0));
  Serial.print("|");
  Serial.print(analogRead(1));
  Serial.print("|");
  Serial.print(analogRead(2));
}

void printDeviceState()
{
  Serial.print(digitalRead(2));
  Serial.print("|");
  Serial.print(digitalRead(3));
  Serial.print("|");
  Serial.print(digitalRead(4));
  Serial.print("|");
  Serial.print(digitalRead(5));
  Serial.print("|");
  Serial.print(digitalRead(6));
}

//void printTemp()
//{
//  float ra;
//  float rb;
//  float rc;
//  
//  ra = analogRead(0) / 10; //LM35
//  rb = analogRead(1); //LM35
//  rc = analogRead(2) / 10; //LM35
//    
//  Serial.print(ra);
//  Serial.print("|");
//  Serial.print(rb);
//  Serial.print("|");
//  Serial.print(rc);
//}

//int incomingSerialNumber()
//{
//  char num[5];
//  int index = 0;
//  delay(10);
//  while(Serial.available() > 0)
//  {
//    delay(10);
//    num[index++] = Serial.read();
//    if(index > 3)
//      break;
//  }
//  num[index]=0;
//  return atoi(num);
//}
