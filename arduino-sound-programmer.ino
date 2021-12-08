#include <LiquidCrystal_I2C.h>
#include <Wire.h>
//#include <LiquidCrystal.h>
#include "notes.h"

const int pinUp = 8;
const int pinLeft = 9;
const int pinRight = 6;
const int pinDown = 7;
const int pinLengthUp = 1;
const int pinLengthDown = 0;
const int pinPlay = 10;
const int melodyLength = 20;
const int standardNote = 1;
const int standardLength = 4;
const int pauseBetweenNotes = 50;

int selNote = 0;

typedef struct
{
  int note;
  int length;
} melody;

melody Melody[melodyLength];

byte arrowLeft[8] = {
    B01000,
    B01100,
    B01110,
    B01111,
    B01110,
    B01100,
    B01000,
    B00000};

byte arrowRight[8] = {
    B01000,
    B01100,
    B01110,
    B01111,
    B01110,
    B01100,
    B01000,
    B00000};

LiquidCrystal_I2C lcd(0x3F, 16, 2);
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  Serial.begin(2000000);
  for (int i = 0; i < melodyLength; i++)
  {
    Melody[i].note = standardNote;
    Melody[i].length = standardLength;
  };
  pinMode(pinUp, INPUT);
  pinMode(pinLeft, INPUT);
  pinMode(pinRight, INPUT);
  pinMode(pinDown, INPUT);
  pinMode(pinLengthUp, INPUT);
  pinMode(pinLengthDown, INPUT);
  pinMode(pinPlay, INPUT);
  lcd.createChar(0, arrowLeft);
  lcd.createChar(1, arrowRight);
  lcd.begin(16, 2);
}
void loop()
{
  while (true)
  {
    switch (getPressedButton())
    {
    case 0:
      delay(100);
      break;

    case 1:
      Melody[selNote].note++;
      drawLCD();
      break;

    case 2:
      Melody[selNote].note--;
      drawLCD();
      break;

    case 3:
      if (selNote > 0)
      {
        selNote--;
      }
      drawLCD();
      break;

    case 4:
      if (selNote < melodyLength)
      {
        selNote++;
      }
      drawLCD();
      break;

    case 5:
      Melody[selNote].length++;
      drawLCD();
      break;

    case 6:
      Melody[selNote].length--;
      drawLCD();
      break;

    case 7:
      drawLCD();
      playMelody();
      break;

    default:
      delay(100);
      break;
    }
    while (getPressedButton() != 0)
    {
      delay(100);
    }
  }
}
void drawLCD()
{
  if (selNote != 0)
  {
    lcd.setCursor(0, 0);
    lcd.write(byte(0));
    lcd.setCursor(2, 0);
    lcd.print(Notes[Melody[selNote - 1].note].name);
  }
  lcd.setCursor(6, 0);
  lcd.print(Notes[Melody[selNote].note].name);
  if (selNote != sizeof(Melody))
  {
    lcd.setCursor(16, 0);
    lcd.write(byte(1));
    lcd.setCursor(10, 0);
    lcd.print(Notes[Melody[selNote + 1].note].name);
  }
  lcd.setCursor(0, 1);
  lcd.print("Length:");
  lcd.print(Melody[selNote].length);
}

void playMelody()
{
  //  for (int i = 0; i < sizeof(melody); i++) {
  //  }
}

int getPressedButton()
{
  if (digitalRead(pinUp) == HIGH)
  {
    return 1;
  }
  else if (digitalRead(pinDown) == HIGH)
  {
    return 2;
  }
  else if (digitalRead(pinLeft) == HIGH)
  {
    return 3;
  }
  else if (digitalRead(pinRight) == HIGH)
  {
    return 4;
  }
  else if (digitalRead(pinLengthUp) == HIGH)
  {
    return 5;
  }
  else if (digitalRead(pinLengthDown) == HIGH)
  {
    return 6;
  }
  else if (digitalRead(pinPlay) == HIGH)
  {
    return 7;
  }
  else
  {
    return 0;
  }
}
