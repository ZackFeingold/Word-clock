// Aron Feingold, November 2020

#include <Wire.h>
#include "DS3231.h"
#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(63, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 200 // Time (in milliseconds) to pause between pixels

uint32_t colour;
RTClib RTC;

void setup()
{
  Wire.begin();

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)

  Serial.begin(9600);

  colour = pixels.Color(30, 75, 30);

  test_the_clock();
}

void loop()
{
  pixels.clear(); // Set all pixel colors to 'off'

  DateTime now = RTC.now(); // Get the time

  int current_time_h = now.hour();
  int current_time_m = now.minute();

  // Making colour change at night
  if (current_time_h >= 22 || current_time_h <= 6)
  {
    colour = pixels.Color(125,105,0);
  }
  else
  {
    colour = pixels.Color(30, 75, 30);
  }

  // Convert time to 12 hour clock
  if (current_time_h > 12)
  {
    current_time_h = current_time_h - 12;
  }

  // Round minutes to nearest 5
  int current_time_m_r;
  current_time_m_r = round_five(current_time_m);

  show_time(current_time_h, current_time_m_r);

  delay(20000);
}


void show_time(int current_time_h, int current_time_m_r)
{
  // It Is
  show_LEDs(colour, 61, 62);

  if (current_time_m_r == 0 || current_time_m_r == 60)
  {
    // O'clock
    show_LEDs(colour, 4, 7);
  }
  else if (current_time_m_r == 5 || current_time_m_r == 55)
  {
    // Five
    show_LEDs(colour, 45, 46);

    // Minutes
    show_LEDs(colour, 40, 44);
  }

  else if (current_time_m_r == 10 || current_time_m_r == 50)
  {
    // Ten
    show_LEDs(colour, 56, 57);

    // Minutes
    show_LEDs(colour, 40, 44);
  }

  else if (current_time_m_r == 15 || current_time_m_r == 45)
  {
    // Quarter
    show_LEDs(colour, 47, 51);
  }

  else if (current_time_m_r == 20 || current_time_m_r == 40)
  {
    // Twenty
    show_LEDs(colour, 52, 55);

    // Minutes
    show_LEDs(colour, 40, 44);
  }

  else if (current_time_m_r == 25 || current_time_m_r == 35)
  {
    // Twenty Five
    show_LEDs(colour, 52, 55);
    show_LEDs(colour, 45, 46);

    // Minutes
    show_LEDs(colour, 40, 44);
  }

  else if (current_time_m_r == 30)
  {
    // Half
    show_LEDs(colour, 58, 60);
  }

  // Past and To
  if (current_time_m_r <= 30 && current_time_m_r > 0)
  {
    // Past
    show_LEDs(colour, 32, 33);
  }
  else if (current_time_m_r > 30 && current_time_m_r <= 55)
  {
    // To
    show_LEDs(colour, 39, 39);
  }


  // If more than 30 minutes add 1 to hour
  if (current_time_m_r > 30)
  {
    current_time_h++;
  }

  // 12 to 1 (When quarter to 12)
  if (current_time_m_r > 30 && current_time_h == 13)
  {
    current_time_h = 1;
  }



  // Lighting up the hour

  if (current_time_h == 1)
  {
    // One
    show_LEDs(colour, 30, 31);
  }

  else if (current_time_h == 2)
  {
    // Two
    show_LEDs(colour, 34, 35);
  }

  else if (current_time_h == 3)
  {
    // Three
    show_LEDs(colour, 36, 38);
  }

  else if (current_time_h == 4)
  {
    // Four
    show_LEDs(colour, 27, 29);
  }

  else if (current_time_h == 5)
  {
    // Five
    show_LEDs(colour, 24, 26);
  }

  else if (current_time_h == 6)
  {
    // Six
    show_LEDs(colour, 16, 17);
  }

  else if (current_time_h == 7)
  {
    // Seven
    show_LEDs(colour, 18, 20);
  }

  else if (current_time_h == 8)
  {
    // Eight
    show_LEDs(colour, 21, 23);
  }

  else if (current_time_h == 9)
  {
    // Nine
    show_LEDs(colour, 14, 15);
  }

  else if (current_time_h == 10)
  {
    // Ten
    show_LEDs(colour, 12, 13);
  }

  else if (current_time_h == 11)
  {
    // Eleven
    show_LEDs(colour, 8, 11);
  }

  else if (current_time_h == 12)
  {
    // Twelve
    show_LEDs(colour, 0, 3);
  }

}



int round_five(int n)
{
  return (n / 5 + (n % 5 > 2)) * 5;
}


// It lights up each LED from start to finish in each word
void show_LEDs(uint32_t colour, int start, int finish)
{
  for (int i = start; i <= finish; i++)
  {
    pixels.setPixelColor(i, colour);
  }
  pixels.show();
}


// Testing the Word Clock
void test_the_clock()
{
  // It Is
  show_LEDs(colour, 61, 62);
  delay(DELAYVAL);
  pixels.clear();

  // Half
  show_LEDs(colour, 58, 60);
  delay(DELAYVAL);
  pixels.clear();

  // Ten
  show_LEDs(colour, 56, 57);
  delay(DELAYVAL);
  pixels.clear();

  // Quarter
  show_LEDs(colour, 47, 51);
  delay(DELAYVAL);
  pixels.clear();

  // Twenty
  show_LEDs(colour, 52, 55);
  delay(DELAYVAL);
  pixels.clear();

  // Five
  show_LEDs(colour, 45, 46);
  delay(DELAYVAL);
  pixels.clear();

  // Minutes
  show_LEDs(colour, 40, 44);
  delay(DELAYVAL);
  pixels.clear();

  // To
  show_LEDs(colour, 39, 39);
  delay(DELAYVAL);
  pixels.clear();

  // Past
  show_LEDs(colour, 32, 33);
  delay(DELAYVAL);
  pixels.clear();

  // Two
  show_LEDs(colour, 34, 35);
  delay(DELAYVAL);
  pixels.clear();

  // Three
  show_LEDs(colour, 36, 38);
  delay(DELAYVAL);
  pixels.clear();

  // One
  show_LEDs(colour, 30, 31);
  delay(DELAYVAL);
  pixels.clear();

  // Four
  show_LEDs(colour, 27, 29);
  delay(DELAYVAL);
  pixels.clear();

  // Five
  show_LEDs(colour, 24, 26);
  delay(DELAYVAL);
  pixels.clear();

  // Six
  show_LEDs(colour, 16, 17);
  delay(DELAYVAL);
  pixels.clear();

  // Seven
  show_LEDs(colour, 18, 20);
  delay(DELAYVAL);
  pixels.clear();

  // Eight
  show_LEDs(colour, 21, 23);
  delay(DELAYVAL);
  pixels.clear();

  // Nine
  show_LEDs(colour, 14, 15);
  delay(DELAYVAL);
  pixels.clear();

  // Ten
  show_LEDs(colour, 12, 13);
  delay(DELAYVAL);
  pixels.clear();

  // Eleven
  show_LEDs(colour, 8, 11);
  delay(DELAYVAL);
  pixels.clear();

  // Twelve
  show_LEDs(colour, 0, 3);
  delay(DELAYVAL);
  pixels.clear();

  // O'clock
  show_LEDs(colour, 4, 7);
  delay(DELAYVAL);
  pixels.clear();

}
