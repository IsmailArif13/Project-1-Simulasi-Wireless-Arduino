const int PIR_SENSOR_PIN = 8;
int PIR_SENSOR_state=0;
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(PIR_SENSOR_PIN, INPUT);
  lcd.setCursor(0,0);
  lcd.print("MOTION DETECTION");
  lcd.setCursor(0,1);
  lcd.print("Ismail's House");
  delay(1000);
}

void loop()
{
  PIR_SENSOR_state = digitalRead(PIR_SENSOR_PIN);
  if(PIR_SENSOR_state== HIGH)
  {
    lcd.clear();
    int PIR_SENSOR_serial_data=10;
    Serial.write(PIR_SENSOR_serial_data);
    lcd.setCursor(0,1);
    lcd.print("MOTION DETECTED");
    delay(50);
    }
    else
    {
      lcd.clear();
      int PIR_SENSOR_serial_data=20;
      Serial.write(PIR_SENSOR_serial_data);
      lcd.setCursor(0,1);
      lcd.print("NO MOTION");
      delay(50);
      }
}
