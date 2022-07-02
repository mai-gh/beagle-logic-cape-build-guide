/*
                                      +-----+
         +----[PWR]-------------------| USB |--+
         |                            +-----+  |
         |         GND/RST2  [ ][ ]            |
         |       MOSI2/SCK2  [ ][ ]  A5/SCL[ ] |   C5
         |          5V/MISO2 [ ][ ]  A4/SDA[ ] |   C4
         |                             AREF[ ] |
         |                              GND[ ] |
         | [ ]N/C                    SCK/13[ ] |   B5
         | [ ]IOREF                 MISO/12[ ] |   .
         | [ ]RST                   MOSI/11[ ]~|   .
         | [ ]3V3    +---+               10[ ]~|   .
         | [ ]5v    -| A |-               9[ ]~|   .
         | [ ]GND   -| R |-               8[ ] |   B0
         | [ ]GND   -| D |-                    |
         | [ ]Vin   -| U |-               7[ ] |   D7
         |          -| I |-               6[ ]~|   .
         | [ ]A0    -| N |-               5[ ]~|   .
         | [ ]A1    -| O |-               4[ ] |   .
         | [ ]A2     +---+           INT1/3[ ]~|   .
         | [ ]A3                     INT0/2[ ] |   .
         | [ ]A4/SDA  RST SCK MISO     TX>1[ ] |   .
         | [ ]A5/SCL  [ ] [ ] [ ]      RX<0[ ] |   D0
         |            [ ] [ ] [ ]              |
         |  UNO_R3    GND MOSI 5V  ____________/
          \_______________________/
*/



#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

volatile unsigned char count __attribute__((section(".noinit"))); // Not cleared on RESET

void set_pin_high(volatile uint8_t *PORT, uint8_t PIN) { *PORT |= (1 << PIN); }
void set_pin_low(volatile uint8_t *PORT, uint8_t PIN) { *PORT &= ~(1 << PIN); }

void set_all_output() {
  DDRD |= (1 << PD0); // CH01
  DDRD |= (1 << PD1); // CH02
  DDRD |= (1 << PD2); // CH03
  DDRD |= (1 << PD3); // CH04
  DDRD |= (1 << PD4); // CH05
  DDRD |= (1 << PD5); // CH06
  DDRD |= (1 << PD6); // CH07
  DDRD |= (1 << PD7); // CH08
  DDRB |= (1 << PB0); // CH09
  DDRB |= (1 << PB1); // CH10
  DDRB |= (1 << PB2); // CH11
  DDRB |= (1 << PB3); // CH12
}


void set_all_low() {
  PORTD &= ~(1 << PD0);
  PORTD &= ~(1 << PD1);
  PORTD &= ~(1 << PD2);
  PORTD &= ~(1 << PD3);
  PORTD &= ~(1 << PD4);
  PORTD &= ~(1 << PD5);
  PORTD &= ~(1 << PD6);
  PORTD &= ~(1 << PD7);
  PORTB &= ~(1 << PB0);
  PORTB &= ~(1 << PB1);
  PORTB &= ~(1 << PB2);
  PORTB &= ~(1 << PB3);
}





void main()
{

  set_all_output();
  set_all_low();

  MCUSR=0;
  DDRB |= (1 << PB5); // LED output

  if (count >= 13) {
    count = 0;
  }

  switch (count) {
    case 1:
      set_pin_high(&PORTD, PD0);
      break;
    case 2:
      set_pin_high(&PORTD, PD1);
      break;
    case 3:
      set_pin_high(&PORTD, PD2);
      break;
    case 4:
      set_pin_high(&PORTD, PD3);
      break;
    case 5:
      set_pin_high(&PORTD, PD4);
      break;
    case 6:
      set_pin_high(&PORTD, PD5);
      break;
    case 7:
      set_pin_high(&PORTD, PD6);
      break;
    case 8:
      set_pin_high(&PORTD, PD7);
      break;
    case 9:
      set_pin_high(&PORTB, PB0);
      break;
    case 10:
      set_pin_high(&PORTB, PB1);
      break;
    case 11:
      set_pin_high(&PORTB, PB2);
      break;
    case 12:
      set_pin_high(&PORTB, PB3);
      break;

  }
  count++;
  while (1) {}

}
