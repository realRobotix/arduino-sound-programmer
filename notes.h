#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978

typedef struct
{
    char name[5];
    int pitch;
} Note;

extern const Note Notes[] = {
    {"TBD", 0},
    {"B0", 31},
    {"C1", 33},
    {"CS1", 35},
    {"D1", 37},
    {"DS1", 39},
    {"E1", 41},
    {"F1", 44},
    {"FS1", 46},
    {"G1", 49},
    {"GS1", 52},
    {"A1", 55},
    {"AS1", 58},
    {"B1", 62},
    {"C2", 65},
    {"CS2", 69},
    {"D2", 73},
    {"DS2", 78},
    {"E2", 82},
    {"F2", 87},
    {"FS2", 93},
    {"G2", 98},
    {"GS2", 104},
    {"A2", 110},
    {"AS2", 117},
    {"B2", 123},
    {"C3", 131},
    {"CS3", 139},
    {"D3", 147},
    {"DS3", 156},
    {"E3", 165},
    {"F3", 175},
    {"FS3", 185},
    {"G3", 196},
    {"GS3", 208},
    {"A3", 220},
    {"AS3", 233},
    {"B3", 247},
    {"C4", 262},
    {"CS4", 277},
    {"D4", 294},
    {"DS4", 311},
    {"E4", 330},
    {"F4", 349},
    {"FS4", 370},
    {"G4", 392},
    {"GS4", 415},
    {"A4", 440},
    {"AS4", 466},
    {"B4", 494},
    {"C5", 523},
    {"CS5", 554},
    {"D5", 587},
    {"DS5", 622},
    {"E5", 659},
    {"F5", 698},
    {"FS5", 740},
    {"G5", 784},
    {"GS5", 831},
    {"A5", 880},
    {"AS5", 932},
    {"B5", 988},
    {"C6", 1047},
    {"CS6", 1109},
    {"D6", 1175},
    {"DS6", 1245},
    {"E6", 1319},
    {"F6", 1397},
    {"FS6", 1480},
    {"G6", 1568},
    {"GS6", 1661},
    {"A6", 1760},
    {"AS6", 1865},
    {"B6", 1976},
    {"C7", 2093},
    {"CS7", 2217},
    {"D7", 2349},
    {"DS7", 2489},
    {"E7", 2637},
    {"F7", 2794},
    {"FS7", 2960},
    {"G7", 3136},
    {"GS7", 3322},
    {"A7", 3520},
    {"AS7", 3729},
    {"B7", 3951},
    {"C8", 4186},
    {"CS8", 4435},
    {"D8", 4699},
    {"DS8", 4978}};