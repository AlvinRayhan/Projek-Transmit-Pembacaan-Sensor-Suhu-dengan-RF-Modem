#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
int TEMP_SENSOR = A0;

void setup() {
  lcd.begin(20,4);
  Serial.begin(9600); //Inisialisasi komunikasi serial pada baud rate 9600 bit per sekon
  lcd.setCursor(0,0);
  lcd.print("Wireless Serial ");
  lcd.setCursor(0,1);
  lcd.print("communication via 2.4 GHz");
  lcd.setCursor(0,2);
  lcd.print("modem at PNJ.....");
}

void loop() {
  int TEMP_SENSOR_ADC_VALUE = analogRead(TEMP_SENSOR);  
  int TEMP_VAL = (TEMP_SENSOR_ADC_VALUE*500)/1023; //Maksimal resolusi ADC adalah 1023 langkah, resolusi sensor adalah 10 mV / derajat celcius, maka dikalikan dengan 500 (0,01)
  lcd.setCursor(0,3);
  lcd.print("Temp. in 0C:");
  lcd.setCursor(13,3);
  lcd.print(TEMP_VAL);
  Serial.write(TEMP_VAL);
  delay(100);
}
