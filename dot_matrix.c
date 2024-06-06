/*
    Code by : Projects_learner
    Project name : LED Matrix Display  using Ardino UNO
    Modified Date : 06-06-2024
    Website : https://projectslearner.com/learn/arduino-uno-led-matrix-display
*/

#include <LedControl.h>

// Pin definitions
int dataInPin = 12;
int chipSelectPin = 11;
int clockPin = 10;

// Create an instance of the LedControl library
LedControl ledMatrix = LedControl(dataInPin, clockPin, chipSelectPin, 0);

void setup()
 {
  // Initialize the MAX72XX chip
  ledMatrix.shutdown(0, false);   // The MAX72XX is in power-saving mode on startup
  ledMatrix.setIntensity(0, 15);  // Set the brightness to maximum value
  ledMatrix.clearDisplay(0);      // Clear the display
}

void loop()
 {
  // Define the heart pattern to display
  byte heart[8] = 
  {
    0b00001010,  //    . . . █ . █ . .
    0b00011111,  //    . . █ █ █ █ █ .
    0b00111111,  //    . █ █ █ █ █ █ █
    0b00111111,  //    . █ █ █ █ █ █ █
    0b00111111,  //    . █ █ █ █ █ █ █
    0b00011111,  //    . . █ █ █ █ █ .
    0b00001110,  //    . . . █ █ █ . .
    0b00000100   //    . . . . █ . . .
  };

  displayPattern(heart);
  delay(1000);  // Display the heart pattern for 1 second
}

// Function to display a pattern on the LED matrix
void displayPattern(byte pattern[]) 
{
  for (int row = 0; row < 8; row++) 
  {
    ledMatrix.setRow(0, row, pattern[row]);
  }
}
