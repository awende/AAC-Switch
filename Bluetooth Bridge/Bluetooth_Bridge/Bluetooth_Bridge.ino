#include<SoftwareSerial.h>

SoftwareSerial soft(8,9); // Used to communicate with the RN-41. 8-RX, 9-TX

const byte button=3, proximity=2; // Pins used to sense if button has been pressed

void setup() {
  Serial.begin(115200); // Used for debugging
  soft.begin(115200);   // used for communicating with the RN-41
  
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
}

void loop() {
  if(digitalRead(button) == 0)  // Button switch is pressed
  {
    soft.print(char(5));
    Serial.println("Button Pressed");
    while(digitalRead(button) == 0) // Wait for button to be released
    {
      delay(5);
    }
  }
  if(digitalRead(proximity) == 0) // Proximity switch is "pressed"
  {
    soft.print(char(6));
    Serial.println("Proximity Pressed");
    while(digitalRead(proximity) != 0)  // Wait for button to be released
    {
      delay(5);
    }
  }
}
