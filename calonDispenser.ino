#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

int s1 = 4;
int s2 = 5;
int outH = 6;
int outK = 7;
int outM = 8;
//int liquid_level = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode (s1, INPUT);
  pinMode (s2, INPUT);
  pinMode (outM, OUTPUT);
  pinMode (outK, OUTPUT);
  pinMode (outH, OUTPUT);
  
  lcd.begin (16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
  int Liquid_level1 = 1;
  int Liquid_level2 = 0;

  lcd.setBacklight(HIGH);
  lcd.setCursor(0,0);
  lcd.print("STATUS GALON");
  
  
  Liquid_level1 = digitalRead(4);
  Liquid_level2 = digitalRead(5);
  if ((Liquid_level1 == 1) && (Liquid_level2 == 1)){
    digitalWrite (outH, HIGH);
    digitalWrite (outK, LOW);
    digitalWrite (outM, LOW);
    lcd.setCursor(0,1);
    lcd.print("PENUH");
    delay(1000);
    lcd.setBacklight(HIGH);
    delay(1000);    
  }
  delay(100);
  if ((Liquid_level1 == 0) && (Liquid_level2 == 1)){
    digitalWrite (outH, LOW);
    digitalWrite (outK, HIGH);
    digitalWrite (outM, LOW);
    lcd.setCursor(0,1);
    lcd.print("SEDANG");
    delay(1000);
    lcd.setBacklight(HIGH);
    delay(1000);
  }
  delay(100);
  if ((Liquid_level1 == 0) && (Liquid_level2 == 0)){
    digitalWrite (outH, LOW);
    digitalWrite (outK, LOW);
    digitalWrite (outM, HIGH);
    lcd.setCursor(0,1);
    lcd.print("KOSONG");
    delay(1000);
    lcd.setBacklight(HIGH);
    delay(1000);
  }
  delay(100);
}
