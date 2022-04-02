const int melodyCount = 2;

const int melodyLength1 = 14;
const int melodyLength2 = 12;

const int melodyLength[melodyCount] = {melodyLength1, melodyLength2};

int melody1[melodyLength1] = {
  NOTE_G2, NOTE_G2, NOTE_E2, NOTE_C2, NOTE_A2, NOTE_A2, NOTE_G2,
  NOTE_F2, NOTE_F2, NOTE_E2, NOTE_E2, NOTE_D2, NOTE_G2, NOTE_C2
};

int melody2[melodyLength2] = {
  NOTE_C3, NOTE_C3, NOTE_C3, NOTE_G2, NOTE_A2, NOTE_A2, NOTE_G2,
  NOTE_E3, NOTE_E3, NOTE_D3, NOTE_D3, NOTE_C3
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
