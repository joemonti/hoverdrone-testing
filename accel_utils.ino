/*
 * HoverDrone Testing Sketch : Acelleromter Utilities
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

const int ANALOG_RESOLUTION = 12;

const int ACCEL_PIN_X = 0;
const int ACCEL_PIN_Y = 1;
const int ACCEL_PIN_Z = 2;

const int ACCEL_DELAY = 200;

int nextAccelMillis = 0;

int accelVal = 0;

void accel_init() {
  analogReadResolution( ANALOG_RESOLUTION );
  
  nextAccelMillis = millis();
}

void accel_update() {
  if ( millis() >= nextAccelMillis ) {
    accelVal = analogRead( ACCEL_PIN_X );
    Serial.print( accelVal );
    Serial.print( "," );
    accelVal = analogRead( ACCEL_PIN_Y );
    Serial.print( accelVal );
    Serial.print( "," );
    accelVal = analogRead( ACCEL_PIN_Z );
    Serial.println( accelVal );
        
    nextAccelMillis = millis() + ACCEL_DELAY;
  }
}
