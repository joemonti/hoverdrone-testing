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
