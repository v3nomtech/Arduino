/*
For assistance contact antongeorgiev313@gmail.com
README @ github.com/TraxData313/AirsoftBomb
*/

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);  // the I2C LCD address of your display might differ, in this case,
// replace this line: LiquidCrystal_I2C lcd(0x3F,20,4)
// with this:         LiquidCrystal_I2C lcd(I2C_adrs_of_your_display,20,4)
// to find it, first upload and run the I2C_scanner.txt code to your arduino - it will show you the I2C_adrs_of_your_display



// DECLARATION:
  // Power for LCD
  int LCD_power = 8;
  // beep/light
  int signal_pin = 10;
  int main_state = 0;
  const int button_1 = 2;
  boolean button_1_state = 0;
  const int button_2 = 3;
  boolean button_2_state = 0;
  int timer = 1;
  int timer_sec;
  float timer_fast;
  float timer_faster;
  int timer_sec_remainder;
  int timer_min;
  int SEQ = 300;
  // Bomb wires:
  const int Red_wire = 12;
  boolean R = 0;
  const int Black_wire = 11;
  boolean B = 0;
  const int Green_wire = 7;
  boolean G = 0;
  const int Yellow_wire = 8;
  boolean Y = 0;
  int D_current[] = {R,B,G,Y};
  // Disarm state:
  int D_State = 0;
  int D0[] = {0,0,0,0};
  int D1[] = {0,0,0,0};
  int D2[] = {0,0,0,0};
  int D3[] = {0,0,0,0};


void setup() {
  pinMode(LCD_power, OUTPUT); 
  digitalWrite(LCD_power, HIGH);
  // Signal pin:
  pinMode(signal_pin, OUTPUT); 
  // Buttons:
  pinMode(button_1, INPUT); 
  pinMode(button_2, INPUT); 
  lcd.init();                      // initialize the lcd 
  Serial.begin(9600);              // initialize debug serial
  // Bomb wires:
  pinMode(Red_wire, INPUT_PULLUP);
  pinMode(Black_wire, INPUT_PULLUP); 
  pinMode(Green_wire, INPUT_PULLUP); 
  pinMode(Yellow_wire, INPUT_PULLUP); 
  // INTRO MESSAGE TO LCD:
  
    digitalWrite(signal_pin, 1);
    delay(50);
    digitalWrite(signal_pin, 0);
    delay(50);
    digitalWrite(signal_pin, 1);
    delay(50);
    digitalWrite(signal_pin, 0);
    delay(50);
    
    lcd.backlight();
    lcd.clear();
    
    // INTRO:
    delay(500);
    lcd.setCursor(1,0);
    lcd.print("Armed");
    delay(500);
    lcd.setCursor(1,0);
    lcd.print("Armed by");
    delay(500);
    lcd.setCursor(1,0);
    lcd.print("Armed by ");
    delay(500);
    lcd.setCursor(0,1);
    lcd.print("VENOM");
    delay(1500);
    
    lcd.setCursor(0,1);
    lcd.print("planting bomb");
    delay(500);
    
    lcd.setCursor(0,1);
    lcd.print("planting bomb");
    delay(500);
    
    lcd.setCursor(0,1);
    lcd.print("planting bomb");
    delay(500);
    
    
    lcd.setCursor(0,1);
    lcd.print("planting bomb");
    delay(500);
    
    lcd.setCursor(0,1);
    lcd.print("planting bomb");
    delay(500);
    
    lcd.setCursor(0,1);
    lcd.print("planting bomb");
    delay(2000);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Set timer [min]:");
    lcd.setCursor(0,1);
    lcd.print("timer = ");
    lcd.print(timer);
}


