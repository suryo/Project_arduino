#include <NewPing.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16,2 );

#define TRIGGER_PIN 4
#define ECHO_PIN 2
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
Serial.begin(115200);
  lcd.init();
  lcd.backlight();
}

void loop() {
  int value_sonar = (sonar.ping_cm());
  lcd.setCursor(1,0);
  lcd.print("Value Sonar :");
  lcd.setCursor(4,1);
  lcd.print(value_sonar);
  lcd.setCursor(8,1);
  Serial.print("Ping :");
  Serial.print(value_sonar);
  delay(100);
}
