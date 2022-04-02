#include "pitches.h"

const int TONE_PIN = 8;

const int melodyCount = 2;

const int melodyLength1 = 14;
const int melodyLength2 = 12;

const int melodyLength[melodyCount] = {melodyLength1, melodyLength2};

const int melody1[melodyLength1] = {
  NOTE_G2, NOTE_G2, NOTE_E2, NOTE_C2, NOTE_A2, NOTE_A2, NOTE_G2,
  NOTE_F2, NOTE_F2, NOTE_E2, NOTE_E2, NOTE_D2, NOTE_G2, NOTE_C2
};

const int melody2[melodyLength2] = {
  NOTE_C3, NOTE_C3, NOTE_C3, NOTE_G2, NOTE_A2, NOTE_A2, NOTE_G2,
  NOTE_E3, NOTE_E3, NOTE_D3, NOTE_D3, NOTE_C3
};

const int noteDurations1[melodyLength1] = {
  4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 2
};

const int noteDurations2[melodyLength2] = {
  4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 2
};

int* noteDurations[melodyCount];
int* melody[melodyCount];

void playMelody(int n) {

  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < melodyLength[n]; thisNote++) {

    int noteDuration = 1300 / noteDurations[n][thisNote];
    tone(TONE_PIN, melody[n][thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.20;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(TONE_PIN);
  }
}

void setup() {
  noteDurations[0] = noteDurations1;
  noteDurations[1] = noteDurations2;
  melody[0] = melody1;
  melody[1] = melody2;

  // put your setup code here, to run once:
  playMelody(1);
  delay(2000);
  playMelody(0);
}

void loop() {
  // put your main code here, to run repeatedly:

}
