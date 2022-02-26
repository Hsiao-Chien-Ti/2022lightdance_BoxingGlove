#include <FastLED.h>

// How many leds in your strip?
#define ARM_NUM 80
#define HAND_NUM 60
#define BACK_NUM 22
#define FINGER_NUM 50

// For led chips like WS2812, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define ARM_PIN 3
#define HAND_PIN 2
#define BACK_PIN 4
#define FINGER_PIN 5
//#define CLOCK_PIN 13

// Define the array of leds
CRGB arm_leds[ARM_NUM];
CRGB hand_leds[HAND_NUM];
CRGB back_leds[BACK_NUM];
CRGB finger_leds[FINGER_NUM];

CRGB cyan=CRGB(144,0,255);
CRGB yellow=CRGB(215,255,0);

void setup() { 
    FastLED.addLeds<WS2812, ARM_PIN>(arm_leds, ARM_NUM);  // GRB ordering is typical
    FastLED.addLeds<WS2812, HAND_PIN>(hand_leds, HAND_NUM);  // GRB ordering is typical
    FastLED.addLeds<WS2812, BACK_PIN>(back_leds, BACK_NUM);
    FastLED.addLeds<WS2812, FINGER_PIN>(finger_leds, FINGER_NUM);
}

void loop() { 
  // energy();
  back_up();
  // arm_side();
  // energy();
  // finger_two();
  // finger_five();
  off();  
  // stable();
}

void energy()
{
  for(int i=19;i<=23;i++)
  {
      arm_leds[i-1] = cyan;
      FastLED.show();
  }
  arm_leds[28]=cyan;
  arm_leds[29]=cyan;
  delay(500);
  for(int i=24;i<=29;i++)
  {
    arm_leds[i-1]=cyan;
    FastLED.show();
    delay(150);
  }

  for(int i=1;i<=3;i++)
  {
    hand_leds[i-1]=cyan;
    FastLED.show();
    delay(150);
  }

  for(int i=4;i<=10;i++)
  {
    hand_leds[i-1]=cyan;
    hand_leds[21-i-1]=cyan;
    FastLED.show();
    delay(150);
  }

  for(int i=30;i<=40;i++)
  {
    arm_leds[i-1]=cyan;
    arm_leds[81-i-1]=cyan;
    FastLED.show();
    delay(50);
  }
  delay(500);
}
void back_up()
{
  for(int i=21;i>=18;i--)
  {
    hand_leds[i-1]=cyan;
    hand_leds[51-i-1]=cyan;
    FastLED.show();
    delay(100);
  }
  for(int i=0;i<=10;i++)
  {
    back_leds[i-1]=cyan;
    back_leds[21-i-1]=cyan;
    FastLED.show();
    delay(100);
  }
}
void finger_two()
{
  for(int i=1;i<=4;i++)
  {
    for(int j=0;j<4;j++)
    {
      finger_leds[i+7*j-1]=yellow;
    }
    FastLED.show();
  }
  for(int i=22;i<=26;i++)
  {
    hand_leds[i-1]=yellow;
  }
  FastLED.show();
  delay(200);
  for(int i=5;i<=7;i++)
  {
    for(int j=0;j<4;j++)
    {
      finger_leds[i+7*j-1]=yellow;
    }
    FastLED.show();
  }
  for(int i=27;i<=29;i++)
  {
    hand_leds[i-1]=yellow;
  }
  FastLED.show();
  delay(500);
  CRGB rainbow[]={CRGB(0,255,0),CRGB(80,255,0),CRGB(215,255,0),CRGB(255,0,0),CRGB(206,135,235),CRGB(144,30,255),CRGB(51,153,225)};
  for(int i=7;i>=1;i--)
  {
    for(int j=0;j<4;j++)
    {
      finger_leds[i+7*j-1]=rainbow[7-i];
    }
    hand_leds[22+i-1]=rainbow[7-i];
    FastLED.show();
    delay(100);
  }
  delay(200);
    for(int i=7;i>=1;i--)
  {
    for(int j=0;j<4;j++)
    {
      finger_leds[i+7*j-1]=yellow;
    }
    hand_leds[22+i-1]=yellow;
    // delay(50);
    FastLED.show();
  }
  delay(500);
}
void off()
{
  for(int i=0;i<ARM_NUM;i++)
  {
    arm_leds[i]=CRGB::Black;
  }
  for(int i=0;i<HAND_NUM;i++)
  {
    hand_leds[i]=CRGB::Black;
  }
  for(int i=0;i<BACK_NUM;i++)
  {
    back_leds[i]=CRGB::Black;
  }
  for(int i=0;i<FINGER_NUM;i++)
  {
    finger_leds[i]=CRGB::Black;
  }
  FastLED.show();
  delay(500);
}

void arm_side()
{
  for(int i=1;i<=5;i++)
  {
    for(int j=1;j<=18;j++)
    {
    arm_leds[j-1]=CRGB::Black;
    arm_leds[51+j-1]=CRGB::Black;
    }
    FastLED.show();
    delay(150);
    for(int j=1;j<=18;j++)
    {
    arm_leds[j-1]=yellow;
    arm_leds[51+j-1]=yellow;
    }
    FastLED.show();
    delay(150);
  }
}
void finger_five()
{
  for(int i=22;i<=29;i++)
  {
    hand_leds[i-1]=yellow;
  }
  FastLED.show();
  delay(300);
  for(int i=22;i<=29;i++)
  {
    hand_leds[i-1]=CRGB::Black;
  }
  FastLED.show();
  for(int i=0;i<=3;i++)
  {
    for(int j=1;j<=7;j++)
    {
      finger_leds[j+i*7-1]=yellow;
    }
    FastLED.show();
    delay(300);
    for(int j=1;j<=7;j++)
    {
      finger_leds[j+i*7-1]=CRGB::Black;
    }
  }
}

void stable()
{
  for(int i=19;i<=23;i++)
  {
    arm_leds[i-1] = cyan;
  }
  arm_leds[28]=cyan;
  arm_leds[29]=cyan;
  for(int i=24;i<=29;i++)
  {
    arm_leds[i-1]=cyan;
  }
  for(int i=1;i<=3;i++)
  {
    hand_leds[i-1]=cyan;
  }
  for(int i=4;i<=10;i++)
  {
    hand_leds[i-1]=cyan;
    hand_leds[21-i-1]=cyan;
  }
  for(int i=30;i<=40;i++)
  {
    arm_leds[i-1]=cyan;
    arm_leds[81-i-1]=cyan;
  }
  for(int j=1;j<=18;j++)
  {
    arm_leds[j-1]=yellow;
    arm_leds[51+j-1]=yellow;
  }
  for(int i=22;i<=29;i++)
  {
    hand_leds[i-1]=yellow;
  }
  for(int i=0;i<=3;i++)
  {
    for(int j=1;j<=7;j++)
    {
      finger_leds[j+i*7-1]=yellow;
    }
  }
  FastLED.show(); 
}