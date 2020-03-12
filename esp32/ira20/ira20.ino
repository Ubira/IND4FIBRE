void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(25,INPUT_PULLUP);
  pinMode(2, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  int sensorVal = digitalRead(25);
  Serial.println(sensorVal);

  if (sensorVal  == HIGH){
    digitalWrite(2,LOW);
    
  }else{
    digitalWrite(2,HIGH);
  }
}
