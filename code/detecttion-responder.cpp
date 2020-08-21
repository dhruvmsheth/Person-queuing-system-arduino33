/* Copyright Dhruv Sheth. Edited upon the initial person detction model trained by Tensorflow Authors
Credits: Tensorflow Authors and Arduino Team
==============================================================================*/

#if defined(ARDUINO) && !defined(ARDUINO_ARDUINO_NANO33BLE)
#define ARDUINO_EXCLUDE_CODE
#endif  // defined(ARDUINO) && !defined(ARDUINO_ARDUINO_NANO33BLE)

#ifndef ARDUINO_EXCLUDE_CODE

#include "detection_responder.h"
#include <servo.h>
#include "Arduino.h"
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// Define hardware type, size, and output pins:
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CS_PIN 3
// Create a new instance of the MD_Parola class with hardware SPI connection:
MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);


void setup()
{
  servo_8.attach(8);

}

  // Intialize the object:
  myDisplay.begin();
  // Set the intensity (brightness) of the display (0-15):
  myDisplay.setIntensity(0);
  // Clear the display:
  myDisplay.displayClear();
}

// Flash the blue LED after each inference
void RespondToDetection(tflite::ErrorReporter* error_reporter,
                        uint8_t person_score, uint8_t no_person_score) {
  static bool is_initialized = false;
  if (!is_initialized) {
    // Pins for the built-in RGB LEDs on the Arduino Nano 33 BLE Sense
    pinMode(LEDR, OUTPUT);
    pinMode(LEDG, OUTPUT);
    pinMode(LEDB, OUTPUT);
    is_initialized = true;
  }

  // Note: The RGB LEDs on the Arduino Nano 33 BLE
  // Sense are on when the pin is LOW, off when HIGH.

  // Switch the person/not person LEDs off
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDR, HIGH);

  // Flash the blue LED after every inference.
  digitalWrite(LEDB, LOW);
  delay(100);
  digitalWrite(LEDB, HIGH);

  // Switch on the green LED when a person is detected,
  // the red when no person is detected
  if (person_score > no_person_score) {
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDR, HIGH);
    servo_8.write(0);  // this servo moves to 0degrees in order to open the mall door when a person is detected to ensure no touch entry system
  } else {
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDR, LOW);
    servo_8.write(180); // this servo moves to 180degrees when no person is detected
  }

  TF_LITE_REPORT_ERROR(error_reporter, "Person score: %d No person score: %d",
                       person_score, no_person_score);
}                     // Running this inference 10 times to allow 10 people in and then setting a delay of 15min

  if (person_score > no_person_score) {
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDR, HIGH);
    servo_8.write(0);  // this servo moves to 0degrees in order to open the mall door when a person is detected to ensure no touch entry system
  } else {
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDR, LOW);
    servo_8.write(180); // this servo moves to 180degrees when no person is detected
  }

  TF_LITE_REPORT_ERROR(error_reporter, "Person score: %d No person score: %d",
                       person_score, no_person_score);
}

  if (person_score > no_person_score) {
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDR, HIGH);
    servo_8.write(0);  // this servo moves to 0degrees in order to open the mall door when a person is detected to ensure no touch entry system
  } else {
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDR, LOW);
    servo_8.write(180); // this servo moves to 180degrees when no person is detected
  }

  TF_LITE_REPORT_ERROR(error_reporter, "Person score: %d No person score: %d",
                       person_score, no_person_score);
}

  if (person_score > no_person_score) {
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDR, HIGH);
    servo_8.write(0);  // this servo moves to 0degrees in order to open the mall door when a person is detected to ensure no touch entry system
  } else {
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDR, LOW);
    servo_8.write(180); // this servo moves to 180degrees when no person is detected
  }

  TF_LITE_REPORT_ERROR(error_reporter, "Person score: %d No person score: %d",
                       person_score, no_person_score);
}

  if (person_score > no_person_score) {
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDR, HIGH);
    servo_8.write(0);  // this servo moves to 0degrees in order to open the mall door when a person is detected to ensure no touch entry system
  } else {
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDR, LOW);
    servo_8.write(180); // this servo moves to 180degrees when no person is detected
  }

  TF_LITE_REPORT_ERROR(error_reporter, "Person score: %d No person score: %d",
                       person_score, no_person_score);
}

  if (person_score > no_person_score) {
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDR, HIGH);
    servo_8.write(0);  // this servo moves to 0degrees in order to open the mall door when a person is detected to ensure no touch entry system
  } else {
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDR, LOW);
    servo_8.write(180); // this servo moves to 180degrees when no person is detected
  }

  TF_LITE_REPORT_ERROR(error_reporter, "Person score: %d No person score: %d",
                       person_score, no_person_score);
}

  if (person_score > no_person_score) {
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDR, HIGH);
    servo_8.write(0);  // this servo moves to 0degrees in order to open the mall door when a person is detected to ensure no touch entry system
  } else {
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDR, LOW);
    servo_8.write(180); // this servo moves to 180degrees when no person is detected
  }

  TF_LITE_REPORT_ERROR(error_reporter, "Person score: %d No person score: %d",
                       person_score, no_person_score);
}

  if (person_score > no_person_score) {
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDR, HIGH);
    servo_8.write(0);  // this servo moves to 0degrees in order to open the mall door when a person is detected to ensure no touch entry system
  } else {
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDR, LOW);
    servo_8.write(180); // this servo moves to 180degrees when no person is detected
  }

  TF_LITE_REPORT_ERROR(error_reporter, "Person score: %d No person score: %d",
                       person_score, no_person_score);
}

  if (person_score > no_person_score) {
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDR, HIGH);
    servo_8.write(0);  // this servo moves to 0degrees in order to open the mall door when a person is detected to ensure no touch entry system
  } else {
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDR, LOW);
    servo_8.write(180); // this servo moves to 180degrees when no person is detected
  }

  TF_LITE_REPORT_ERROR(error_reporter, "Person score: %d No person score: %d",
                       person_score, no_person_score);
}

  if (person_score > no_person_score) {
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDR, HIGH);
    servo_8.write(0);  // this servo moves to 0degrees in order to open the mall door when a person is detected to ensure no touch entry system
  } else {
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDR, LOW);
    servo_8.write(180); // this servo moves to 180degrees when no person is detected
  }

  TF_LITE_REPORT_ERROR(error_reporter, "Person score: %d No person score: %d",
                       person_score, no_person_score);
}

