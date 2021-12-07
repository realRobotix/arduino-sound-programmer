//#include <Wire.h>
//#include <LiquidCrysral_I2C.h>
#include <LiquidCrystal.h>
#include "notes.h"

typedef struct
{
  int pitch;
  char name[5];
} Note;

Note Notes[] = {
    {0, "TBD"},
    {31, "B0"},
    {33, "C1"},
    {35, "CS1"},
    {37, "D1"},
    {39, "DS1"},
    {41, "E1"},
    {44, "F1"},
    {46, "FS1"},
    {49, "G1"},
    {52, "GS1"},
    {55, "A1"},
    {58, "AS1"},
    {62, "B1"},
    {65, "C2"},
    {69, "CS2"},
    {73, "D2"},
    {78, "DS2"},
    {82, "E2"},
    {87, "F2"},
    {93, "FS2"},
    {98, "G2"},
    {104, "GS2"},
    {110, "A2"},
    {117, "AS2"},
    {123, "B2"},
    {131, "C3"},
    {139, "CS3"},
    {147, "D3"},
    {156, "DS3"},
    {165, "E3"},
    {175, "F3"},
    {185, "FS3"},
    {196, "G3"},
    {208, "GS3"},
    {220, "A3"},
    {233, "AS3"},
    {247, "B3"},
    {262, "C4"},
    {277, "CS4"},
    {294, "D4"},
    {311, "DS4"},
    {330, "E4"},
    {349, "F4"},
    {370, "FS4"},
    {392, "G4"},
    {415, "GS4"},
    {440, "A4"},
    {466, "AS4"},
    {494, "B4"},
    {523, "C5"},
    {554, "CS5"},
    {587, "D5"},
    {622, "DS5"},
    {659, "E5"},
    {698, "F5"},
    {740, "FS5"},
    {784, "G5"},
    {831, "GS5"},
    {880, "A5"},
    {932, "AS5"},
    {988, "B5"},
    {1047, "C6"},
    {1109, "CS6"},
    {1175, "D6"},
    {1245, "DS6"},
    {1319, "E6"},
    {1397, "F6"},
    {1480, "FS6"},
    {1568, "G6"},
    {1661, "GS6"},
    {1760, "A6"},
    {1865, "AS6"},
    {1976, "B6"},
    {2093, "C7"},
    {2217, "CS7"},
    {2349, "D7"},
    {2489, "DS7"},
    {2637, "E7"},
    {2794, "F7"},
    {2960, "FS7"},
    {3136, "G7"},
    {3322, "GS7"},
    {3520, "A7"},
    {3729, "AS7"},
    {3951, "B7"},
    {4186, "C8"},
    {4435, "CS8"},
    {4699, "D8"},
    {4978, "DS8"}};

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

//LiquidCrystal_I2C lcd(0x3F, 16, 2);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

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
