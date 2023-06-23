# Garage Parking Assist
My project is the garage parking assistant. This is a device programmed to help a car park in a tight garage by putting a red light if the car is getting close to the wall to prevent the car from hitting the wall. When a car is backing out it returns to a green light indicating the car has plenty of space in front of it.

| **Engineer** | **School** | **Area of Intrest** | **Grade** |
|:--:|:--:|:--:|:--:|
| Arvind P| Mountain View High School | Hardware Engineering | Incoming Freshman



![Headstone Image](Arvind-Headshot.png)
<!--# Final Milestone
- What you've accomplished since your previous milestone
- What your biggest challenges and triumphs were at BSE
- A summary of key topics you learned about
- What you hope to learn in the future after everything you've learned at BS
--------

-->
# Third Milestone

<iframe width="560" height="350" src="https://www.youtube.com/embed/jUr4x9YDDTo" title="Arvind P. Milestone 3" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

My third milestone was being able to complete the entire garage parking assistant project. This included completing the light and ultrasonic portion of the project, as well as combining the two by coding it so that the light acts in accordance with the ultrasonic sensor. I was able to fix the code inorder to make it work between the time of the last milestone till the time that I finished this one. A major challenge I faced with my third project was the code working sometimes but not other times. This was a problem that took me a day to debug. However, something to note is to always quadruple check that your pins are set to the right thing. Because this is something that is pretty easy to miss and even through debugging it's hard to see. So it is very good if you start by checking if all of your pins are correct and are set to the correct thing in order to not waste time trying to study your entire code to debug the issue. Another challenge that I faced was the ultrasonic sensor not reading its data when the code tells it to. This is another problem that is very avoidable. A common issue that causes this is the serial monitor not being refreshed. I didn’t realize this was the problem until I tried to refresh the serial monitor and sure enough the ultrasonic sensor values began showing up. Overall there are many issues that could be easily avoidable. For any other issues like this you can look at the troubleshooting section in the schematics.


# Second Milestone

<iframe width="560" height="350" src="https://www.youtube.com/embed/lh4tWKUuAtc" title="Arvind P. Milestone 2" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

My second milestone was completing the LED strip part of my Garage Parking Assistant project. This is the part of the project that will be the guide for the vehicles to act according to what the light says. For example if it is red that means that there is plenty of space to go forward however it is red there is no more space to move forward and the vehicle should stop. Some of the components include a data cable, the power and ground cables, and the actual LED strip itself. Something that has been surprising is that just the regular wall outlet plug that connects to the LED is not the only thing that needs to be plugged in inorder to make the light actually light up. It also needs to be plugged into the arduino itself. That also happened to be the biggest challenge of this part of the project for me. The debugging took a lot of time to fully figure out, but once I did I was able to make the light activate. A challenge that was reoccurring for me was understanding the code, however this time I was able to fix it a bit faster because I already had some experience working with the code. I now need to re-wire some of the ground and power cables into a breadboard to make it easier to manage all of the cables in one place.


# First Milestone

<iframe width="560" height="350" src="https://www.youtube.com/embed/GFauvsFPPtU" title="Arvind P. Milestone 1" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

My first milestone was completing the ultrasonic sensor part of my garage parking assistant project. It is the part of the project that will detect how far the vehicle is from hitting the wall. Some of the components of the project include the ultrasonic sensor itself, ground and power cables, and Trig and Echo pins. A challenge I am faced with in my project that I can prevent in future projects is knowing how to actually code in C++! Before working on this part of my project I had know idea how to code in C++. However once I learned some of the basics I was able to make it work and read all of the distances. There weren’t any challenges that I had faced while making the ultrasonic sensor work that I had faced while making the Tv Be Gone. My plan to complete the project is to combine this to the LED. The LED will be working in correspondence to the LED and once I can make the LED work I will be able to combine the two and have a working Garage Parking Assistant!

 
# Starter Project

<iframe width="560" height="350" src="https://www.youtube.com/embed/TGxNgDbHCbw" title="Arvind P. Starter Project" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

