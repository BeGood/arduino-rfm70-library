// RFM70 receiver
// by Heye Everts <heye.everts.1@gmail.com>
//
// Demonstrates use of the megaRF library
// Receive bytes from another device and echo
// 
// Refer to the "simple_sender" example for use with this
//
// Created 2 January 2013
// Copyright 2013 Heye Everts

#include <rfm70.h>

// CS, CE, IRQ, CLKDIV
RFM70 rfm70(10, 8, 2, RFM77_DEFAULT_SPI_CLOCK_DIV);

void setup() {
	Serial.begin(19200);
	Serial.println("##reset##");

	rfm70.begin();
	rfm70.onReceive(receiveEvent);
}

void loop() {
	//delay for stability
	delay(1);

	//the tick function checks for any received data and calls the receiveEvent
	rfm70.tick();

}

void receiveEvent(void) {
	Serial.print("Len: ");
	Serial.print(rfm70.getPacketLength());
	Serial.print("\tContent: ");
	Serial.println((char*) rfm70.getRcvBuffer());
}

