#include <Arduino.h>

#define LED PORTD
#define BUTTON PORTB

#define UP_BUTTON_PRESSED !(PINB & 0x01)
#define DOWN_BUTTON_PRESSED !(PINB & 0x02)
#define ALL_LED_OFF LED=0x00

const uint16_t DELAY = 300;

void mode1() {
  LED=0xFF;
  _delay_ms(DELAY);
  ALL_LED_OFF;
  _delay_ms(DELAY);
}

void mode2() {
  LED = 0x01;
  _delay_ms(DELAY);
  LED = 0x03;
  _delay_ms(DELAY);
  LED = 0x07;
  _delay_ms(DELAY);
  LED = 0x0F;
  _delay_ms(DELAY);
  LED = 0x1F;
  _delay_ms(DELAY);
  LED = 0x3F;
  _delay_ms(DELAY);
  LED = 0x7F;
  _delay_ms(DELAY);
  LED = 0xFF;
  _delay_ms(DELAY);
}

void setup() {
  DDRD = 0xFF;
  DDRB = 0x00;
  LED = 0x00;
  BUTTON = 0x03;
}

void loop() {
  if (UP_BUTTON_PRESSED) {
    mode1();
  } else if (DOWN_BUTTON_PRESSED) {
    mode2();
  } else {
    ALL_LED_OFF;
  }
}