# Prize Wheel: Circuit Playground Bluefruit
A code for using a Circuit Playground Bluefruit as a prize wheel! Created for the STEM Teachers Open House at the Cox Science Center &amp; Aquarium.

# Software & Hardware
## Circuit Playground 
The hardware used for this project is the Circuit Playground Bluefruit. 4 Circuit Playgrounds are at the Acreage Branch right now, in a wooden case on my desk with "Circuit Playground: Miami Maker Faire". The wooden case also holds alligator clips and data cables.

You can use any one of the Circuit Playgrounds, the software will upload on all of them.

## Arduino
The software used for this project is Arduino, which is free and open source. You can download it onto whatever computer is being used for the outreach using [this link through the Arduino page.](https://www.arduino.cc/en/software) 

## Processing
The software used to pretty-up the output is Processing. This is also a free and open source software. You can download it from [this link through the Processing Foundation.](https://processing.org/)

# Progress

In the very first demo, it was a simple shake to trigger some lights, a victory tune, and 1 of 2 outputs: a sticker or a bookmark.


https://github.com/varsvisualizes/circuitplayground-prizewheel/assets/47091936/eb9b3e10-c0ca-4575-8b4b-3dba91afd146


Once we got in the prizes, the code got a little more sophisticated. I broke down potential outputs based on the prizes available. 

<img width="1160" alt="Screen Shot 2023-09-30 at 11 22 56 AM" src="https://github.com/varsvisualizes/circuitplayground-prizewheel/assets/47091936/6ecc4c98-d5d1-4293-9d22-b6cb2c73ebaf">


Right now the probabilities are hardcoded in and I'd have to update them on the fly during the event as the prizes run out. If there's time I'd like to update the code so it automatically deducts from the prize pool every time someone wins something, but there's a risk of the CPB getting shaken and accidentally deducting unnecessarily. I'll have to think about whether it's worth the automation. 

# Todo

I plan to create a Processing sketch to make a very visually appealing output screen for displaying the prizes won. This is why there's a bit at the end of the Arduino code that reads "send to Processing" - it's all commented out for now so it doesn't accidentally interfere with anything else in the code while I write the Processing sketch separately. 
Processing Text: https://github.com/shiffman/LearningProcessing/blob/master/chp17_strings/exercise_17_10_interpolate_home/exercise_17_10_interpolate_home.pde
