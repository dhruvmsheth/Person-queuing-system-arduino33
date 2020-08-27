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
#include ESP32_Servo.h
#include <WiFi.h>
#include <WiFiMulti.h>
WiFiMulti WiFiMulti;
const char* ssid     = "JioFibertcz5n"; // Your SSID (Name of your WiFi)
const char* password = "*******"; //Your Wifi password
const char* host = "api.thingspeak.com";
String api_key = "RYYSAR2DUGXAMBIC"; // Your API Key provied by thingspeak
int count = 0;

// Define hardware type, size, and output pins:
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CS_PIN 3
// Create a new instance of the MD_Parola class with hardware SPI connection:
MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);


void setup()
{
  servo_8.attach(8);
  Serial.begin(9600);
    Connect_to_Wifi();
}

  // Intialize the object:
  myDisplay.begin();
  // Set the intensity (brightness) of the display (0-15):
  myDisplay.setIntensity(0);
  // Clear the display:
  myDisplay.displayClear();
}


void loop(){

 // call function to send data to Thingspeak
  Send_Data();

  delay(10);
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
    count++
    
  } else {
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDR, LOW);
    servo_8.write(180); // this servo moves to 180degrees when no person is detected
  }

  TF_LITE_REPORT_ERROR(error_reporter, "Person score: %d No person score: %d",
                       person_score, no_person_score);
}                     // Running this inference 10 times to allow 10 people in and then setting a delay of 15min


// Now we have let in 10people inside the store, so we set a delay of 15min wait time for others waiting outside to let them in 
// Displaying wait time on the screen every 1min

 if(count = 10)  // when 10 people are detected, we instruct it to start displaying wait time to other people to wait until 15 min 
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
   myDisplay.print("Go ");
  delay(1000);
  (count = 0); //the people count is again reset to 0 to repeat the action again
 // Finally they are allowed to go inside the store after 15min


 void Connect_to_Wifi()
{

  // We start by connecting to a WiFi network
  WiFiMulti.addAP(ssid, password);

  Serial.println();
  Serial.println();
  Serial.print("Wait for WiFi... ");

  while (WiFiMulti.run() != WL_CONNECTED) {
    Serial.print(".");
    delay(10);
  }

  SerialSerial.println("Prepare to send data");
.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

}

void Send_Data()
{

  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;

  const int httpPort = 80;

  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  else
  {
    String data_to_send = api_key;
    data_to_send += "&field1=";
    data_to_send += String(count);
    data_to_send += "\r\n\";

    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + api_key + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(data_to_send.length());
    client.print("\n\n");
    client.print(data_to_send);

    delay(10);  // reduced delay to perform real time data collection
  }

  client.stop();

}

#endif  // ARDUINO_EXCLUDE_CODE
