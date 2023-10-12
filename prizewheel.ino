/*  Circuit Playground Prize Wheel

    This sketch was made to use a Circuit Playground Bluefruit as a prize wheel for the
    STEM Teachers Open House at the Cox Science Center & Aquarium.

    The way to play is cupping the CPB in your hand and shaking it like a die. The Neopixel
    lights will sweep back and forth for a random number of runs, and then the Serial Monitor
    will output the prize won by the player.

    12 October 2023

    Carmen Peterson

*/

#include <Adafruit_CircuitPlayground.h>
#include <math.h>

int timer = 100;
int lightVal;
int num;
int prize;

/*
   Establishing the probabilities within the Arduino sketch
*/

int owls = 40;
int chipClips = 80;
int pencils = 150;
int pens = 150;

int prob1;
int prob2;
int prob3;
int prob4;

float X, Y, Z, totalAccel;


void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin();
  Serial.begin(115200);

}

void loop() {

  /*
     Activate light sensor
  */

  lightVal = CircuitPlayground.lightSensor();

  /*
      Light Value Sensor Check (uncomment if you want to check)
  */

  //  Serial.print("Light Sensor: ");
  //  Serial.println(lightVal);

  /*
      If the light sensor in the CPB is covered, start the game
  */
  if (lightVal < 100) {

    /*
        Calculate the likelihood of winning each item
    */

    prob1 = owls;
    prob2 = owls + chipClips;
    prob3 = owls + chipClips + pencils;
    prob4 = owls + chipClips + pencils + pens;

    /*
        Select a random winning prize number & random number of times the lights will flash
    */

    prize = random(1, prob4);
    num = random(1, 6);

    /*
        Check prize numbers (uncomment if you want to check)
    */

    //   Serial.print("The prize number is ");
    //   Serial.println(prize);
    //   Serial.print("And the num is ");
    //   Serial.println(num);

    /*
        Sensor values for the shaking
    */

    X = 0;
    Y = 0;
    Z = 0;
    for (int i = 0; i < 10; i++) {
      X += CircuitPlayground.motionX();
      Y += CircuitPlayground.motionY();
      Z += CircuitPlayground.motionZ();
      delay(1);
    }
    X /= 10;
    Y /= 10;
    Z /= 10;

    totalAccel = sqrt(X * X + Y * Y + Z * Z);

    /*
        Check shake values (uncomment if you want to check)
    */

    //   Serial.println(totalAccel);

    /*
        If they shook pretty hard, say something silly
    */

    if (totalAccel > 25) {
      //      Serial.println("Buddy, no need to shake so hard!");
    }

    /*
        If a general shake is detected, complete the game code & output the prize won
    */

    if (totalAccel > 15) {

      for (int j = 0; j < num; j++) {
        /*
          Have a neopixel color chase around the ring some random number of times
        */
        allColor(0, 128, 128);
      }

      /*
          Winning music tones
      */

            CircuitPlayground.playTone(523, 100);
            CircuitPlayground.playTone(659, 100);
            CircuitPlayground.playTone(784, 100);
            CircuitPlayground.playTone(1047, 100);

            Serial.println(prize);
            
      //      Serial.print("You won ");

      if (prize < prob1) {
        //        Serial.println("an owl sharpener!");
        owls--;
        allColor(255, 0, 255);
      }
      else if (prize >= prob1 && prize < prob2) {
        //        Serial.println("a chip clip!");
        chipClips--;
        allColor(255, 255, 0);
      }
      else if (prize >= prob2 && prize < prob3) {
        //        Serial.println("a pencil!");
        pencils--;
        allColor(0, 255, 0);
      }
      else if (prob3 >= prob4) {
        //        Serial.println("a pen!");
        pens--;
        allColor(255, 255, 255);
      }

      /*
           Send prize value to Processing for the prettier output
      */

      /*
            These print values are to make sure the probabilities are updating properly
            Uncomment if you ever need to check and make sure the math is working
      */

      //      Serial.print("There remain ");
      //      Serial.print(owls);
      //      Serial.print(" owls, ");
      //      Serial.print(chipClips);
      //      Serial.print(" chip clips, ");
      //      Serial.print(pens);
      //      Serial.print(" pencils, and ");
      //      Serial.print(pens);
      //      Serial.print(" pens. Total of ");
      //      Serial.print(prob4);
      //      Serial.print(" prizes remain!");
      
    }
    else {
      CircuitPlayground.setPixelColor(0, 0, 0, 0);
    }

  }

  /*
     Refresh every 100ms
  */
  delay(timer);

}

/*
   Function telling the Arduino how to have a Neopixel Chase
*/
void allColor(int r, int g, int b) {

  for (int i = 0; i < 10; i++) {
    CircuitPlayground.setPixelColor(i,   r, g, b);
    delay(timer);
    CircuitPlayground.setPixelColor(i,   0, 0, 0);
  }
  for (int i = 9; i >= 0; i--) {
    CircuitPlayground.setPixelColor(i,   r, g, b);
    delay(timer);
    CircuitPlayground.setPixelColor(i,   0, 0, 0);
  }

}
