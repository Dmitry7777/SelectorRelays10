#include "SelectorRelays10.h"

// Constructor: initialize relay pin numbers
SelectorRelays10::SelectorRelays10(uint8_t DATA0, uint8_t DATA1, uint8_t DATA2, uint8_t DATA3, 
                                   uint8_t DATA4, uint8_t DATA5, uint8_t DATA6, uint8_t DATA7,
                                   uint8_t DATA8, uint8_t DATA9) {
    _relayPins[0] = DATA0;
    _relayPins[1] = DATA1;
    _relayPins[2] = DATA2;
    _relayPins[3] = DATA3;
    _relayPins[4] = DATA4;
    _relayPins[5] = DATA5;
    _relayPins[6] = DATA6;
    _relayPins[7] = DATA7;
    _relayPins[8] = DATA8;
    _relayPins[9] = DATA9;
}

// Initialize relay pins as outputs
void SelectorRelays10::begin() {
    for (int i = 0; i < 10; i++) {
        pinMode(_relayPins[i], OUTPUT);
        digitalWrite(_relayPins[i], LOW);  // Start with all relays off
    }
}

// Turn on a specific relay (0-9)
void SelectorRelays10::turnOn(uint8_t relay) {
    if (relay < 10) {
        digitalWrite(_relayPins[relay], HIGH);
    }
}

// Turn off a specific relay (0-9)
void SelectorRelays10::turnOff(uint8_t relay) {
    if (relay < 10) {
        digitalWrite(_relayPins[relay], LOW);
    }
}

// Toggle a specific relay (0-9)
void SelectorRelays10::toggle(uint8_t relay) {
    if (relay < 10) {
        digitalWrite(_relayPins[relay], !digitalRead(_relayPins[relay]));
    }
}

// Turn on all relays
void SelectorRelays10::allOn() {
    for (int i = 0; i < 10; i++) {
        digitalWrite(_relayPins[i], HIGH);
    }
}

// Turn off all relays
void SelectorRelays10::allOff() {
    for (int i = 0; i < 10; i++) {
        digitalWrite(_relayPins[i], LOW);
    }
}