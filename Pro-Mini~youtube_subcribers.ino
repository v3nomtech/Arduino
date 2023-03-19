#define WINDOWS 1
#include <Keyboard.h>



int platform = WINDOWS;


void setup()
{
  
  pinMode(2, INPUT_PULLUP);
  Keyboard.begin();

 
  delay(500);


}


void loop() {




  switch (platform) {
    case WINDOWS:
   
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('r');
      Keyboard.releaseAll();
      break;
  }
  delay(100);


  Keyboard.print("Chrome");

  delay(100);

  typeKey(KEY_RETURN);
  delay(1000);

  typeKey(KEY_RETURN);
  delay(3000);


  Keyboard.print("https://www.youtube.com/@venomelectronics?sub_confirmation=1");
  delay(500);

  typeKey(KEY_RETURN);

  delay(5000);

  typeKey(KEY_TAB);

  typeKey(KEY_TAB);

  typeKey(KEY_RETURN);

  while (true);
}

void typeKey(int key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}
