/*
  MyMIDI.cpp - Library for MIDI protocol communication output with Arduino
  
  MyMIDI is an Arduino library focused on MIDI output from microcontroller communication
  to other devices, such as computer softwares. This library is destinated to apply some
  abstractions to MIDI concepts that are consistently need to be repeated.

  Author  : Mattah
  Version : 1.0.0
  Created : 14/07/2026
  Modified: 14/07/2026
  License : MIT 
*/

#include "Arduino.h"
#include "MyMIDI.h"
#include "MIDI_messages"

// baud rate constant
#define BAUD_RATE 31250

// constructor
MyMIDI::MyMIDI()
{}

// initialize UART protocol
void MyMIDI::begin()
{
  if (!Serial.available)
  { 
    Serial.begin(BAUD_RATE);
    serial_status =    true;
  }
}

// end UART protocol
void MyMIDI::end()
{
  if (serial_status)
  {
    Serial.end();
    serial_status = false;
  }
}

// send MIDI message to note on
void MyMIDI::send_note_on(byte channel, byte note, byte velocity)
{
  // verify the parameter limits
  if (((CHANNEL_01 + 0b01) <= channel  && channel <= (CHANNEL_16 + 0b01)) &&
      (0b0                 <= note     && note     <= 0b1111111         ) &&
      (0b0                 <= velocity && velocity <= 0b1111111         ))
  {
    // convert the data into binary system (optional) and store in object members
    status_note_on = STATUS_NOTE_ON | byte(channel-1);
    db_note_on_1   =                  byte(note     );
    db_note_on_2   =                  byte(velocity );

    // verify the serial status (ON or OFF)
    if (serial_status)
    {
      // send the message via UART protocol (which is implemented in Serial class)
      Serial.write(status_note_on);
      Serial.write(db_note_on_1  );
      Serial.write(db_note_on_2  );
    }
  }
}

// send MIDI message to note on
void MyMIDI::send_note_off(byte channel, byte note)
{
  // verify the parameter limits
  if (((CHANNEL_01 + 0b01) <= channel  && channel <= (CHANNEL_16 + 0b01)) &&
      (0b0                 <= note     && note     <= 0b1111111         )
  {
    // convert the data into binary system (optional) and store in object members
    status_note_off = STATUS_NOTE_OFF | channel;
    db_note_off_1  =                 byte(note);
    db_note_off_2  =                 0b00000000;

    // verify the serial status (ON or OFF)
    if (serial_status)
    {
      // send the message via UART protocol (which is implemented in Serial class)
      Serial.write(status_note_off);
      Serial.write(db_note_off_1  );
      Serial.write(db_note_on_2   );
    }
  }
}
