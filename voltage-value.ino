int t1;
float voltage;
float lastVoltage;

void setup(){
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop(){
  t1 = 0;
  Serial.println("Waiting and checking...");
  
  //calib-logic.py, but converted in c++ logic and with the potentiometer input;
  while(voltage <= 0.54 or t1 < 15){ //t1 * 100 is the time in milleseconds to confirm the calibration;
    voltage = analogRead(A0) * (5.00 / 1023);
    
    if (voltage >= 0.54 and voltage >= (lastVoltage - (lastVoltage / 10)) and voltage <= (lastVoltage + lastVoltage / 10)){
      t1 += 1;
    }
    else{
      t1 = 0;
    }

    delay(100);
    lastVoltage = voltage;
  }

  Serial.println("Done!");
  Serial.print("Animal: ");
  
  if (voltage >= 0.55 and voltage <= 1.65){
    Serial.println("Giraffe");
    while(voltage >= 0.5){
      voltage = analogRead(A0) * (5.00 / 1023);
    }
  }
  
  else if(voltage >= 1.66 and voltage <= 3.34){
    Serial.println("Cow");
    while(voltage >= 0.5){
        voltage = analogRead(A0) * (5.00 / 1023);
    }
  }
  
  else if(voltage >= 3.35 and voltage <= 5){
    Serial.println("Elephant");
    while(voltage >= 0.5){
      voltage = analogRead(A0) * (5.00 / 1023);
    }
  }
}
