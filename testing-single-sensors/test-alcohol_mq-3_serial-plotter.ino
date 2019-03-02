/*
  Open Hive | Alcohol (MQ-3 sensor)
  2019-02 Clemens Gruber | initial sketch
  2019-02 Clemens Gruber | optimized for serial plotter
  
  This code is in the public domain.
*/

// -------------------------+------
// variables you can modify | START
// -------------------------+------

const int alcoholSensorAnalogPin  = A1;  // AOUT sensor pin A0 of the arduino
const int alcoholSensorDigitalPin = A0;  // DOUT sensor pin D8 of the arduino
// we use also the pin for LED_BUILTIN

// -------------------------+----
// variables you can modify | END
// -------------------------+----

int value;  

// hint to the limit variable: 
// the digital output is vice versa the expectation 
// you may have, 
// - a high signal means limit not reached
// - a low signal means limit reached 
int limit; 


void setup() {
  // serial communication
  Serial.begin(9600);
  
  pinMode(alcoholSensorDigitalPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
  // read the sensor values
  value = analogRead(alcoholSensorAnalogPin);
  limit = digitalRead(alcoholSensorDigitalPin);

  // print values on the serial monitor
// some lines commented out to use output for serial plotter! 
//  Serial.print("alcohol value: ");
  Serial.print(value);
//  Serial.print("\tlimit: ");
//  Serial.print(limit);
  Serial.println();
  delay(1000);

  // switch Arduino onboard LED on or off based on the limit adjusted by the potentiometer on the PCB
  // hint: the behavior is vice versa the function on the 
  if (limit == HIGH){
    digitalWrite(LED_BUILTIN, LOW);
  }
  else{
    digitalWrite(LED_BUILTIN, HIGH);
  }
}
