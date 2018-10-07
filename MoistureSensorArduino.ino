int analogInput = 0;
int maxValue = 600;
int ledGreen = 2;
int ledYellow = 3;
int ledRed = 4;
void setup() {
  Serial.begin(9600);
  pinMode(ledGreen,OUTPUT);
  pinMode(ledYellow,OUTPUT);
  pinMode(ledRed,OUTPUT);
}

void loop() {
  float moistureValue = analogRead(analogInput);
  if (moistureValue > maxValue){
    maxValue = moistureValue;
  }
  Serial.print("\nmoisture Value: ");
  Serial.print(moistureValue);
  Serial.print("\tmax Value: ");
  Serial.print(maxValue);
  
  double moisPercent = (moistureValue/maxValue)*100.0;
  Serial.print("\tProzent: ");
  Serial.print(moisPercent);
  if(moisPercent < 20){
    digitalWrite(ledGreen,LOW);
    digitalWrite(ledYellow,LOW);
    digitalWrite(ledRed,HIGH);
  } 
  else if (moisPercent >=20 && moisPercent <40){
    digitalWrite(ledGreen,LOW);
    digitalWrite(ledYellow,HIGH);
    digitalWrite(ledRed,LOW);
  }
  else{
    digitalWrite(ledGreen,HIGH);
    digitalWrite(ledYellow,LOW);
    digitalWrite(ledRed,LOW);
  }
  delay(600000);
}
