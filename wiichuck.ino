/*
 Name:		wiichuck.ino
 Created:	2019/03/27 14:51:01
 Author:	53177a
*/

#include <Arduino.h>
#include <Wire.h>
#include "ArduinoNunchuk.h"

byte accx, accy, accz, zbut, cbut;
int ledPin = 13;

ArduinoNunchuk nunchuk = ArduinoNunchuk();

void setup() {
	Serial.begin(9600);
	nunchuk.init();

	pinMode(ledPin, OUTPUT);
}

void loop() {
	nunchuk.update();

		accx = nunchuk.accelX; // ranges from approx 70 - 182
		accy = nunchuk.accelY; // ranges from approx 65 - 173
		accz = nunchuk.accelZ;
		zbut = nunchuk.zButton;
		cbut = nunchuk.cButton;

		/*Serial.print("accx: ");*/	  Serial.print(" "); Serial.print((byte)accx, DEC);
		/*Serial.print(" accy: ");*/ Serial.print(" "); Serial.print((byte)accy, DEC);
		/*Serial.print(" accz: ");*/ Serial.print(" "); Serial.print((byte)accz, DEC);
		/*Serial.print(" zbut: ");*/ Serial.print(" "); Serial.print((byte)zbut, DEC);
		/*Serial.print(" cbut: ");*/ Serial.print(" "); Serial.println((byte)cbut, DEC);

		if (zbut == 1 || cbut == 1) digitalWrite(ledPin, HIGH);
		else digitalWrite(ledPin, LOW);

	delay(50);
}
