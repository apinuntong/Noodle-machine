/*************** Include Library ***************/
#include <Wire.h>


/*************** Initail variable ***************/
// define pin
// front
#define A1_limit  22     //limit switch 1
#define A2_limit  23     //limit switch 2
#define A3_limit  24     //limit switch 3
#define A4_limit  25     //limit switch 4
#define A5_limit  26     //limit switch 5
#define A6_limit  27     //limit switch 6
// back
#define D1_limit  40     //limit switch 1
#define D2_limit  41     //limit switch 2
#define D3_limit  42     //limit switch 3
#define D4_limit  43     //limit switch 4
#define D5_limit  44     //limit switch 5
#define D6_limit  45     //limit switch 6

//  limit switch noodle
// front
#define B1_limit  28     //limit switch 1
#define B2_limit  29     //limit switch 2
#define B3_limit  30     //limit switch 3
#define B4_limit  31     //limit switch 4
#define B5_limit  32     //limit switch 5
#define B6_limit  33     //limit switch 6
// back
#define C1_limit  34     //limit switch 1
#define C2_limit  35     //limit switch 2
#define C3_limit  36     //limit switch 3
#define C4_limit  37     //limit switch 4
#define C5_limit  38     //limit switch 5
#define C6_limit  39     //limit switch 6

//  limit switch motor press  ย้อนกลับ
#define L_press1  7      //limit switch หน้า
#define L_press2  6      //limit switch หลัง

// motor slide
                          //    ________      //
#define f_motor4  46      //---|         |____// มอเตอร์ดันมาม่าหลัง
#define b_motor4  47      //---|_________|    //
                          //    ________      //
#define b_motor3  48      //---|         |____// มอเตอร์เลือกกมาม่าหลัง
#define f_motor3  49      //---|_________|    //
                          //    ________      //
#define b_motor2  50      //---|         |____// มอเตอร์เลือกกมาม่าหน้า
#define f_motor2  51      //---|_________|    //
                          //    ________      //
#define f_motor1  52      //---|         |____// มอเตอร์ดันมาม่าหน้า
#define b_motor1  53      //---|_________|    //

//ใช้ในการเก็บสถานะระบบ
//////////////////////////////////////////
byte positionA = 1, positionB = 1;      //
byte NowpositionA = 6, NowpositionB = 6;//
byte statePress = 0;                    //
byte stateOKA = 0;                      //
byte stateOKB = 0;                      //
//////////////////////////////////////////


