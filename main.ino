#include <LiquidCrystal.h>
#define SYS_SLEEP 1000

const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int led = 2; //lampe
int photoResistorValue;

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(led, OUTPUT);
}

void loop()
{
  //digitalWrite(led, HIGH);
  //delay(1000);
  //digitalWrite(pinLed, LOW);
  //delay(1000);

  photoResistorValue = analogRead(A0);
  //Serial.print("Value photo: ");
  //Serial.println(photoResistorValue);


  if (photoResistorValue < 590) {
    delay(SYS_SLEEP);
     Serial.print("{\"lux\":");
  Serial.print(0);
  Serial.print(",\"val\":");
  Serial.print(photoResistorValue);
  Serial.println("}");
    
    digitalWrite(led, LOW);
    lcd.setCursor(0,0);
    lcd.print("Status: Off  ");
    lcd.setCursor(0,1);
    lcd.print("                ");
  } else {
    delay(SYS_SLEEP);
    lcd.clear();
  Serial.print("{\"lux\":");
  Serial.print(1);
  Serial.print(",\"val\":");
  Serial.print(photoResistorValue);
  Serial.println("}");
    digitalWrite(led, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Status: On");

    lcd.setCursor(1,1);
    lcd.print("Eteint dans ");
    lcd.setCursor(13,1);
    lcd.print(SYS_SLEEP/1000);
    lcd.setCursor(15,1);
    lcd.print("s");
  }
}
