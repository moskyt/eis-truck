void playMelody(int n) {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < melodyLength[n]; thisNote++) {

    int noteDuration = 1300 / noteDurations[n][thisNote];
    tone(TONE_PIN, melody[n][thisNote], noteDuration);
    
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

void setupMelodyPointers() {
  noteDurations[0] = noteDurations1;
  noteDurations[1] = noteDurations2;
  melody[0] = melody1;
  melody[1] = melody2;
}
