/*
 * HoverDrone Testing Sketch : Receiver Utilities
 *
 * This file is part of HoverDrone.
 *
 * HoverDrone is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * HoverDrone is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with HoverDrone.  If not, see <http://www.gnu.org/licenses/>. 
 *
 * Author: Joseph Monti <joe.monti@gmail.com>
 * Copyright (c) 2013 All Rights Reserved, http://joemonti.org/
 */

const int NUM_CHANNELS = 6;
const int MIN_IN_PULSE_WIDTH = 750;
const int MAX_IN_PULSE_WIDTH = 2250;
const int SYNC_GAP_LEN = 3000;
const int INITIALIZE_CYCLES = 5;

const int STATE_PENDING = 0;
const int STATE_INITIALIZING = 1;
const int STATE_READY = 2;

volatile unsigned long last_micros;
volatile int initializedCount;
volatile int state;
volatile int channel;
volatile int pulses[NUM_CHANNELS];

void receiver_setup( int pin ) {
  last_micros = 0;
  initializedCount = 0;
  state = STATE_PENDING;
  channel = 0;
  
  attachInterrupt( pin, receiver_interrupt, RISING);
}

void receiver_interrupt( ) {
  unsigned long current_micros = micros();
  unsigned long gap = current_micros - last_micros;
  
  if ( gap >= SYNC_GAP_LEN ) {
    if ( state == STATE_READY ) {
      if ( channel != NUM_CHANNELS ) {
        state = STATE_INITIALIZING;
      }
    } else if ( state == STATE_INITIALIZING ) {
      initializedCount++;
      if ( initializedCount >= INITIALIZE_CYCLES ) {
        state = STATE_READY;
      }
    } else {
      state = STATE_INITIALIZING;
      initializedCount = 0;
    }
    channel = 0;
  } else if ( channel < NUM_CHANNELS ) {
    if ( gap >= MIN_IN_PULSE_WIDTH && gap <= MAX_IN_PULSE_WIDTH ) {
      pulses[channel] = gap;
      channel++;
    } else if ( state == STATE_READY ) {
      state = STATE_INITIALIZING;
      channel = 0;
    }
  }
  
  last_micros = current_micros;
}

int getState() { 
  return state;
}

int getValue( int c ) {
  if ( state == STATE_READY ) {
    return pulses[c];
  } else {
    return -1;
  }
}
