//Example By ArduinoAll
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>
#define ONE_WIRE_BUS 15 //กำหนดว่าขาของเซนเซอร์ ต่อกับขา 15
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

int lcdColumns = 16;
int lcdRows = 2;


LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

void setup() {
  
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
  sensors.begin();
  lcd.init();                    
  lcd.backlight();
  
}

void blink(float cc){
  if(cc<27){
    digitalWrite(LED_BUILTIN, HIGH); 
    delay(1000); 
    digitalWrite(LED_BUILTIN, LOW);  
  }else{
    digitalWrite(LED_BUILTIN, LOW);    
  }
}

void loop() {

  lcd.setCursor(0, 0);
  lcd.print("TEHN JAD");
  
  sensors.requestTemperatures(); 
  String c = String(sensors.getTempCByIndex(0));
  Serial.println(c + " C,M01");

  float cc = c.toFloat();
  if(cc>=27){
     digitalWrite(4, HIGH); 
     delay(250);
     digitalWrite(4, LOW);
  }else{
     digitalWrite(4, LOW); 
  }
  
  lcd.setCursor(0, 1);
  lcd.print(c + " C");   
  blink(cc);
           
      
}
