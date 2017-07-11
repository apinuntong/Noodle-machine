//////// Mode 3 System monitor ///////
void mode3() {
  // print mode are in
  Serial.println("System monitor mode");



  // clear Status for make sure is repair
  noodleState = false;
  tempState = false;
  waterState = false;



  // get data from keypad
  getKeypad();


  // mode 3 display
  lcd.setCursor(0, 0);
  lcd.print("Noodles In Stock :");

  lcd.setCursor(0, 1);
  lcd.print("  ");
  if (fstock1 <= 9)   lcd.print("0");
  lcd.print(fstock1); lcd.print(" ");
  if (fstock2 <= 9)   lcd.print("0");
  lcd.print(fstock2); lcd.print(" ");
  if (fstock3 <= 9)   lcd.print("0");
  lcd.print(fstock3); lcd.print(" ");
  if (fstock4 <= 9)   lcd.print("0");
  lcd.print(fstock4); lcd.print(" ");
  if (fstock5 <= 9)   lcd.print("0");
  lcd.print(fstock5); lcd.print(" ");
  if (fstock6 <= 9)   lcd.print("0");
  lcd.print(fstock6); lcd.print(" ");

  lcd.setCursor(0, 2);
  lcd.print("  ");
  if (bstock1 <= 9)   lcd.print("0");
  lcd.print(bstock1); lcd.print(" ");
  if (bstock2 <= 9)   lcd.print("0");
  lcd.print(bstock2); lcd.print(" ");
  if (bstock3 <= 9)   lcd.print("0");
  lcd.print(bstock3); lcd.print(" ");
  if (bstock4 <= 9)   lcd.print("0");
  lcd.print(bstock4); lcd.print(" ");
  if (bstock5 <= 9)   lcd.print("0");
  lcd.print(bstock5); lcd.print(" ");
  if (bstock6 <= 9)   lcd.print("0");
  lcd.print(bstock6); lcd.print(" ");

  //  lcd.setCursor(0, 3);
  //  lcd.print("* Clear    # Confirm");



  // exit admin mode
  if (inChar == '#') {
    stateAdmin = 0;
    mode = 0;
  }



  // press for clear noodle stock
  if (inChar == '*') {
    stateAdmin += 1;
  }



  // ensure for clear data noodle stock
  if (inChar == '*' && stateAdmin == 2) {
    // Clear noodle in stock
    stock = 10;
    EEPROM.write(f_stock1, stock);
    EEPROM.write(f_stock2, stock);
    EEPROM.write(f_stock3, stock);
    EEPROM.write(f_stock4, stock);
    EEPROM.write(f_stock5, stock);
    EEPROM.write(f_stock6, stock);
    EEPROM.write(b_stock1, stock);
    EEPROM.write(b_stock2, stock);
    EEPROM.write(b_stock3, stock);
    EEPROM.write(b_stock4, stock);
    EEPROM.write(b_stock5, stock);
    EEPROM.write(b_stock6, stock);
    delay(1000);
    stateAdmin = 0;
    mode = 0;
  }

  if (stateAdmin == 1) {
    lcd.setCursor(0, 3);
    lcd.print("Restock? *:Ok #:Back");
  } else {
    lcd.setCursor(0, 3);
    lcd.print("* Clear    # Confirm");
  }

  //  if (inChar == '1') {
  //    mp3_play(1);
  //    delay(500);
  //  } else if (inChar == '2') {
  //    mp3_play(2);
  //    delay(500);
  //  } else if (inChar == '3') {
  //    mp3_play(3);
  //    delay(500);
  //  } else if (inChar == '4') {
  //    mp3_play(4);
  //    delay(500);
  //  } else if (inChar == '5') {
  //    mp3_play(5);
  //    delay(500);
  //  } else if (inChar == '6') {
  //    mp3_play(6);
  //    delay(500);
  //  } else if (inChar == '*') {
  //    mp3_stop();
  //    delay(500);
  //  }
}

