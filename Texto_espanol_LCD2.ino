#include <LCD_ESP.h>


void setup()
 {
  Serial.begin(9600);
  lcd.init();
  lcdIni();
  lcd.backlight();
  lcd.setCursor(0,0);  
  lcdPrint2(F("-----Radio FM"));
  lcd.setCursor(0,1);  
  lcdPrint2(F("Ramón. Señor."));
  lcd.setCursor(0,2);  
  lcdPrint2(F("Tildes y Ñ. Prueba."));
  lcd.setCursor(0,3);  
  lcdPrint2(F("ÉRASE.ÁBALOS.ÍNDALO."));

 }//setup()






void loop() {
 
}
