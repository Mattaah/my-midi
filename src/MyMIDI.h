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
  // nothing yet

public:
  // constructor
  MyMIDI();

  void send_note_on();

  void send_note_off();
  
};

#endif

