#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);

void setup() {
  lcd.begin(20,4);
  Serial.begin(9600); //Inisialisasi komunikasi serial pada baud rate 9600 bit per sekon
  lcd.setCursor(0,0);
  lcd.print("wireless Serial ");
  lcd.setCursor(0,1);
  lcd.print("communication via 2.4 GHz");
  lcd.setCursor(0,2);
  lcd.print("modem at PNJ.....");
}

void loop() {
  int TEMP_VALUE = Serial.read();
  lcd.setCursor(0,3);
  lcd.print("Temp. in 0C:");
  lcd.setCursor(13,3);
  lcd.print(TEMP_VALUE);
  delay(100);
  Serial.print("TEMP_VAL:");
  Serial.println(TEMP_VALUE);
  delay(100); //Jeda diantara pembacaan kiriman dari Transmitter agar outputnya mudah terbaca.
}