void checkPosit() {
  if (digitalRead(A1_limit) == 1) {
    NowpositionA = 1;
  } else if (digitalRead(A2_limit) == 1) {
    NowpositionA = 2;
  } else if (digitalRead(A3_limit) == 1) {
    NowpositionA = 3;
  } else if (digitalRead(A4_limit) == 1) {
    NowpositionA = 4;
  } else if (digitalRead(A5_limit) == 1) {
    NowpositionA = 5;
  } else if (digitalRead(A6_limit) == 1) {
    NowpositionA = 6;
  }

  if (digitalRead(D1_limit) == 1 && digitalRead(D2_limit) == 0 && digitalRead(D3_limit) == 0 && digitalRead(D4_limit) == 0 && digitalRead(D5_limit) == 0 && digitalRead(D6_limit) == 0) {
    NowpositionB = 1;
  } else if (digitalRead(D1_limit) == 0 && digitalRead(D2_limit) == 1 && digitalRead(D3_limit) == 0 && digitalRead(D4_limit) == 0 && digitalRead(D5_limit) == 0 && digitalRead(D6_limit) == 0) {
    NowpositionB = 2;
  } else if (digitalRead(D1_limit) == 0 && digitalRead(D2_limit) == 0 && digitalRead(D3_limit) == 1 && digitalRead(D4_limit) == 0 && digitalRead(D5_limit) == 0 && digitalRead(D6_limit) == 0) {
    NowpositionB = 3;
  } else if (digitalRead(D1_limit) == 0 && digitalRead(D2_limit) == 0 && digitalRead(D3_limit) == 0 && digitalRead(D4_limit) == 1 && digitalRead(D5_limit) == 0 && digitalRead(D6_limit) == 0) {
    NowpositionB = 4;
  } else if (digitalRead(D1_limit) == 0 && digitalRead(D2_limit) == 0 && digitalRead(D3_limit) == 0 && digitalRead(D4_limit) == 0 && digitalRead(D5_limit) == 1 && digitalRead(D6_limit) == 0) {
    NowpositionB = 5;
  } else if (digitalRead(D1_limit) == 0 && digitalRead(D2_limit) == 0 && digitalRead(D3_limit) == 0 && digitalRead(D4_limit) == 0 && digitalRead(D5_limit) == 0 && digitalRead(D6_limit) == 1) {
    NowpositionB = 6;
  }
}
int lm = 0;
byte nop = 0;
void movePosit(byte posi1, byte posi2) {
  checkPosit();
  checkPosit();
  checkPosit();
  checkPosit();
  checkPosit();
  checkPosit();
  if (posi1 < NowpositionA ) {
    digitalWrite(f_motor2, 1);   //เดินกลับ A>>>
    digitalWrite(b_motor2, 0);
    

  } else if (posi1 > NowpositionA ) {
    digitalWrite(f_motor2, 0);   //เดินกลับ A>>>
    digitalWrite(b_motor2, 1);
    
  } else {
    checkPosit();
    if (nop == 1 && posi1 == NowpositionA&&lm==2) {
      stateOKA = 1;
      nop =0;
       lm = 1;
    }
    digitalWrite(f_motor2, 1);   //เดินกลับ A>>>
    digitalWrite(b_motor2, 1);
  }

  if (posi2 < NowpositionB ) {
    digitalWrite(f_motor3, 1);   //เดินกลับ A>>>
    digitalWrite(b_motor3, 0);
   

  } else if (posi2 > NowpositionB ) {
    digitalWrite(f_motor3, 0);   //เดินกลับ A>>>
    digitalWrite(b_motor3, 1);

  } else {
    checkPosit();
    if (nop == 2 && posi2 == NowpositionB&&lm==2) {
      stateOKB = 1;
      nop = 0;
       lm = 1;
    }
    digitalWrite(f_motor3, 1);   //เดินกลับ A>>>
    digitalWrite(b_motor3, 1);
  }

}

void movePosit2(byte posi1, byte posi2) {
  checkPosit();
  checkPosit();
  checkPosit();
  checkPosit();
  checkPosit();
  checkPosit();
  if (posi1 < NowpositionA ) {
    digitalWrite(f_motor2, 1);   //เดินกลับ A>>>
    digitalWrite(b_motor2, 0);
    

  } else if (posi1 > NowpositionA ) {
    digitalWrite(f_motor2, 0);   //เดินกลับ A>>>
    digitalWrite(b_motor2, 1);
    
  } else {
    
    digitalWrite(f_motor2, 1);   //เดินกลับ A>>>
    digitalWrite(b_motor2, 1);
  }

  if (posi2 < NowpositionB ) {
    digitalWrite(f_motor3, 1);   //เดินกลับ A>>>
    digitalWrite(b_motor3, 0);
   

  } else if (posi2 > NowpositionB ) {
    digitalWrite(f_motor3, 0);   //เดินกลับ A>>>
    digitalWrite(b_motor3, 1);

  } else {
    
    digitalWrite(f_motor3, 1);   //เดินกลับ A>>>
    digitalWrite(b_motor3, 1);
  }

}

