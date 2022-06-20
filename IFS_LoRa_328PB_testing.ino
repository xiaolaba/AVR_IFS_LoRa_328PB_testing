// xiaolaba 
/*
- https://www.facebook.com/invisiblefun/posts/2951385615082036
- invisiblefun.com Mini LoRa Development Board
- Samtech SX1276 for 915Mhz and 923Mhz application, LoRaWan chip
- MCU ATMEGA328PB
- AM1805 RTC (I2C interface, PC5/SCL0, PC4/SDA0)
- Extra Interrupt pin for further development, PC0 / PC1 / PC3 pin used
 */

/*
PC3 ADC3 (ADC Input Channel 3)
PCINT11 (Pin Change Interrupt 11)

PC2 ADC2 (ADC Input Channel 2)
PCINT10 (Pin Change Interrupt 10)

PC1 SCK1 (SPI1 Master Clock output)
ADC1 (ADC Input Channel 1)
PCINT9 (Pin Change Interrupt 9)

PC0 MISO1
ADC0 (ADC Input Channel 0)
PCINT8 (Pin Change Interrupt 8)
*/

//#include "detect_vcc.h"


// onbroad LED, PD5, pin9
// UART0, PD1/TXD0, PD0/RXD0 used for Serial dump, pin 30/31
// PC0 / PC1 / PC3, fan out, ADC or PCINT, pin 23/24/26
// MCU ISP shared pin MI0/MO0/SCK0 (pin 14/15/16) with SX1276


// constants won't change. Used here to set a pin number:
const int ledPin =  PIN_PD5;// the number of the LED pin
const int pc0Pin =  PIN_PC0;// the number of the LED pin
const int pc1Pin =  PIN_PC1;// the number of the LED pin
const int pc3Pin =  PIN_PC3;// the number of the LED pin

const int reedSwitchPin =  PIN_PB0;// the number of the reedSwitch pin


int sensorPin0 = A0;    // select the input pin for the potentiometer
int sensorPin1 = A1;    // select the input pin for the potentiometer
int sensorPin3 = A3;    // select the input pin for the potentiometer


// Variables will change:
int ledState = LOW;             // ledState used to set the LED
int reedSwitchState = LOW;      // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 1000;           // interval at which to blink (milliseconds)


int sensorValue0 = 0;  // variable to store the value coming from the sensor
int sensorValue1 = 0;  // variable to store the value coming from the sensor
int sensorValue3 = 0;  // variable to store the value coming from the sensor


void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
  pinMode(pc0Pin, OUTPUT);
  pinMode(pc1Pin, OUTPUT);
  pinMode(pc3Pin, OUTPUT);
  pinMode(reedSwitchPin, INPUT_PULLUP);

  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
}

void loop() {

/*
  sensorValue0 = analogRead(sensorPin0);
  delay(100);
  sensorValue1 = analogRead(sensorPin1);
  delay(100);
  sensorValue3 = analogRead(sensorPin3);
*/
  
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);

    // test pc0/pc1/pc3 IO control
    digitalWrite(pc0Pin, ledState);
    digitalWrite(pc1Pin, ledState);
    digitalWrite(pc3Pin, ledState);
            
    // prints title with ending line break
    Serial.println("xiaolaba IFS LoRa mini development broad testing");
/*
    Serial.println("PC0/ADC0 = " + String(sensorValue0) );
    Serial.println("PC1/ADC1 = " + String(sensorValue1) );
    Serial.println("PC3/ADC3 = " + String(sensorValue3) );
*/
    reedSwitchState = digitalRead(reedSwitchPin);
    if (reedSwitchState == LOW) Serial.println("reedSwitch = LOW" );
    else Serial.println("reedSwitch = HIGH" );
    
//    Serial.println("VCC = " + String(detectVcc()) + " mV"); delay(1000); 
  }
}
