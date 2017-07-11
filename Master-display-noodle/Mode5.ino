//////// Mode 5 Warning mode ///////
void mode5() {
  Serial.println("warning mode");

  unsigned long curGet = millis();
  if (curGet - preGet >= 1000) {
    lcd.noBacklight();
    preGet = curGet;
  } else {
    lcd.backlight();
  }

  lcd.setCursor(0, 0);
  lcd.print("     Warning !!!    ");
  lcd.setCursor(0, 1);
  lcd.print("   Out of Sevice    ");
  lcd.setCursor(0, 2);
  lcd.print("     No Water       ");
  lcd.setCursor(0, 3);
  lcd.print("                    ");


  char customKey = keypad.getKey();
  if (customKey == 'D') {
    lcd.backlight();
    lcd.clear();
    noodleState = false;
    tempState = false;
    waterState = false;
    mode = 0;
  }
}



// warning water not flow
//void waterFail() {
//  lcd.backlight();
//  lcd.setCursor(0, 0);
//  lcd.print("     Warning !!!    ");
//  lcd.setCursor(0, 1);
//  lcd.print("   Out of Sevice    ");
//  lcd.setCursor(0, 2);
//  lcd.print("     No Water       ");
//  lcd.setCursor(0, 3);
//  lcd.print("                    ");
//  delay(250);
//  lcd.noBacklight();
//  delay(250);
//}