# EisTruck

Firmware zmrzlinarskeho auta pro pani pruvodci.

## Hardware

mikrokontroler: Arduino Nano 33 IoT

RFID ctecka: MFRC-522 RC522
https://www.laskakit.cz/rfid-ctecka-s-vestavenou-antenou-mfrc-522-rc522/

ePaper displej: Waveshare BW 200x200 1.54""

napajeni: LiPo baterie 1500 mAh 3.7V vc. ochranne elektroniky
https://www.laskakit.cz/baterie-li-po-3-7v-1500mah-lipo/

nabijecka: TP4056
https://www.laskakit.cz/nabijecka-li-ion-clanku-tp4056-s-ochranou-microusb/

bzucak: pasivni 3.3V + aktivni (5V ?)

## UX

Aktualni verze na prilozeni cipu s ovocem nakresli obrazek a zapne svetla v odpovidajici barve, na druhe prilozeni tehoz cipu svetla vypne.

Cip s lodickou prehraje svetelne-akustickou sekvenci.

Pristupny microUSB konektor neni pro arduino, ale jen pro nabijeni -- je to konektor nabijecky. Pro preflashovani arduina je treba otevrit strechu a arduino z patice vytahnout a pripojit k pocitaci.

### Mechanicky caveat

Nutno znamenati, ze:

1) maticky se mi nepodarilo moc dobre vlepit, takze opakovane otvirani mozna bude z tohohle hlediska trochu problem (ale kdo neni liny vytahnout epoxid, tak je tam muze proste zalepit poradne a je to - jen tam doslo k nejakymu nestesti a ty sroubky jsou priserne krive, takze to chce lepit s matickou nasazenou na sroubek...)
(variantnim resenim je to uchyceni strechy nejak prepracovat, pokud by se mela otvirat castejs)

2) rohovy pin u socketu pro arduino (myslim, ze pokud by byl usb nahore, tak by to byl roh vlevo dole - je to Vin pin) se mi podarilo trochu ulomit, takze tam ten kontakt je trochu fraglich - je dobry se po vyjmuti presvedcit, ze neni spodni kovova cast kontaktu nejak ohnuta a ze kontakt bude i nadale kontaktovat.

## Knihovny

```
GxEPD2 (1.4.5)
Adafruit_GFX_Library (1.5.3)
Adafruit_NeoPixel (1.2.3)
RFID_MFRC522v2 (2.0.3)
```