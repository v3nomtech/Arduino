#include <TM1637Display.h>

#define CLK 10
#define DIO 11

#define delaytime  500

TM1637Display display(CLK, DIO);

int count=0;
uint8_t a[]  = { 0x1, 0x00, 0x00, 0x00 };
uint8_t b[]  = { 0x2, 0x00, 0x00, 0x00 };
uint8_t c[]  = { 0x4, 0x00, 0x00, 0x00 };
uint8_t d[]  = { 0x8, 0x00, 0x00, 0x00 };
uint8_t e[] = { 0x10, 0x00, 0x00, 0x00 };
uint8_t f[] = { 0x20, 0x00, 0x00, 0x00 };
uint8_t g[] = { 0x40, 0x00, 0x00, 0x00 };
uint8_t h[] = { 0x80, 0x00, 0x00, 0x00 };
int minutetime  =47;
int hourtime  =02;
unsigned long current;
unsigned long old=0;
unsigned int interval;
boolean flag=false;
int settime=5;
int minbutton=4;
int hourbutton =3;
void setup()
{
 Serial.begin(115200);
 pinMode(settime,INPUT_PULLUP);
 pinMode(minbutton,INPUT_PULLUP);
 pinMode(hourbutton,INPUT_PULLUP);
 display.setBrightness(0x0f);  // Set full brightness
 display.clear();
 scrolling();
 scrolling();
 display.clear();
 old=millis();
}

void loop()
{
     current = millis();
     interval=(current-old)/1000;
        
   
     if (digitalRead(settime)==LOW)
     {
      flag =true;
      old=current;
     }
      if (flag)
      setTiming();
      else
        {
           display.showNumberDecEx(hourtime,0b01110000,true,2,0);
           display.showNumberDec(minutetime,true,2,2);
           delay(delaytime);
           display.showNumberDec(hourtime,true,2,0);
           display.showNumberDec(minutetime,true,2,2);
           delay(delaytime);
           current = millis();
           interval=(current/1000)-(old/1000);
           Serial.println ("interval: " + String(interval));
           if(interval>=60)
           checktimeformat();
           
         }
Serial.println("Flag: "+ String(flag)); 

 
}


void checktimeformat()
{
  minutetime++;
  old=current;
  interval=0;
  
if (minutetime==60)
{
  minutetime=0;
  hourtime++;
}
if (hourtime==24)
hourtime=0;
}

void setTiming()
{
  if(interval>5)
 {
  flag=false;
  return;
 }
 display.clear();
 delay(40);
 display.showNumberDecEx(hourtime,0b01110000,true,2,0);
 display.showNumberDec(minutetime,true,2,2);
 delay(100);
  if(digitalRead(minbutton)==LOW)
{
   old=millis();
   minutetime++;
   if (minutetime==60)
     minutetime=0;
   delay(100);
}

  if(digitalRead(hourbutton)==LOW)
{
   old=millis();
   hourtime++;
   if (hourtime==24)
     hourtime=0;
   delay(100);
}
}

void scrolling()
{
  
  for(count=0; count<4; count++)
{
 display.clear();
 display.setSegments(a,1,count);
 delay(100);
}
 display.clear();
 display.setSegments(b,1,3);
 delay(100);

 display.clear();
 display.setSegments(c,1,3);
 delay(100);

  for(count=3; count>=0; count--)
{
 display.clear();
 display.setSegments(d,1,count);
 delay(100);
}

 display.clear();
 display.setSegments(e,1,0);
 delay(100);

 display.clear();
 display.setSegments(f,1,0);
 delay(100);
}
