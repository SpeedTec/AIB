int sensorValue;
float voltage;

void setup(){
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void updateVoltage(){
  sensorValue = analogRead(A0);
  voltage = sensorValue * (5.00 / 1023);
}

void loop(){
  //giraffe = (voltage >= 0.55 and voltage <= 1.65);
  //cow = (voltage >= 1.66 and voltage <= 3.34);
  //elephant = (voltage >= 3.35 and voltage <= 5);

  updateVoltage();

  while(voltage <= 0.54){
      Serial.println("Waiting object...");
      updateVoltage();
      delay(200);
  }
  if (voltage <= 1.65){
    Serial.println("Giraffe");
    while(voltage >= 0.55 and voltage <= 1.65){
      updateVoltage();
      delay(200);
    }
  }
  else if(voltage <= 3.34){
    Serial.println("Cow");
    while(voltage >= 1.66 and voltage <= 3.34){
        updateVoltage();
        delay(200);
    }
  }
  else if(voltage <= 5){
    Serial.println("Elephant");
    while(voltage >= 3.35 and voltage <= 5){
      updateVoltage();
      delay(200);
    }
  }
}
