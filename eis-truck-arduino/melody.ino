
const int melodyLength = 14;

const int melody[melodyLength] = {
  NOTE_G2, NOTE_G2, NOTE_E2, NOTE_C2, NOTE_A2, NOTE_A2, NOTE_G2,
  NOTE_F2, NOTE_F2, NOTE_E2, NOTE_E2, NOTE_D2, NOTE_A2, NOTE_C2
};

const int noteDurations[melodyLength] = {
  4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 2
};

void playMelody() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < melodyLength; thisNote++) {

    int noteDuration = 1300 / noteDurations[thisNote];
    tone(TONE_PIN, melody[thisNote], noteDuration);

    if (thisNote % 2 == 0)
      headlights(255,0,0);
    else
      headlights(0,0,255);

    int pauseBetweenNotes = noteDuration * 1.20;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(TONE_PIN);
  }
}
