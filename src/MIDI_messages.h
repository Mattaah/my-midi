/*
  MIDI_messages.h - Library for MIDI protocol communication output with Arduino
  
  MyMIDI is an Arduino library focused on MIDI output from microcontroller communication
  to other devices, such as computer softwares. This library is destinated to apply some
  abstractions to MIDI concepts that are consistently need to be repeated.

  Author  : Mattah
  Version : 1.0.0
  Created : 14/07/2026
  Modified: 14/07/2026
  License : MIT 
*/

/* First part of status byte */

// channel voice messages
#define STATUS_NOTE_ON       0b10010000
#define STATUS_NOTE_OFF      0b10000000
#define STATUS_NOTE_POLY_KEY 0b10100000
#define STATUS_NOTE_CC       0b10110000
#define STATUS_NOTE_PC       0b11000000
#define STATUS_NOTE_CP       0b11010000
#define STATUS_NOTE_PB       0b11100000

/* Second part of status byte */

// channel voice messages
#define CHANNEL_01 0b0000
#define CHANNEL_02 0b0001
#define CHANNEL_03 0b0010
#define CHANNEL_04 0b0011
#define CHANNEL_05 0b0100
#define CHANNEL_06 0b0101
#define CHANNEL_07 0b0110
#define CHANNEL_08 0b0111
#define CHANNEL_09 0b1000
#define CHANNEL_10 0b1001
#define CHANNEL_11 0b1010
#define CHANNEL_12 0b1011
#define CHANNEL_13 0b1100
#define CHANNEL_14 0b1101
#define CHANNEL_15 0b1110
#define CHANNEL_16 0b1111