void loop() {
  // STATE 0 - SET THE TIMER:
  if (main_state == 0){
    button_1_state = digitalRead(button_1);
    if (button_1_state == LOW){
      delay(100);
    }
    else if (button_1_state == HIGH){
      timer = timer + 1;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Set timer [min]:");
      lcd.setCursor(0,1);
      lcd.print("timer = ");
      lcd.print(timer);
      delay(150);
    } 
    button_2_state = digitalRead(button_2);
    if (button_2_state == LOW){
      delay(1);
    }
    else if (button_2_state == HIGH){
      //lcd.clear();
      //lcd.setCursor(0,0);
      //lcd.print("Timer set");
      //lcd.setCursor(0,1);
      //lcd.print("Timer[min] = ");
      //lcd.print(timer);
      main_state = 1;
      //delay(1000);
    }
 } // END STATE 0
 
 
 // STATE 1 - SET SNOOSE AND DISARM:
 else if (main_state == 1){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Gnrting key");
    delay(500);
    lcd.setCursor(0,0);
    lcd.print("Gnrting key.");
    delay(500);
    lcd.setCursor(0,0);
    lcd.print("Gnrting key..");
    delay(500);
    lcd.setCursor(0,0);
    lcd.print("Gnrting key...");
    delay(500);
    lcd.setCursor(0,1);
    lcd.print("Done!");
    delay(1000);
    
    // print a random number from 1 to 24, random(1, 25)
    randomSeed(analogRead(0));
    int SEQ = random(1, 25);  
    // SETTING THE SEQ:
    if (SEQ == 1){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("KEY: R,B,G");
      // Set the Disarm steps {R,B,G,Y}:
      //int D0[] = {0,0,0,0}; // Fully armed
      //int D1[] = {1,0,0,0}; // *
      D1[0] = 1;
      //int D2[] = {1,1,0,0}; // **
      D2[0] = 1;
      D2[1] = 1;
      //int D3[] = {1,1,1,0}; // Disarmed
      D3[0] = 1;
      D3[1] = 1;
      D3[2] = 1;
      delay(1000); 
    }
    else if (SEQ == 2){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("KEY: R,B,Y");
      // Set the Disarm steps {R,B,G,Y}:
      //int D0[] = {0,0,0,0}; // Fully armed
      //int D1[] = {1,0,0,0}; // *
      D1[0] = 1;
      //int D2[] = {1,1,0,0}; // **
      D2[0] = 1;
      D2[1] = 1;
      //int D3[] = {1,1,0,1}; // Disarmed
      D3[0] = 1;
      D3[1] = 1;
      D3[3] = 1;
      delay(1000);
    }
    else if (SEQ == 3){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("KEY: R,G,B");
      // Set the Disarm steps {R,B,G,Y}:
      //int D0[] = {0,0,0,0}; // Fully armed
      //int D1[] = {1,0,0,0}; // *
      D1[0] = 1;
      //int D2[] = {1,0,1,0}; // **
      D2[0] = 1;
      D2[2] = 1;
      //int D3[] = {1,1,1,0}; // Disarmed
      D3[0] = 1;
      D3[1] = 1;
      D3[2] = 1;
      delay(1000);
    }
    else if (SEQ == 4){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("KEY: R,G,Y");
      // Set the Disarm steps {R,B,G,Y}:
      //int D0[] = {0,0,0,0}; // Fully armed
      //int D1[] = {1,0,0,0}; // *
      D1[0] = 1;
      //int D2[] = {1,0,1,0}; // **
      D2[0] = 1;
      D2[2] = 1;
      //int D3[] = {1,0,1,1}; // Disarmed
      D3[0] = 1;
      D3[2] = 1;
      D3[3] = 1;
      delay(1000);
    }
    else if (SEQ == 5){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("KEY: R,Y,B");
      // Set the Disarm steps {R,B,G,Y}:
      //int D0[] = {0,0,0,0}; // Fully armed
      //int D1[] = {1,0,0,0}; // *
      D1[0] = 1;
      //int D2[] = {1,0,0,1}; // **
      D2[0] = 1;
      D2[3] = 1;
      //int D3[] = {1,1,0,1}; // Disarmed
      D3[0] = 1;
      D3[1] = 1;
      D3[3] = 1;
      delay(1000);
    }
    else if (SEQ == 6){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("KEY: R,Y,G");
      // Set the Disarm steps {R,B,G,Y}:
      //int D0[] = {0,0,0,0}; // Fully armed
      //int D1[] = {1,0,0,0}; // *
      D1[0] = 1;
      //int D2[] = {1,0,0,1}; // **
      D2[0] = 1;
      D2[3] = 1;
      //int D3[] = {1,0,1,1}; // Disarmed
      D3[0] = 1;
      D3[2] = 1;
      D3[3] = 1;
      delay(1000);
    }
    else if (SEQ == 7){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("KEY: B,R,G");
      // Set the Disarm steps {R,B,G,Y}:
      //int D0[] = {0,0,0,0}; // Fully armed
      //int D1[] = {0,1,0,0}; // *
      D1[1] = 1;
      //int D2[] = {1,1,0,0}; // **
      D2[0] = 1;
      D2[1] = 1;
      //int D3[] = {1,1,1,0}; // Disarmed
      D3[0] = 1;
      D3[1] = 1;
      D3[2] = 1;
      delay(1000);
    }
    else if (SEQ == 8){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("KEY: B,R,Y");
      // Set the Disarm steps {R,B,G,Y}:
      //int D0[] = {0,0,0,0}; // Fully armed
      //int D1[] = {0,1,0,0}; // *
      D1[1] = 1;
      //int D2[] = {1,1,0,0}; // **
      D2[0] = 1; 
      D2[1] = 1;
      //int D3[] = {1,1,0,1}; // Disarmed
      D3[0] = 1;
      D3[1] = 1;
      D3[3] = 1;
      delay(1000);
    }
    else if (SEQ == 9){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("KEY: B,G,R");
      // Set the Disarm steps {R,B,G,Y}:
      //int D0[] = {0,0,0,0}; // Fully armed
      //int D1[] = {0,1,0,0}; // *
      D1[1] = 1;
      //int D2[] = {0,1,1,0}; // **
      D2[1] = 1;
      D2[2] = 1;
      //int D3[] = {1,1,1,0}; // Disarmed
      D3[0] = 1;
      D3[1] = 1;
      D3[2] = 1;
      delay(1000);
    }
    else if (SEQ == 10){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("KEY: B,G,Y");
      // Set the Disarm steps {R,B,G,Y}:
      //int D0[] = {0,0,0,0}; // Fully armed
      //int D1[] = {0,1,0,0}; // *
      D1[1] = 1;
      //int D2[] = {0,1,1,0}; // **
      D2[1] = 1;
      D2[2] = 1;
      //int D3[] = {0,1,1,1}; // Disarmed
      D3[1] = 1;
      D3[2] = 1;
      D3[3] = 1;
      delay(1000);
    }
    else if (SEQ == 11){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("KEY: B,Y,R");
      // Set the Disarm steps {R,B,G,Y}:
      //int D0[] = {0,0,0,0}; // Fully armed
      //int D1[] = {0,1,0,0}; // *
      D1[1] = 1;
      //int D2[] = {0,1,0,1}; // **
      D2[1] = 1;
      D2[3] = 1;
      //int D3[] = {1,1,0,1}; // Disarmed
      D3[0] = 1;
      D3[1] = 1;
      D3[3] = 1;
      delay(1000);
    }
    else if (SEQ == 12){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("KEY: B,Y,G");
      // Set the Disarm steps {R,B,G,Y}:
      //int D0[] = {0,0,0,0}; // Fully armed
      //int D1[] = {0,1,0,0}; // *
      D1[1] = 1;
      //int D2[] = {0,1,0,1}; // **
      D2[1] = 1;
      D2[3] = 1;
      //int D3[] = {0,1,1,1}; // Disarmed
      D3[1] = 1;
      D3[2] = 1;
      D3[3] = 1;
      delay(1000);
    }
    else if (SEQ == 13){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("KEY: G,R,B");
      // Set the Disarm steps {R,B,G,Y}:
      //int D0[] = {0,0,0,0}; // Fully armed
      //int D1[] = {0,0,1,0}; // *
      D1[2] = 1;
      //int D2[] = {1,0,1,0}; // **
      D2[0] = 1;
      D2[2] = 1;
      //int D3[] = {1,1,1,0}; // Disarmed
      D3[0] = 1;
      D3[1] = 1;
      D3[2] = 1;
      delay(1000);
    }
    else if (SEQ == 14){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("KEY: G,R,Y");
      // Set the Disarm steps {R,B,G,Y}:
      //int D0[] = {0,0,0,0}; // Fully armed
      //int D1[] = {0,0,1,0}; // *
      D1[2] = 1;
      //int D2[] = {1,0,1,0}; // **
      D2[0] = 1;
      D2[2] = 1;
      //int D3[] = {1,0,1,1}; // Disarmed
      D3[0] = 1;
      D3[2] = 1;
      D3[3] = 1;
      delay(1000);
    }
    else if (SEQ == 15){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("KEY: G,B,R");
      // Set the Disarm steps {R,B,G,Y}:
      //int D0[] = {0,0,0,0}; // Fully armed
      //int D1[] = {0,0,1,0}; // *
      D1[2] = 1;
      //int D2[] = {0,1,1,0}; // **
      D2[1] = 1;
      D2[2] = 1;
      //int D3[] = {1,1,1,0}; // Disarmed
      D3[0] = 1;
      D3[1] = 1;
      D3[2] = 1;
      delay(1000);
    }
    else if (SEQ == 16){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("KEY: G,B,Y");
      // Set the Disarm steps {R,B,G,Y}:
      //int D0[] = {0,0,0,0}; // Fully armed
      //int D1[] = {0,0,1,0}; // *
      D1[2] = 1;
      //int D2[] = {0,1,1,0}; // **
      D2[1] = 1;
      D2[2] = 1;
      //int D3[] = {0,1,1,1}; // Disarmed
      D3[1] = 1;
      D3[2] = 1;
      D3[3] = 1;
      delay(1000);
    }
    else if (SEQ == 17){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("KEY: G,Y,R");
      // Set the Disarm steps {R,B,G,Y}:
      //int D0[] = {0,0,0,0}; // Fully armed
      //int D1[] = {0,0,1,0}; // *
      D1[2] = 1;
      //int D2[] = {0,0,1,1}; // **
      D2[2] = 1;
      D2[3] = 1;
      //int D3[] = {1,0,1,1}; // Disarmed
      D3[0] = 1;
      D3[2] = 1;
      D3[3] = 1;
      delay(1000);
    }
    else if (SEQ == 18){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("KEY: G,Y,B");
      // Set the Disarm steps {R,B,G,Y}:
      //int D0[] = {0,0,0,0}; // Fully armed
      //int D1[] = {0,0,1,0}; // *
      D1[2] = 1;
      //int D2[] = {0,0,1,1}; // **
      D2[2] = 1;
      D2[3] = 1;
      //int D3[] = {0,1,1,1}; // Disarmed
      D3[1] = 1;
      D3[2] = 1;
      D3[3] = 1;
      delay(1000);
    }
    else if (SEQ == 19){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("KEY: Y,R,B");
      // Set the Disarm steps {R,B,G,Y}:
      //int D0[] = {0,0,0,0}; // Fully armed
      //int D1[] = {0,0,0,1}; // *
      D1[3] = 1;
      //int D2[] = {1,0,0,1}; // **
      D2[0] = 1;
      D2[3] = 1;
      //int D3[] = {1,1,0,1}; // Disarmed
      D3[0] = 1;
      D3[1] = 1;
      D3[3] = 1;
      delay(1000);
    }
    else if (SEQ == 20){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("KEY: Y,R,G");
      // Set the Disarm steps {R,B,G,Y}:
      //int D0[] = {0,0,0,0}; // Fully armed
      //int D1[] = {0,0,0,1}; // *
      D1[3] = 1;
      //int D2[] = {1,0,0,1}; // **
      D2[0] = 1;
      D2[3] = 1;
      //int D3[] = {1,0,1,1}; // Disarmed
      D3[0] = 1;
      D3[2] = 1;
      D3[3] = 1;
      delay(1000);
    }
    else if (SEQ == 21){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("KEY: Y,B,R");
      // Set the Disarm steps {R,B,G,Y}:
      //int D0[] = {0,0,0,0}; // Fully armed
      //int D1[] = {0,0,0,1}; // *
      D1[3] = 1;
      //int D2[] = {0,1,0,1}; // **
      D2[1] = 1;
      D2[3] = 1;
      //int D3[] = {1,1,0,1}; // Disarmed
      D3[0] = 1;
      D3[1] = 1;
      D3[3] = 1;
      delay(1000);
    }
    else if (SEQ == 22){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("KEY: Y,B,G");
      // Set the Disarm steps {R,B,G,Y}:
      //int D0[] = {0,0,0,0}; // Fully armed
      //int D1[] = {0,0,0,1}; // *
      D1[3] = 1;
      //int D2[] = {0,1,0,1}; // **
      D2[1] = 1;
      D2[3] = 1;
      //int D3[] = {0,1,1,1}; // Disarmed
      D3[1] = 1;
      D3[2] = 1;
      D3[3] = 1;
      delay(1000);
    }
    else if (SEQ == 23){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("KEY: Y,G,R");
      // Set the Disarm steps {R,B,G,Y}:
      //int D0[] = {0,0,0,0}; // Fully armed
      //int D1[] = {0,0,0,1}; // *
      D1[3] = 1;
      //int D2[] = {0,0,1,1}; // **
      D2[2] = 1;
      D2[3] = 1;
      //int D3[] = {1,0,1,1}; // Disarmed
      D3[0] = 1;
      D3[2] = 1; 
      D3[3] = 1;
      delay(1000);
    }
    else if (SEQ == 24){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("KEY: Y,G,B");
      // Set the Disarm steps {R,B,G,Y}:
      //int D0[] = {0,0,0,0}; // Fully armed
      //int D1[] = {0,0,0,1}; // *
      D1[3] = 1;
      //int D2[] = {0,0,1,1}; // **
      D2[2] = 1;
      D2[3] = 1;
      //int D3[] = {0,1,1,1}; // Disarmed
      D3[1] = 1;
      D3[2] = 1;
      D3[3] = 1;
      delay(1000);
    }
  // Move to next state:
  main_state = 2;
 } // END STATE 1
 
 
 
 // STATE 2 -:
 else if (main_state == 2){
    // CONFIRM USER WROTE DOWN THE KEY:
    lcd.setCursor(0,1);
    lcd.print("Press B2 to ARM");
    button_2_state = digitalRead(button_2);
    if (button_2_state == LOW){
      delay(100);
    }
    
    else if (button_2_state == HIGH){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("ARMED:");
      lcd.setCursor(7,0);
      //lcd.print(timer_sec);
      timer_min = int(timer_sec/60);
      timer_sec_remainder = timer_sec % 60;
      if (timer_min < 10){ lcd.print("0"); }
      else { Serial.print(" "); }
      lcd.print(timer_min);
      if (timer_sec_remainder < 10){lcd.print(":0");}
      else {lcd.print(":");}
      lcd.print(timer_sec_remainder);
      timer_sec = timer*60;
      timer_fast = timer_sec/6;
      timer_faster = timer_fast/3;
      // Move to next state:
      main_state = 3;
    } 
 
 }
 // END STATE 2
 
 
 
 // STATE 3 -:
 // - run timer
 else if (main_state == 3){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ARMED:");
    lcd.setCursor(7,0);
    //lcd.print(timer_sec);
      timer_min = int(timer_sec/60);
      timer_sec_remainder = timer_sec % 60;
      if (timer_min < 10){ lcd.print("0"); }
      else { Serial.print(" "); }
      lcd.print(timer_min);
      if (timer_sec_remainder < 10){lcd.print(":0");}
      else {lcd.print(":");}
      lcd.print(timer_sec_remainder);
    if (D_State == 0){
      lcd.setCursor(0,1);
      lcd.print("***");
    }
    else if (D_State == 1){
      lcd.setCursor(0,1);
      lcd.print("**");
    }
    else if (D_State == 2){
      lcd.setCursor(0,1);
      lcd.print("*");
    }
      
    
    
    if (timer_sec <= 1){
      main_state = 4;
    }
    else if (timer_sec < timer_faster){
      digitalWrite(signal_pin, 1);
      delay(50);
      timer_sec = timer_sec - 1;
      digitalWrite(signal_pin, 0);
      delay(200);
      digitalWrite(signal_pin, 1);
      delay(50);
      digitalWrite(signal_pin, 0);
      delay(200);
      digitalWrite(signal_pin, 1);
      delay(50);
      digitalWrite(signal_pin, 0);
      delay(200);   
      digitalWrite(signal_pin, 1);
      delay(50);
      digitalWrite(signal_pin, 0);
      delay(200);    
    }
    else if (timer_sec < timer_fast){
      digitalWrite(signal_pin, 1);
      delay(50);
      timer_sec = timer_sec - 1;
      digitalWrite(signal_pin, 0);
      delay(400);
      digitalWrite(signal_pin, 1);
      delay(50);
      digitalWrite(signal_pin, 0);
      delay(400);
    }
    else if (timer_sec > 1){
      digitalWrite(signal_pin, 1);
      delay(50);
      timer_sec = timer_sec - 1;
      digitalWrite(signal_pin, 0);
      delay(950);
    }


  //- check D_current
  check_D_current();
    
  if (D_State == 0){
    if (
      D_current[0] == D0[0] and
      D_current[1] == D0[1] and
      D_current[2] == D0[2] and
      D_current[3] == D0[3]
      ){
        Serial.println(" ");
      }
    else {
        if (
          D_current[0] == D1[0] and
          D_current[1] == D1[1] and
          D_current[2] == D1[2] and
          D_current[3] == D1[3]
          ){
            digitalWrite(signal_pin, 1);
            delay(1000);
            D_State = 1;
            digitalWrite(signal_pin, 0);
            delay(50);
            digitalWrite(signal_pin, 1);
            delay(50);
            digitalWrite(signal_pin, 0);
            delay(50);
            digitalWrite(signal_pin, 1);
            delay(50);
            digitalWrite(signal_pin, 0);
          }
        //----- if D_current != D1 -> BOOM
        else {
        digitalWrite(signal_pin, 1);
        main_state = 4;
        delay(1000);
        digitalWrite(signal_pin, 1);
        }
    }
  } // end D_State == 0
  
  
  
  if (D_State == 1){
    if (
      D_current[0] == D1[0] and
      D_current[1] == D1[1] and
      D_current[2] == D1[2] and
      D_current[3] == D1[3]
      ){
        Serial.println(" ");
      }
    else {
        Serial.println(D2[0]);
        Serial.println(D2[1]);
        Serial.println(D2[2]);
        Serial.println(D2[3]);
        Serial.println(" ");
        if (
          D_current[0] == D2[0] and
          D_current[1] == D2[1] and
          D_current[2] == D2[2] and
          D_current[3] == D2[3]
          ){
            digitalWrite(signal_pin, 1);
            delay(1000);
            D_State = 2;
            digitalWrite(signal_pin, 0);
            delay(50);
            digitalWrite(signal_pin, 1);
            delay(50);
            digitalWrite(signal_pin, 0);
            delay(50);
            digitalWrite(signal_pin, 1);
            delay(50);
            digitalWrite(signal_pin, 0);
          }
        else {
        digitalWrite(signal_pin, 1);
        main_state = 4;
        delay(1000);
        digitalWrite(signal_pin, 1);
        }
    }
  } // end D_State == 1
  
  
  
  if (D_State == 2){
  //--- if D_current == D0 : pass
    if (
      D_current[0] == D2[0] and
      D_current[1] == D2[1] and
      D_current[2] == D2[2] and
      D_current[3] == D2[3]
      ){
        Serial.println(" ");
      }
  //--- else if D_current != D0:
    else {
        //----- else if D_current == D1 -> D_state = 1
        if (
          D_current[0] == D3[0] and
          D_current[1] == D3[1] and
          D_current[2] == D3[2] and
          D_current[3] == D3[3]
          ){
            digitalWrite(signal_pin, 1);
            delay(1000);
            D_State = 3;
            digitalWrite(signal_pin, 0);
            delay(50);
            digitalWrite(signal_pin, 1);
            delay(50);
            digitalWrite(signal_pin, 0);
            delay(50);
            digitalWrite(signal_pin, 1);
            delay(50);
            digitalWrite(signal_pin, 0);
          }
        //----- if D_current != D1 -> BOOM
        else {
        digitalWrite(signal_pin, 1);
        main_state = 4;
        delay(1000);
        digitalWrite(signal_pin, 1);
        }
    }
  } // end D_State == 2
  
  
  
  if (D_State == 3){
    lcd.clear();
    lcd.setCursor(0,0);
      digitalWrite(signal_pin, 1);
      delay(50);
      digitalWrite(signal_pin, 0);
      delay(50);
      digitalWrite(signal_pin, 1);
      delay(50);
      digitalWrite(signal_pin, 0);
      delay(50);
      digitalWrite(signal_pin, 1);
      delay(50);
      digitalWrite(signal_pin, 0);
      delay(50);
    lcd.print("  BOMB DEFUSED");
    delay(1000000);
  } // end D_State == 3
  
  
  
  
 } // END STATE 3
 
 
 
 
 
 
 
 // STATE 4 - BOOM, TERRORISTS WIN:
 else if (main_state == 4){
    lcd.clear();
    lcd.setCursor(0,0);
    digitalWrite(signal_pin, 1);
    lcd.print("  BOMB EXPLODED");
    delay(1000);
    digitalWrite(signal_pin, 0);
    delay(10000);
 } // END STATE 4
 
 
 
} // END LOOP









// Check current bomb wires config:
void check_D_current(){
  R = digitalRead(Red_wire);
  B = digitalRead(Black_wire);
  G = digitalRead(Green_wire);
  Y = digitalRead(Yellow_wire);
  // Print for debug:
  Serial.println("D_current:");
  D_current[0] = R;
  D_current[1] = B;
  D_current[2] = G;
  D_current[3] = Y;
  Serial.println(D_current[0]);
  Serial.println(D_current[1]);
  Serial.println(D_current[2]);
  Serial.println(D_current[3]);
  Serial.println(" ");
}





/* DISAMR SEQUENCE REF:
R,B,G 1
R,B,Y 2
R,G,B 3
R,G,Y 4
R,Y,B 5
R,Y,G 6

B,R,G 7
B,R,Y 8
B,G,R 9
B,G,Y 10
B,Y,R 11
B,Y,G 12

G,R,B 13
G,R,Y 14
G,B,R 15
G,B,Y 16
G,Y,R 17
G,Y,B 18

Y,R,B 19
Y,R,G 20
Y,B,R 21
Y,B,G 22
Y,G,R 23
Y,G,B 24
*/
