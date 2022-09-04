// We were having problems to create these variables inside the setup
int sensorValue;
float voltage;
float lastVoltage;

void setup(){
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void vl(){
  sensorValue = analogRead(A0);
  voltage = sensorValue * (5.00 / 1023);
}

void loop(){
  //giraffe = (voltage >= 0.55 and voltage <= 1.65);
  //cow = (voltage >= 1.66 and voltage <= 3.34);
  //elephant = (voltage >= 3.35 and voltage <= 5);

  // Analog input is being made with a potentiometer for now.
  // The idea is to use a weight tracking scale that works in the same way.
  vl();

  if (voltage >= 0.55 and voltage <= 1.65){
    Serial.println("Giraffe");
    while(voltage >= 0.55 and voltage <= 1.65){
      vl();
    }
  }
  else if(voltage >= 1.66 and voltage <= 3.34){
    Serial.println("Cow");
    lastVoltage = voltage;
    while(voltage >= 1.66 and voltage <= 3.34){
       vl();
    }
  }
  else if(voltage >= 3.35 and voltage <= 5){
    Serial.println("Elephant");
    lastVoltage = voltage;
    while(voltage >= 3.35 and voltage <= 5){
      vl();
    }
  }
  else {}
}
