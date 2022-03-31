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
