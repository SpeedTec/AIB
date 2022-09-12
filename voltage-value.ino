int t1;
float voltage;
float lastVoltage;

void setup(){
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop(){
  Serial.println("Etapa 0");
  t1 = 0;
  
  while(voltage <= 0.54 or t1 < 24){
      voltage = analogRead(A0) * (5.00 / 1023);

      if (voltage <= 0.54){
        t1 = 0;
        }
      
      else if (voltage >= (lastVoltage - (lastVoltage / 10)) and voltage <= (lastVoltage + lastVoltage / 10)){
        t1 += 1;
        }
      
      else{
        t1 = 0;
        }
      delay(100);
      lastVoltage = voltage;
  }
   Serial.println("Done!");
  
  if (voltage >= 0.55 and voltage <= 1.65){
    Serial.println("Giraffe");
    
    while(voltage >= 0.5){
      voltage = analogRead(A0) * (5.00 / 1023);
      delay(200);
    }
  }
  
  else if(voltage >= 1.66 and voltage <= 3.34){
    Serial.println("Cow");
    
    while(voltage >= 0.5){
        voltage = analogRead(A0) * (5.00 / 1023);
        delay(200);
    }
  }
  
  else if(voltage >= 3.35 and voltage <= 5){
    Serial.println("Elephant");
    
    while(voltage >= 0.5){
      voltage = analogRead(A0) * (5.00 / 1023);
      delay(200);
    }
  }
}
