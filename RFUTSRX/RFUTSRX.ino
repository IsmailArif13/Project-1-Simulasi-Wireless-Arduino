#include <LiquidCrystal.h>
const int ledPinred = 10;
const int ledPingre = 9;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
  pinMode(ledPinred, OUTPUT);
  pinMode(ledPingre, OUTPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print("MOTION DETECTION");
  lcd.setCursor(0,1);
  lcd.print("Ismail's House");
  delay(1000);
}

void loop()
{
  int PIR_SENSOR_serial_data= Serial.read();;
  if(PIR_SENSOR_serial_data == 10)
  {
    lcd.clear();
    Serial.print("PIRSENSOR:");
    Serial.println(PIR_SENSOR_serial_data);
    lcd.setCursor(0,0);
    lcd.print("BE CAREFUL!");
    digitalWrite(ledPinred, HIGH);
    digitalWrite(ledPinred, LOW);
    lcd.setCursor(0,1);
    lcd.print("MOTION DETECTED");
    delay(50);
    }
    else if(PIR_SENSOR_serial_data == 20)
    {
      lcd.clear();
      Serial.print("PIRSENSOR:");
      Serial.println(PIR_SENSOR_serial_data);
      lcd.setCursor(0,0);
      lcd.print("NO MOTION");
      digitalWrite(ledPingre, HIGH);
      digitalWrite(ledPingre, LOW);
      lcd.setCursor(0,1);
      lcd.print("YOU ARE SAFE :)");
      delay(50);
      }
}
