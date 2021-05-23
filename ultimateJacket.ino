    // color swirl! connect an RGB LED to the PWM pins as indicated
    // in the #defines
    // public domain, enjoy!
     
    #define REDPIN 5
    #define GREENPIN 6
    #define BLUEPIN 3
     
    #define FADESPEED 5     // make this higher to slow down
    const int Sensor = A0; // the piezo is connected to analog pin 0
    const int Sensor2 = A1;
    const int Sensor3 = A2;
    const int Sensor4 = A3;
    const int Sensor5 = A4;
const int threshold = 400;  // threshold value to decide when the detected sound is a knock or not


// these variables will change:
int sensorReading = 0;      // variable to store the value read from the sensor pin
int sensorReading2 = 0;
int sensorReading3 = 0;
int sensorReading4 = 0;
int sensorReading5 = 0;
int r =0;
int g =0;
int b =0;

     
    void setup() {
      pinMode(REDPIN, OUTPUT);
      pinMode(GREENPIN, OUTPUT);
      pinMode(BLUEPIN, OUTPUT);
        // Set MIDI baud rate:
      Serial.begin(31250);
    }
     
     
    void loop() {

      // fade from blue to violet
      r=0 ;
        analogWrite(REDPIN, r);
  
      // read the sensor and store it in the variable sensorReading:
  sensorReading = analogRead(Sensor);
  sensorReading2 = analogRead(Sensor2);
  sensorReading3 = analogRead(Sensor3);
  sensorReading4 = analogRead(Sensor4);
  sensorReading5 = analogRead(Sensor5);

  // if the sensor reading is greater than the threshold:
  if (sensorReading >= threshold) {
      // fade from red to yellow
      g =255;
        analogWrite(BLUEPIN, g);
        noteOn(0x90, 0x18, 0x45);
        delay(200); 
      g =0;
      analogWrite(BLUEPIN, g);
      noteOn(0x90, 0x18, 0x00);
  }
    if (sensorReading2 >= threshold) {
      // fade from red to yellow
      b =255;
        analogWrite(BLUEPIN, b);
                noteOn(0x90, 0x1A, 0x45);
        delay(200); 
      b =0;
      analogWrite(BLUEPIN, b);
      noteOn(0x90, 0x1A, 0x00);
  }
    if (sensorReading3 >= threshold) {
      // fade from red to yellow
      b =255;
        analogWrite(BLUEPIN, b);
        noteOn(0x90, 0x24, 0x45);
        delay(200); 
      b =0;
      analogWrite(BLUEPIN, b);
      noteOn(0x90, 0x24, 0x00);
  }
      if (sensorReading4 >= threshold) {
      // fade from red to yellow
      b =255;
        analogWrite(BLUEPIN, b);
        noteOn(0x90, 0x41, 0x45);
        delay(200); 
      b =0;
      analogWrite(BLUEPIN, b);
      noteOn(0x90, 0x41, 0x00);
  }
      if (sensorReading5 >= threshold) {
      // fade from red to yellow
      b =255;
        analogWrite(BLUEPIN, b);
        noteOn(0x90, 0x47, 0x45);
        delay(200); 
      b =0;
      analogWrite(BLUEPIN, b);
      noteOn(0x90, 0x47, 0x00);
  }
     
    }
    void noteOn(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}