// Now we have let in 10people inside the store, so we set a delay of 15min wait time for others waiting outside to let them in 
// Displaying wait time on the screen every 1min


 myDisplay.setTextAlignment(PA_CENTER);
 myDisplay.print("Waiting 15min");
 delay(60000);
  myDisplay.setTextAlignment(PA_CENTER);
 myDisplay.print("Waiting 14min");
 delay(60000);
  myDisplay.setTextAlignment(PA_CENTER);
 myDisplay.print("Waiting 13min");
 delay(60000);
  myDisplay.setTextAlignment(PA_CENTER);
 myDisplay.print("Waiting 12min");
 delay(60000);
  myDisplay.setTextAlignment(PA_CENTER);
 myDisplay.print("Waiting 11min");
 delay(60000);
  myDisplay.setTextAlignment(PA_CENTER);
 myDisplay.print("Waiting 10min");
 delay(60000);
  myDisplay.setTextAlignment(PA_CENTER);
 myDisplay.print("Waiting 9min");
 delay(60000);
  myDisplay.setTextAlignment(PA_CENTER);
 myDisplay.print("Waiting 8min");
 delay(60000);
  myDisplay.setTextAlignment(PA_CENTER);
 myDisplay.print("Waiting 7min");
 delay(60000);
  myDisplay.setTextAlignment(PA_CENTER);
 myDisplay.print("Waiting 6min");
 delay(60000);
  myDisplay.setTextAlignment(PA_CENTER);
 myDisplay.print("Waiting 5min");
 delay(60000);
  myDisplay.setTextAlignment(PA_CENTER);
 myDisplay.print("Waiting 4min");
 delay(60000);
  myDisplay.setTextAlignment(PA_CENTER);
 myDisplay.print("Waiting 3min");
 delay(60000);
  myDisplay.setTextAlignment(PA_CENTER);
 myDisplay.print("Waiting 2min");
 delay(60000);
  myDisplay.setTextAlignment(PA_CENTER);
 myDisplay.print("Waiting 1min");
 delay(60000);
  myDisplay.setTextAlignment(PA_CENTER);
 myDisplay.print("Go in");
 delay(1000);
 // Finally they are allowed to go inside the store after 15min


#endif  // ARDUINO_EXCLUDE_CODE
