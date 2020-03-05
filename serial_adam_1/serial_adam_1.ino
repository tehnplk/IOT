/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(4800);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  Serial.println("DoctorID:   00000 ");  
  Serial.println("");
  delay(100);
  Serial.println("PatientID:  0000000000");
  Serial.println("");
  delay(100);
  float w = random(40.0,100.0);
  Serial.println("Weight:         "+String(w)+" Kg");
  Serial.println("");
  delay(100);
  float h = random(145,180);  
  Serial.println("Height:           "+String((int)h)+" cm");
  Serial.println("");
  delay(100);
  float a = (h/100)*(h/100);
  float b = w/a;
  Serial.println("BMI:             "+String(b));
  Serial.println("");
  delay(100);
  Serial.println("D&T:  24/12/2019 15:07");
  Serial.println("");
  Serial.println("");
  delay(2000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(5000);                       // wait for a second
}
