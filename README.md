# Prize Wheel: Circuit Playground Bluefruit
A code for using a Circuit Playground Bluefruit as a prize wheel! Created for the STEM Teachers Open House at the Cox Science Center &amp; Aquarium.

# Software & Hardware
## Circuit Playground 
The hardware used for this project is the [Circuit Playground Bluefruit.](https://learn.adafruit.com/adafruit-circuit-playground-bluefruit/overview) 4 Circuit Playgrounds are at the Acreage Branch right now, in a wooden case on my desk with "Circuit Playground: Miami Maker Faire". The wooden case also holds alligator clips and data cables.

You can use any one of the Circuit Playgrounds, the software will upload on all of them.

## Arduino
The software used for this project is Arduino, which is free and open source. You can download it onto whatever computer is being used for the outreach using [this link through the Arduino page.](https://www.arduino.cc/en/software) 

## Processing
The software used to pretty-up the output is Processing. This is also a free and open source software. You can download it from [this link through the Processing Foundation.](https://processing.org/)

# Set-Up Process

1. Download the Arduino & Processing software to your computer.
2. Download the Arduino & Processing files from this repository.
3. Connect the Circuit Playground Bluefruit to the Arduino software. (Select the appropriate board & port combo - see above regarding my pending installation notes)
4. Verify and upload the Arduino sketch. You'll hear a little "click!" when the Circuit Playground has successfully burned the code.
5. Close out the Arduino sketch, and open up the Processing sketch.
6. Hit the "Play" button on Processing.
7. Shake the Circuit Playground - you should get the lights, sounds, and text output.
8. Win your prize!


# Progress

In the very first demo, it was a simple shake to trigger some lights, a victory tune, and 1 of 2 outputs: a sticker or a bookmark.


https://github.com/varsvisualizes/circuitplayground-prizewheel/assets/47091936/eb9b3e10-c0ca-4575-8b4b-3dba91afd146


Once we got in the prizes, the code got a little more sophisticated. I broke down potential outputs based on the prizes available. 

<img width="1160" alt="Screen Shot 2023-09-30 at 11 22 56 AM" src="https://github.com/varsvisualizes/circuitplayground-prizewheel/assets/47091936/6ecc4c98-d5d1-4293-9d22-b6cb2c73ebaf">


After establishing the probabilities, I created a Processing sketch that would display the text in a larger format on the screen. I also added unique lights for each prize won.

https://github.com/varsvisualizes/circuitplayground-prizewheel/assets/47091936/d5405859-70d8-4a62-af24-3610611c544e


https://github.com/varsvisualizes/circuitplayground-prizewheel/assets/47091936/68ea128e-3c85-490e-8b8e-2839d479ba8f


For the next iteration, I added in a few bells and whistles: I made a neutral page for the screen to display between rolls, and I threw in a confetti animation upon prize announcement.  

On the day of the event, we had 145 people pass by our booth! Several enjoyed using the Circuit Playground and were excited to learn about the tech programs that we offer with the library systems, including classes on creative coding and tech toys. 



https://github.com/varsvisualizes/circuitplayground-prizewheel/assets/47091936/8f7e0f99-a8d8-4af5-b5b7-462c191c37de



# Todo

From the outreach event, I realized that the wait times took much longer than I anticipated. The lights ran a little longer than I would have liked, and the reset also took up time. Also, almost all the participants wanted to shake the Circuit Playground until something on-screen changed, which I worry may have led to some sensor overload. So, in my next iteration I'll reduce the light animation time and the amount of time their prize is announced on the screen, and I'll test to make sure that they can shake the Circuit Playground for the entire loading time without negatively impacting the prize result or overloading the program. Can't wait to roll it out again!
