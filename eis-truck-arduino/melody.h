const int melodyCount = 2;

const int melodyLength1 = 14;
const int melodyLength2 = 12;

const int melodyLength[melodyCount] = {melodyLength1, melodyLength2};

int melody1[melodyLength1] = {
  NOTE_G4, NOTE_G4, NOTE_E4, NOTE_C4, NOTE_A4, NOTE_A4, NOTE_G4,
  NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_G4, NOTE_C4
};

int melody2[melodyLength2] = {
  NOTE_C5, NOTE_C5, NOTE_C5, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4,
  NOTE_E5, NOTE_E5, NOTE_D5, NOTE_D5, NOTE_C5
};

int noteDurations1[melodyLength1] = {
  4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 2
};

int noteDurations2[melodyLength2] = {
  4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 2
};

int* noteDurations[melodyCount];
int* melody[melodyCount];
