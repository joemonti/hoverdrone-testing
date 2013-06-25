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

