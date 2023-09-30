# Prize Wheel: Circuit Playground Bluefruit
A code for using a Circuit Playground Bluefruit as a prize wheel! Created for the STEM Teachers Open House at the Cox Science Center &amp; Aquarium.

# Software & Hardware
## Circuit Playground 
The hardware used for this project is the Circuit Playground Bluefruit. 4 Circuit Playgrounds are at the Acreage Branch right now, in a wooden case on my desk with "Circuit Playground: Miami Maker Faire". The wooden case also holds alligator clips and data cables.

You can use any one of the Circuit Playgrounds, the software will upload on all of them.

## Arduino
The software used for this project is Arduino, which is free and open source. You can download it onto whatever computer is being used for the outreach using [this link through the Arduino page.](https://www.arduino.cc/en/software) 

The version of Arduino I have on my computer is v1.8. The work computer seems to only want to download v2.2, and I don't quite know how to connect the board to that version yet. I plan to put in a PNR to get the legacy v1.8 version installed on my computer, and we may also get that version installed on some of the staff training & programming laptops. More to come if I can figure out the installation process for v2.2. 

## Processing
The software used to pretty-up the output is Processing. This is also a free and open source software. You can download it from [this link through the Processing Foundation.](https://processing.org/)

# Progress

In the very first demo, it was a simple shake to trigger some lights, a victory tune, and 1 of 2 outputs: a sticker or a bookmark.


https://github.com/varsvisualizes/circuitplayground-prizewheel/assets/47091936/eb9b3e10-c0ca-4575-8b4b-3dba91afd146


Once we got in the prizes, the code got a little more sophisticated. I broke down potential outputs based on the prizes available. 

<img width="1160" alt="Screen Shot 2023-09-30 at 11 22 56 AM" src="https://github.com/varsvisualizes/circuitplayground-prizewheel/assets/47091936/6ecc4c98-d5d1-4293-9d22-b6cb2c73ebaf">


After establishing the probabilities, I created a Processing sketch that would display the text in a larger format on the screen. I also added unique lights for each prize won.

https://github.com/varsvisualizes/circuitplayground-prizewheel/assets/47091936/d5405859-70d8-4a62-af24-3610611c544e





https://github.com/varsvisualizes/circuitplayground-prizewheel/assets/47091936/87e22197-b6f1-40ab-a4f5-a63728549d85



Right now the probabilities are hardcoded in and I'd have to update them on the fly during the event as the prizes run out. If there's time I'd like to update the code so it automatically deducts from the prize pool every time someone wins something, but there's a risk of the CPB getting shaken and accidentally deducting unnecessarily. I'll have to think about whether it's worth the automation. 

# Todo

I hope to spice up the Processing sketch so it might have a cute animation when the prize is announced. Maybe it could look like a slot machine output, or just have the text wiggle and shake a bit! I'll keep working on it. 
