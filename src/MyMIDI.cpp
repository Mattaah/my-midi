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

// init UART serial communication protocol
void MyMIDI::begin()
{
  if (!Serial.available)
  { 
    Serial.begin(BAUD_RATE);
    serial_status =    true;
  }
}

// end UART serial communication protocol
void MyMIDI::end()
{
  if (serial_status)
  {
    Serial.end();
    serial_status = false;
  }
}

// send MIDI message note on
void MyMIDI::send_note_on(byte channel, byte note, byte velocity)
{
  // verify the parameter limits
  if (((CHANNEL_01 + 0b01) <= channel  && channel <= (CHANNEL_16 + 0b01)) &&
      (0b0                 <= note     && note     <= 0b1111111         ) &&
      (0b0                 <= velocity && velocity <= 0b1111111         ))
  {
    // convert the data into binary system (optional) and store in object members
    sb_note_on   = STATUS_NOTE_ON | byte(channel-1);
    db_note_on_1 =                  byte(note     );
    db_note_on_2 =                  byte(velocity );

    if (velocity == 0b0)
    { sb_note_off_1 = sb_note_on; }

    // verify the serial status (ON or OFF)
    if (serial_status)
    {
      // send the message via UART protocol (which is implemented in Serial class)
      Serial.write(sb_note_on  );
      Serial.write(db_note_on_1);
      Serial.write(db_note_on_2);
    }
  }
}

// send MIDI message note off
void MyMIDI::send_note_off(byte channel, byte note, byte velocity)
{
  // verify the parameter limits
  if (((CHANNEL_01 + 0b01) <= channel  && channel <= (CHANNEL_16 + 0b01)) &&
      (0b0                 <= note     && note     <= 0b1111111         ) &&
      (0b0                 <= velocity && velocity <= 0b1111111         ))
  {
    // convert the data into binary system (optional) and store in object members
    sb_note_off_2  = STATUS_NOTE_OFF | byte(channel-1);
    db_note_off_1  =                   byte(note     );
    db_note_off_2  =                   byte(velocity );

    // verify the serial status (ON or OFF)
    if (serial_status)
    {
      // send the message via UART protocol (which is implemented in Serial class)
      Serial.write(sb_note_off_2 );
      Serial.write(db_note_on_1  );
      Serial.write(db_note_on_2  );
    }
  }
}

// send control change message
void MyMIDI::send_control_change(byte channel, byte controller, byte controller_value)
{
  // verify the parameter limits
  if (((CHANNEL_01 + 0b01) <= channel          && channel <= (CHANNEL_16 + 0b01)) &&
      (0b0                 <= controller       && controller     <= 0b1110111   ) &&
      (0b0                 <= controller_value && controller_value <= 0b1111111 ))
  {
    sb_ctlr_change = STATUS_NOTE_CC | byte(channel-1       );
    db_ctrl_change_1 =                byte(controller      );
    db_ctrl_change_2 =                byte(controller_value);
  }
}
