/*
  MyMIDI.h - Library for MIDI protocol communication output with Arduino
  
  MyMIDI is an Arduino library focused on MIDI output from microcontroller communication
  to other devices, such as computer softwares. This library is destinated to apply some
  abstractions to MIDI concepts that are consistently need to be repeated.

  Author  : Mattah
  Version : 1.0.0
  Created : 14/07/2026
  Modified: 14/07/2026
  License : MIT 
*/

#ifndef MY_MIDI_H
#define MY_MIDI_H

#include "Arduino.h"

class MyMIDI
{
private:
// variables to store status bytes
  byte sb_note_on;
  byte sb_note_off;
  byte sb_poly_key_press;
  byte sb_ctlr_change;
  byte sb_program_change;
// variables to store data bytes
  byte db_note_on_1;
  byte db_note_on_2;
  byte db_note_off_1;
  byte db_note_off_2;
  byte db_poly_key_press_1;
  byte db_poly_key_press_2;
  byte db_ctrl_change_1;
  byte db_ctrl_change_2;
  byte db_program_change;
// state variables
  bool serial_status;

public:
  // constructor
  MyMIDI();

  void begin();

  void end();

  void send_note_on(byte channel, byte note, byte velocity);

  void send_note_off(byte channel, byte note, byte velocity);
};

#endif

