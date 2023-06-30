#include <FastLED.h>

#define trigPin       10  // ultrasonic sensro trig ping
#define echoPin       11  // ultrasonic sensro echo ping
#define NUM_LEDS      47  // How many leds in your strip?
#define DATA_PIN      3   // data pin for LED strip
#define ZONE          20  // default zone distance is 30 cms / a foot
#define MAXRR         30  // default distance for Flashing Red is 30 cms / a foot
#define MAXR          MAXRR+ZONE  // distance for Red
#define MAXY          MAXR+ZONE   // distance for Yellow/Amber
#define MAXG          MAXY+20   // distance for Green
#define MAXFLASHCOUNT 30  // max times to flash

CRGB leds[NUM_LEDS];        // Define the array of leds

float duration, distance;
int flashcount, LEDpercm;

void setup() 
{
  
  // initialize the LED strip
  //FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);  // GRB ordering is typical
  FastLED.addLeds<NEOPIXEL,3>(leds, NUM_LEDS);
  FastLED.clear();  // clear all pixel data
  FastLED.show();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // set the trig and echo pin modes

  LEDpercm = NUM_LEDS / ZONE ; // number of LEDs to glow per cm of distance measured
  int n = 0;
  for(int n = 0; n < NUM_LEDS/2; n++);  //code to run leds as red 
    leds[n] = CRGB (255, 0, 0);
    fill_solid(leds, NUM_LEDS, CRGB::Red); 
}

void loop() 
{
  CallSensor();
  CallUltrasonicSensor();
  
}

void CallSensor()
{
  // initiate ultrasonic sensor to fire
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0344; // use speed of sound to calc rountrip distance and divide by 2 to get one way distance

  delay(200); // give a delay between successive firings of ultrasonic sensor
  Serial.println("CallSensor");

  if (distance > MAXG) // if distance is greater than MAXG clear all LEDs
  {
    fill_solid( leds, NUM_LEDS, CRGB::Black); 
    FastLED.show();
    return;
  }
  else if (distance > MAXY && distance < MAXG) 
    ChangePixelColors(MAXG, distance, 0, 255, 0); // green color
  else if (distance > MAXR && distance < MAXY) 
    ChangePixelColors(MAXY, distance, 255, 126, 0); //Amber color
  else if (distance > MAXRR && distance < MAXR) 
    ChangePixelColors (MAXR, distance, 255, 0, 0); //red color
  else if (distance <= MAXRR) // we are in SOS zone, show flashing red
    ShowFlashingRed();
}

void ShowFlashingRed()
{
  if (flashcount >= MAXFLASHCOUNT) //stop flashing after MAX times
  {
    fill_solid( leds, NUM_LEDS, CRGB::Black);
    FastLED.show();
    return;
  }

  flashcount++; // increment the times we have flashed red

  fill_solid( leds, NUM_LEDS, CRGB(255, 0, 0)); //fill full LED strip with red color
  FastLED.show();
  delay (250);
  fill_solid( leds, NUM_LEDS, CRGB::Black);
  FastLED.show();
  delay (5);
}


void CallUltrasonicSensor()
{
  //Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  //Sets the trigPin on HIGH state for 10 micro seconds 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin, LOW);
  //reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  //Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(1000);
  
}

void ChangePixelColors(int zonemax, float distance, int R, int G, int B)
{
  int countLED;
  fill_solid(leds, NUM_LEDS, CRGB::Black); // reset the LED strip to black (or blank)

  // calculate the difference of distance between zone max and object distance. This is the distance
  // the object is at within the zone. E.g if zonemax is 120cm and object is at 100cm, we get 20cm
  // Use this 20cm and LEDpercm to calculate how many LEDs to show
  countLED = round((zonemax - distance)* LEDpercm) ; 
   
  for (int n = 0; n <= countLED; n++) // fill the LEDs with right color and until countLED 
    leds[n] = CRGB (R, G, B);
  
  FastLED.show();
  flashcount = 0; // we are no longer flashing red so reset this to zero
}