
//Libraries
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

//Define 7 Segment #1
Adafruit_7segment matrix = Adafruit_7segment();

//Define 7 Segment #2
Adafruit_7segment matrix2 = Adafruit_7segment();

void setup() {

  //Debug Light Definition & Enabling
  pinMode(1, OUTPUT);

  //Contact Definitions
  pinMode(10, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(0, INPUT_PULLUP);

  //Initialize 7 Segment #1
  matrix.begin(0x70);

  //Initialize 7 Segment #2
  matrix2.begin(0x71);
}

void loop() {
  //Check if all pieces are in place (All Contacts read LOW)
  if (digitalRead(10) == LOW && digitalRead(9) == LOW && digitalRead(8) == LOW && digitalRead(0) == LOW){
    //All pieces are in place!
    digitalWrite(1, HIGH);
    
    DisplayCode1(3, 2, 8, 7);
    
    matrix2.println("FUEL");
    matrix2.writeDisplay();
  }
  else{
    //Not all pieces are in place  
    digitalWrite(1, LOW);
    
    matrix.print("    ");
    matrix.writeDisplay();
    
    matrix2.print("    ");
    matrix2.writeDisplay();
  }
}

//Function to control code display
void DisplayCode1(int num1, int num2, int num3, int num4){
  matrix.writeDigitNum(0, num1, false);
  matrix.writeDigitNum(1, num2, false);
  matrix.drawColon(false);
  matrix.writeDigitNum(3, num3, false);
  matrix.writeDigitNum(4, num4, false);
  matrix.writeDisplay();
}

void DisplayCode2(int num1, int num2, int num3, int num4){
  matrix2.writeDigitNum(0, num1, false);
  matrix2.writeDigitNum(1, num2, false);
  matrix2.drawColon(false);
  matrix2.writeDigitNum(3, num3, false);
  matrix2.writeDigitNum(4, num4, false);
  matrix2.writeDisplay();
}