void initPosit() {
  Serial.print("set zero");
  while (digitalRead(L_press1) == 1) {    ///หลัง
    digitalWrite(b_motor4, LOW);
    digitalWrite(f_motor4, HIGH);

  }
  digitalWrite(b_motor4, HIGH);
  digitalWrite(f_motor4, HIGH);

  while (digitalRead(L_press2) != 0) {   /// หน้า
    digitalWrite(b_motor1, LOW);
    digitalWrite(f_motor1, HIGH);
  }
  digitalWrite(b_motor1, HIGH);
  digitalWrite(f_motor1, HIGH);
  checkPosit();
  while (NowpositionA > 1) {
    checkPosit();
    digitalWrite(f_motor2, 1);   //เดินกลับ A>>>
    digitalWrite(b_motor2, 0);
  }

  digitalWrite(f_motor2, 1);
  digitalWrite(b_motor2, 1);

  while (NowpositionB > 1) {
    checkPosit();
    digitalWrite(f_motor3, 1);//เดินกลับ B>>>
    digitalWrite(b_motor3, 0);
  }
  checkPosit();
  digitalWrite(f_motor3, 1);
  digitalWrite(b_motor3, 1);
  Serial.println("  done...");
}

void receiveEvent(int howMany) {
  byte data;
  if (Wire.available())
    data = Wire.read();    // receive byte as an integer
 
  Serial.println(data);


      
      if (data == 1) {
         positionA = 1;
         nop = 1;
      }
      else if (data == 2) {
        positionA = 2;
        nop = 1;
      }
      else if (data == 3) {
        positionA = 3;
        nop = 1;
      }
      else if (data == 4) {
        positionA = 4;
        nop = 1;
      }
      else if (data == 5) {
        positionA = 5;
        nop = 1;
      }
      else if (data == 6) {
        positionA = 6;
        nop = 1;
      }
      else if (data == 7) {
         positionB = 1;
         nop = 2;
      }
      else if (data == 8) {
        positionB = 2;
        nop = 2;
      }
      else if (data == 9) {
        positionB = 3;
        nop = 2;
      }
      else if (data == 10) {
        positionB = 4;
        nop = 2;
      }
      else if (data == 11) {
        positionB = 5;
        nop = 2;
      }
      else if (data == 12) {
        positionB = 6;
        nop = 2;
      }else{
        
      }
      lm = 2;
    movePosit(positionA, positionB);
  
}

void setup() {
  Serial.begin(9600);
  Wire.begin(8);
  Wire.onReceive(receiveEvent);

  pinMode(A1_limit, INPUT_PULLUP);
  pinMode(A2_limit, INPUT_PULLUP);
  pinMode(A3_limit, INPUT_PULLUP);
  pinMode(A4_limit, INPUT_PULLUP);
  pinMode(A5_limit, INPUT_PULLUP);
  pinMode(A6_limit, INPUT_PULLUP);

  pinMode(B1_limit, INPUT_PULLUP);
  pinMode(B2_limit, INPUT_PULLUP);
  pinMode(B3_limit, INPUT_PULLUP);
  pinMode(B4_limit, INPUT_PULLUP);
  pinMode(B5_limit, INPUT_PULLUP);
  pinMode(B6_limit, INPUT_PULLUP);

  pinMode(C1_limit, INPUT_PULLUP);
  pinMode(C2_limit, INPUT_PULLUP);
  pinMode(C3_limit, INPUT_PULLUP);
  pinMode(C4_limit, INPUT_PULLUP);
  pinMode(C5_limit, INPUT_PULLUP);
  pinMode(C6_limit, INPUT_PULLUP);

  pinMode(D1_limit, INPUT_PULLUP);
  pinMode(D2_limit, INPUT_PULLUP);
  pinMode(D3_limit, INPUT_PULLUP);
  pinMode(D4_limit, INPUT_PULLUP);
  pinMode(D5_limit, INPUT_PULLUP);
  pinMode(D6_limit, INPUT_PULLUP);

  pinMode(L_press1, INPUT_PULLUP);
  pinMode(L_press2, INPUT_PULLUP);

  pinMode(f_motor1, OUTPUT);
  pinMode(b_motor1, OUTPUT);
  pinMode(f_motor2, OUTPUT);
  pinMode(b_motor2, OUTPUT);
  pinMode(f_motor3, OUTPUT);
  pinMode(b_motor3, OUTPUT);
  pinMode(f_motor4, OUTPUT);
  pinMode(b_motor4, OUTPUT);

  digitalWrite(f_motor1, 1);
  digitalWrite(b_motor1, 1);
  digitalWrite(f_motor2, 1);
  digitalWrite(b_motor2, 1);
  digitalWrite(f_motor3, 1);
  digitalWrite(b_motor3, 1);
  digitalWrite(f_motor4, 1);
  digitalWrite(b_motor4, 1);

  //  digitalWrite(b_motor4, 0);
  //  delay(300);
  //  digitalWrite(b_motor4, 1);

  checkPosit();
  initPosit();

  //  while (NowpositionA > 1) {
  //    checkPosition();
  //    digitalWrite(b_motor2, 0);
  //  } else {
  //    digitalWrite(b_motor2, 1);
  //  }

  Serial.println(" 55 ");
  //  Serial.println(NowpositionB);
  //  delay(2000);
}
unsigned long previousMillis = 0;

