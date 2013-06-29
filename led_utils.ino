/*
 * HoverDrone Testing Sketch : LED Utilities
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

const int LED_MIN_DELAY = 50;
const int LED_MAX_DELAY = 500;
boolean lastLed = LOW;
int nextLedMillis = 0;


void led_init_blink() {
  lastLed = LOW;
  nextLedMillis = millis();
}

void led_blink() {
  if ( millis() >= nextLedMillis ) {
    lastLed = !lastLed;
    digitalWrite( LED_PIN0, lastLed );
    
    if ( encValue == 0 ) {
      digitalWrite( LED_PIN1, HIGH );
    } else {
      digitalWrite( LED_PIN1, LOW );
    }
    
    if ( encValue == MAX_MOTOR_VALUE ) {
      digitalWrite( LED_PIN2, HIGH );
    } else {
      digitalWrite( LED_PIN2, LOW );
    }
    
    nextLedMillis = millis() + ( map( MAX_MOTOR_VALUE-encValue, 0, MAX_MOTOR_VALUE, LED_MIN_DELAY, LED_MAX_DELAY ) ) ;
  }
}

void led_count() {
  if ( encValue & 1 ) {
    digitalWrite( LED_PIN0, HIGH );
  } else {
    digitalWrite( LED_PIN0, LOW );
  }
    
  if ( encValue & 2 ) {
    digitalWrite( LED_PIN1, HIGH );
  } else {
    digitalWrite( LED_PIN1, LOW );
  }
    
  if ( encValue & 4 ) {
    digitalWrite( LED_PIN2, HIGH );
  } else {
    digitalWrite( LED_PIN2, LOW );
  }
    
  if ( encValue & 8 ) {
    digitalWrite( LED_PIN3, HIGH );
  } else {
     digitalWrite( LED_PIN3, LOW );
  }
}  