My starter milestone was completing my starter project which was the Tv Be Gone. The Tv Be Gone is a Tv remote that can work anywhere on any Tv! Some of the components of the project include a button which is connected to a light that is programmed so that when the button is pressed the light will illuminate. A microcontroller that tells 4 infrared lights to send signals to Tv's to connect to them. There are also 4 resistor’s that regulate the flow of electricity in the remote. Some of the technical progress that I have made in my project include learning that filling holes with solder inside of the board will be a huge pain to get rid of. I also learned to be very careful when inserting resistors into the board as they can break easy when inserting. A challenge I have faced in my project that I have solved in my intensive project was not heating the heat shrink enough which makes the connection inside of the heat shrink weaker and as a result creating an issue in the project. This was fixed when using a heat shrink in my main project as I saw if the jap between the heat shrink and the wire was small enough and once it was I knew it could be sturdy enough. I will use the information I have learned in making my starter project and use it as my intensive project.


<!---# Schematics 

-->
#define trigPin       10  // ultrasonic sensro trig ping
#define echoPin       11  // ultrasonic sensro echo ping
#define NUM_LEDS      47  // How many leds in your strip?
#define DATA_PIN      3   // data pin for LED strip
#define ZONE          30  // default zone distance is 30 cms / a foot
#define MAXRR         30  // default distance for Flashing Red is 30 cms / a foot
#define MAXR          MAXRR+ZONE  // distance for Red
#define MAXY          MAXR+ZONE   // distance for Yellow/Amber
#define MAXG          MAXY+ZONE   // distance for Green
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
  Serial.begin(9600);
}

void loop() 
{
  CallSensor();
}

void CallSensor()
{
  // initiate ultrasonic sensor to fire
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0344; // use speed of sound to calc rountrip distance and divide by 2 to get one way distance
  Serial.println(distance);
  delay(200); // give a delay between successive firings of ultrasonic sensor

  if (distance > MAXG) // if distance is greater than MAXG clear all LEDs
  {
    fill_solid( leds, NUM_LEDS, CRGB::Black); 
    FastLED.show();
    return;
  }
  else if (distance > MAXY && distance < 60) 
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
  delay (250);
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

# Bill of Materials
Here's where you'll list the parts in your project. To add more rows, just copy and paste the example rows below.
Don't forget to place the link of where to buy each component inside the quotation marks in the corresponding row after href =. Follow the guide [here]([url](https://www.markdownguide.org/extended-syntax/)) to learn how to customize this to your project needs. 

| **Part** | **Note** | **Price** | **Link** |
|:--:|:--:|:--:|:--:|
| LED | This is used to tell the car how to act through color.| $32.99 | <a href="https://www.amazon.com/BTF-LIGHTING-Flexible-Individually-Addressable-Non-waterproof/dp/B01CDTEJBG/ref=sr_1_1_sspa?crid=2EJY8BP7FFZ2U&keywords=ws2812b%2Bled%2Bstrip&qid=1686776906&sprefix=WS2812B%2BL%2Caps%2C218&sr=8-1-spons&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUFTSU5NRk1GRUhBU0gmZW5jcnlwdGVkSWQ9QTA1MTg1NTUzSjBJSVY0QTVJRUxOJmVuY3J5cHRlZEFkSWQ9QTEwMDM4MzQxNFM3NEk2TEpKODBWJndpZGdldE5hbWU9c3BfYXRmJmFjdGlvbj1jbGlja1JlZGlyZWN0JmRvTm90TG9nQ2xpY2s9dHJ1ZQ&th=1"> Link </a> |
|:--:|:--:|:--:|:--:|
| Item Name | What the item is used for | $Price | <a href="https://www.amazon.com/Arduino-A000066-ARDUINO-UNO-R3/dp/B008GRTSV6/"> Link </a> |
|:--:|:--:|:--:|:--:|
| Item Name | What the item is used for | $Price | <a href="https://www.amazon.com/Arduino-A000066-ARDUINO-UNO-R3/dp/B008GRTSV6/"> Link </a> |
|:--:|:--:|:--:|:--:|

# Other Resources/Examples
One of the best parts about Github is that you can view how other people set up their own work. Here are some past BSE portfolios that are awesome examples. You can view how they set up their portfolio, and you can view their index.md files to understand how they implemented different portfolio components.
- [Example 1](https://trashytuber.github.io/YimingJiaBlueStamp/)
- [Example 2](https://sviatil0.github.io/Sviatoslav_BSE/)
- [Example 3](https://arneshkumar.github.io/arneshbluestamp/)

To watch the BSE tutorial on how to create a portfolio, click here.