void loop() {
  checkPosit();
  if (Serial.available() > 0) {
    char income = Serial.read();
    nop = 1;
    //    //Serial.write(income);
    //    if (income == 'A') {
    //      Serial.write("ok");
    //      digitalWrite(f_motor1, LOW);
    //      delay(12000);
    //      digitalWrite(f_motor1, HIGH);
    //      statePress = 1;
    //    }
    if (income == '1') {
      positionA = 1;
    }
    if (income == '2') {
      positionA = 2;
    }
    if (income == '3') {
      positionA = 3;
    }
    if (income == '4') {
      positionA = 4;
    }
    if (income == '5') {
      positionA = 5;
    }
    if (income == '6') {
      positionA = 6;
    }
    if (income == '7') {
      positionB = 2;
    }
    if (income == '8') {
      positionB = 1;
    }

  }
  if (lm == 2) {
  movePosit(positionA, positionB);
  }
  if (lm == 3) {
  movePosit2(positionA, positionB);
  }
  if (lm == 1) {
    if (stateOKA == 1) {
      digitalWrite(f_motor1, 0);   //ตัวดันหน้า A
      digitalWrite(b_motor1, 1);
      delay(9000);
      digitalWrite(f_motor1, 1);   //ตัวดันหน้า A
      digitalWrite(b_motor1, 1);
      stateOKA = 0;
      statePress = 1;
      delay(1000);
    }
    if (stateOKB == 1) {
      digitalWrite(f_motor4, 0);   //ตัวดันหน้า A
      digitalWrite(b_motor4, 1);
      delay(9000);
      digitalWrite(f_motor4, 1);   //ตัวดันหน้า A
      digitalWrite(b_motor4, 1);
      stateOKB = 0;
      statePress = 2;
      delay(1000);
    }

    if (statePress == 1) {
      Serial.println("state1");
      digitalWrite(b_motor1, 0);
      digitalWrite(f_motor1, 1);
      if (digitalRead(L_press2) == 0) {
        digitalWrite(b_motor1, 1);
        digitalWrite(f_motor1, 1);
        delay(1000);
        positionA = 1;
        statePress = 0;
        lm = 3;
      }
    }
    if (statePress == 2) {
      Serial.println("state2");
      digitalWrite(b_motor4, 0);
      digitalWrite(f_motor4, 1);
      if (digitalRead(L_press1) == 0) {
        digitalWrite(b_motor4, 1);
        digitalWrite(f_motor4, 1);
        delay(1000);
        positionB = 1;
        statePress = 0;
        lm = 3;
      }
    }
  }
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= 1000) {
    previousMillis = currentMillis;
    Serial.print(NowpositionA);
    Serial.print("  ");
    Serial.print(digitalRead(L_press2));  //
    Serial.print("  ");
    Serial.print(digitalRead(L_press1));   //
    Serial.print("  ");
    Serial.println(NowpositionB);

  }

}
