#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeSansBold12pt7b.h>
#include <Adafruit_NeoPixel.h>
#include <MFRC522v2.h>
#include <MFRC522DriverSPI.h>
#include <MFRC522DriverPinSimple.h>
#include <MFRC522Debug.h>

#include "pitches.h"
#include "melody.h"

// list of tags
const unsigned long uids[5] = { 0x653A703, 0x91E12526, 0x7D2BA603, 0xF2CCE61A, 0xE0901B21 };

// pin assignment
const int BEEP_PIN = 19;
const int TONE_PIN = 20;
const int NEO_PIN = 21;

const int RFID_RESET_PIN = 10;
const int RFID_CS_PIN = 9;

const int EPD_CS_PIN = 6;
const int EPD_DC_PIN = 5;
const int EPD_RST_PIN = 4;
const int EPD_BUSY_PIN = 3;

// e-paper display
GxEPD2_BW<GxEPD2_154, 200> display(GxEPD2_154(EPD_CS_PIN, EPD_DC_PIN, EPD_RST_PIN, EPD_BUSY_PIN));
// RFID reader
MFRC522DriverPinSimple ss_pin(RFID_CS_PIN); 
SPIClass &spiClass = SPI; 
const SPISettings spiSettings = SPISettings(SPI_CLOCK_DIV4, MSBFIRST, SPI_MODE0); 
MFRC522DriverSPI driver{ss_pin, spiClass, spiSettings};
MFRC522 mfrc522{driver}; 
// headlights
Adafruit_NeoPixel pixels(2, NEO_PIN, NEO_RGB + NEO_KHZ800);

unsigned short int rr, gg, bb;
bool lights = false;

unsigned long last_uid = 0;
unsigned long last_read = 0;

void setup()
{
  Serial.begin(115200);
  delay(2000);

  Serial.println(F("Init neopixels..."));

  lights = false;
  rr = 255;
  gg = 255;
  bb = 255;
  
  pixels.begin();
  delay(100);
  pixels.clear();
  delay(100);
  pixels.show();

  Serial.println(F("Init beeper..."));

  pinMode(BEEP_PIN, OUTPUT);
  digitalWrite(BEEP_PIN, LOW);

  Serial.println(F("Init EPD..."));

  display.init();
  helloWorld();
  display.hibernate();
 
  Serial.println(F("Init RFID..."));
  pinMode(RFID_RESET_PIN, OUTPUT);
  digitalWrite(RFID_RESET_PIN, LOW);
  delay(500);
  digitalWrite(RFID_RESET_PIN, HIGH);
  delay(500);

  mfrc522.PCD_Init();   
  MFRC522Debug::PCD_DumpVersionToSerial(mfrc522, Serial);

  Serial.println(F("Init done."));

  setupMelodyPointers();
}

void beep() {
  digitalWrite(BEEP_PIN, HIGH);
  delay(100);
  digitalWrite(BEEP_PIN, LOW);
}

void headlights(int r, int g, int b) {
   pixels.setPixelColor(0, pixels.Color(r, g, b));
   pixels.setPixelColor(1, pixels.Color(r, g, b));
   pixels.show();
}

void loop() {
  unsigned long now = millis();
  
  if ( mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial() && (now - last_read > 2000)) {

    last_read = now;
    
    unsigned long uid;
    uid += (long)mfrc522.uid.uidByte[0] << 24;
    uid += (long)mfrc522.uid.uidByte[1] << 16;
    uid += (long)mfrc522.uid.uidByte[2] << 8;
    uid += (long)mfrc522.uid.uidByte[3];
    Serial.println(uid,HEX); 

    int bmap = -1;
    if (uid == uids[0]) { // schiffli
      playMelody(0);
      headlights(150,150,150);
    } else 
    if (uid == uids[4]) { // old mc donalds
      playMelody(1);
      headlights(150,150,150);
    } else 
    if (uid == uids[1]) { // cherry
      beep();
      if (uid == last_uid) {
        lights = !lights;
      } else {
        rr = 255;
        gg = 0;
        bb = 0;
        lights = true;
        bmap = 0;
      }
    } else 
    if (uid == uids[2]) { // lemon
      beep();
      if (uid == last_uid) {
        lights = !lights;
      } else {
        rr = 255;
        gg = 255;
        bb = 0;
        lights = true;
        bmap = 1;
      }
    } else 
    if (uid == uids[3]) { // pear
      beep();
      if (uid == last_uid) {
        lights = !lights;
      } else {
        rr = 0;
        gg = 255;
        bb = 0;
        lights = true;
        bmap = 2;
      }
    } else {
      beep();
      displayUID(uid);
    }
    if (lights) 
      headlights(rr, gg, bb);
     else
      headlights(0, 0, 0);
    if (bmap >= 0)  
      displayBitmap(bmap);
    last_uid = uid;
  }
  
  delay(100); 
}
