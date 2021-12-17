#include <Wire.h>
#include <LCD_I2C.h>
//#include <LiquidCrystal.h>
#include "notes.h"

const static int pinUp PROGMEM = 4;
const static int pinLeft PROGMEM = 8;
const static int pinRight PROGMEM = 10;
const static int pinDown PROGMEM = 12;
const static int pinLengthUp PROGMEM = 11;
const static int pinLengthDown PROGMEM = 9;
const static int pinPlay PROGMEM = 6;
const static int pinSpeaker PROGMEM = 2;
const static int melodyLength PROGMEM = 20;
const static int standardNote PROGMEM = 0;
const static int standardLength PROGMEM = 4;
const static int pauseBetweenNotes PROGMEM = 50;
const static int BPM PROGMEM = 130;
const static int debounceTime PROGMEM = 200;

int selNote = 0;

typedef struct
{
  int note;
  int length;
} melody;

melody Melody[melodyLength+1];

byte arrowLeft[8] = {
    B00010,
    B00110,
    B01110,
    B11110,
    B01110,
    B00110,
    B00010,
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

LCD_I2C lcd(0x3F, 16, 2);
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd.begin();
  lcd.backlight();
  Serial.begin(250000);
  Serial.println("heh");
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
  drawLCD();
}
void loop()
{
  if (digitalRead(pinUp) == HIGH)
  {
    Melody[selNote].note++;
    drawLCD();
    delay(debounceTime);
  }
  else if (digitalRead(pinDown) == HIGH)
  {
    Melody[selNote].note--;
    drawLCD();
    delay(debounceTime);
  }
  else if (digitalRead(pinLeft) == HIGH)
  {
    if (selNote > 0)
    {
      selNote--;
      drawLCD();
      delay(debounceTime);
    }
  }
  else if (digitalRead(pinRight) == HIGH)
  {
    if (selNote < melodyLength)
    {
      selNote = selNote + 1;
      drawLCD();
      delay(debounceTime);
    }
  }
  else if (digitalRead(pinLengthUp) == HIGH)
  {
    Melody[selNote].length++;
    drawLCD();
    delay(debounceTime);
  }
  else if (digitalRead(pinLengthDown) == HIGH)
  {
    Melody[selNote].length--;
    drawLCD();
    delay(debounceTime);
  }
  else if (digitalRead(pinPlay) == HIGH)
  {
    playMelody();
    drawLCD();
    delay(debounceTime);
  }
}

void drawLCD()
{
  lcd.noCursor();
  if (selNote != 0)
  {
    lcd.setCursor(0, 0);
    lcd.write(byte(0));
    lcd.setCursor(2, 0);
    lcd.print(Notes[Melody[selNote - 1].note].name);
  }
  else
  {
    lcd.setCursor(0, 0);
    lcd.print(F("     "));
  }
  lcd.setCursor(6, 0);
  lcd.print(Notes[Melody[selNote].note].name);
  if (selNote != melodyLength)
  {
    lcd.setCursor(16, 0);
    lcd.write(byte(1));
    lcd.setCursor(10, 0);
    lcd.print(Notes[Melody[selNote + 1].note].name);
  }
  else
  {
    lcd.setCursor(10, 0);
    lcd.print(F("      "));
  }
  lcd.setCursor(0, 1);
  lcd.print(F("L:"));
  lcd.print(Melody[selNote].length);
  lcd.setCursor(6, 1);
  lcd.print(selNote);
  lcd.print(F("/"));
  lcd.print(melodyLength);
  lcd.setCursor(7, 0);
  lcd.cursor();
}

void playMelody()
{
  for (int i = 0; i < melodyLength; i++)
  {
    selNote = i;
    if (!Melody[selNote].note == 0)
    {
      delay(pauseBetweenNotes);
      tone(pinSpeaker, Notes[Melody[selNote].note].pitch);
      delay(Melody[selNote].length / (BPM / 60) * 1000); // TODO: find right algorithm
    }
  }
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