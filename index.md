# Garage Parking Assist
My project is the garage parking assistant. This is a device programmed to help a car park in a tight garage by putting a red light if the car is getting close to the wall to prevent the car from hitting the wall. When a car is backing out it returns to a green light indicating the car has plenty of space in front of it.

| **Engineer** | **School** | **Area of Intrest** | **Grade** |
|:--:|:--:|:--:|:--:|
| Arvind P| Mountain View High School | Hardware Engineering | Incoming Freshman

**Replace the BlueStamp logo below with an image of yourself and your completed project. Follow the guide [here](https://tomcam.github.io/least-github-pages/adding-images-github-pages-site.html) if you need help.**

![Headstone Image](logo.svg)
  
<!-- # Final Milestone
-For your final milestone, explain the outcome of your project. Key details to include are:
- What you've accomplished since your previous milestone
- What your biggest challenges and triumphs were at BSE
- A summary of key topics you learned about
- What you hope to learn in the future after everything you've learned at BSE

-->
# Second Milestone
My second milestone was completing the LED strip part of my Garage Parking Assistant project. This is the part of the project that will be the guide for the vehicles to act according to what the light says. For example if it is red that means that there is plenty of space to go forward however it is red there is no more space to move forward and the vehicle should stop. Some of the components include a data cable, the power and ground cables, and the actual LED strip itself. Something that has been surprising is that just the regular wall outlet plug that connects to the LED is not the only thing that needs to be plugged in inorder to make the light actually light up. It also needs to be plugged into the arduino itself. That also happened to be the biggest challenge of this part of the project for me. The debugging took a lot of time to fully figure out, but once I did I was able to make the light activate. A challenge that was reoccurring for me was understanding the code, however this time I was able to fix it a bit faster because I already had some experience working with the code. I now need to re-wire some of the ground and power cables into a breadboard to make it easier to manage all of the cables in one place.

<iframe width="560" height="350" src="https://www.youtube.com/embed/lh4tWKUuAtc" title="Arvind P. Milestone 2" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

# First Milestone
My first milestone was completing the ultrasonic sensor part of my garage parking assistant project. It is the part of the project that will detect how far the vehicle is from hitting the wall. Some of the components of the project include the ultrasonic sensor itself, ground and power cables, and Trig and Echo pins. A challenge I am faced with in my project that I can prevent in future projects is knowing how to actually code in C++! Before working on this part of my project I had know idea how to code in C++. However once I learned some of the basics I was able to make it work and read all of the distances. There weren’t any challenges that I had faced while making the ultrasonic sensor work that I had faced while making the Tv Be Gone. My plan to complete the project is to combine this to the LED. The LED will be working in correspondence to the LED and once I can make the LED work I will be able to combine the two and have a working Garage Parking Assistant!

<iframe width="560" height="350" src="https://www.youtube.com/embed/GFauvsFPPtU" title="Arvind P. Milestone 1" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>
 
# Starter Project
My starter milestone was completing my starter project which was the Tv Be Gone. The Tv Be Gone is a Tv remote that can work anywhere on any Tv! Some of the components of the project include a button which is connected to a light that is programmed so that when the button is pressed the light will illuminate. A microcontroller that tells 4 infrared lights to send signals to Tv's to connect to them. There are also 4 resistor’s that regulate the flow of electricity in the remote. Some of the technical progress that I have made in my project include learning that filling holes with solder inside of the board will be a huge pain to get rid of. I also learned to be very careful when inserting resistors into the board as they can break easy when inserting. A challenge I have faced in my project that I have solved in my intensive project was not heating the heat shrink enough which makes the connection inside of the heat shrink weaker and as a result creating an issue in the project. This was fixed when using a heat shrink in my main project as I saw if the jap between the heat shrink and the wire was small enough and once it was I knew it could be sturdy enough. I will use the information I have learned in making my starter project and use it as my intensive project.

<iframe width="560" height="350" src="https://www.youtube.com/embed/TGxNgDbHCbw" title="Arvind P. Starter Project" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

# Schematics 
Here's where you'll put images of your schematics. [Tinkercad](https://www.tinkercad.com/blog/official-guide-to-tinkercad-circuits) and [Fritzing](https://fritzing.org/learning/) are both great resoruces to create professional schematic diagrams, though BSE recommends Tinkercad becuase it can be done easily and for free in the browser. 

# Code
Here's where you'll put your code. The syntax below places it into a block of code. Follow the guide [here]([url](https://www.markdownguide.org/extended-syntax/)) to learn how to customize it to your project needs. 

```c++
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello World!");
}

void loop() {
  // put your main code here, to run repeatedly:

}
```

# Bill of Materials
Here's where you'll list the parts in your project. To add more rows, just copy and paste the example rows below.
Don't forget to place the link of where to buy each component inside the quotation marks in the corresponding row after href =. Follow the guide [here]([url](https://www.markdownguide.org/extended-syntax/)) to learn how to customize this to your project needs. 

| **Part** | **Note** | **Price** | **Link** |
|:--:|:--:|:--:|:--:|
| Item Name | What the item is used for | $Price | <a href="https://www.amazon.com/Arduino-A000066-ARDUINO-UNO-R3/dp/B008GRTSV6/"> Link </a> |
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
