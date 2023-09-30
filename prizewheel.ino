/*  Circuit Playground Prize Wheel

    This sketch was made to use a Circuit Playground Bluefruit as a prize wheel for the
    STEM Teachers Open House at the Cox Science Center & Aquarium.

    The way to play is cupping the CPB in your hand and shaking it like a die. The Neopixel
    lights will sweep back and forth for a random number of runs, and then the Serial Monitor
    will output the prize won by the player.

    Our prize inventory is:

    40 Owl Shaped Pencil Sharpeners
    80 clip chips
    ~150 pencils
    ~150 pens

    Based on these numbers, I'll give the players a...

    9% chance of winning the pencil sharpener
    19% chance of winning the chip clip
    35% chance of winning a pencil
    35% chance of winning a pen

    These numbers can be modified on the fly as we run out of prizes to give out. Perhaps in
    another iteration I'll even make it an automatic statistics system, but for today,
    I'll hardcode in the probabilites.

    30 September 2023
    Carmen Peterson

*/

#include <Adafruit_CircuitPlayground.h>
#include <math.h>

int timer = 100;
int lightVal;
int num;
int prize;
int values[1];

float X, Y, Z, totalAccel;

float highestShake = 0;


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
        Select the winning prize number & the number of times the lights will flash
    */

    prize = random(0, 100);
    if ((round(prize / 10)) == 0) {
      num = 1;
    }
    else {
      num = round(prize / 10);
    }

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
    if (totalAccel > highestShake) {
      highestShake = totalAccel;
    }

    /*
        Check shake values (uncomment if you want to check)
    */

    //   Serial.println(totalAccel);

    /*
        If they shook pretty hard, say something silly
    */

    if (totalAccel > 25) {
      Serial.println("Buddy, no need to shake so hard!");
    }

    /*
        If a general shake is detected, complete the game code & output the prize won
    */

    if (totalAccel > 12) {

      for (int j = 0; j < num; j++) {

        for (int i = 0; i < 10; i++) {
          CircuitPlayground.setPixelColor(i,   0, 128, 128);
          delay(timer);
          CircuitPlayground.setPixelColor(i,   0, 0, 0);
        }
        for (int i = 9; i >= 0; i--) {
          CircuitPlayground.setPixelColor(i,   0, 128, 128);
          delay(timer);
          CircuitPlayground.setPixelColor(i,   0, 0, 0);
        }
      }

      /*
          Winning music tones
      */

      //            CircuitPlayground.playTone(523, 100);
      //            CircuitPlayground.playTone(659, 100);
      //            CircuitPlayground.playTone(784, 100);
      //            CircuitPlayground.playTone(1047, 100);


      /*
          Output to the Serial Monitor what they won
      */

            Serial.println("Congrats! You win: ");
      //
      //      if (num > 3) {
      //        Serial.println("Sticker!");
      //      }
      //      else {
      //        Serial.println("Bookmark!");
      //      }

              if(prize < 10) {
                Serial.println("An owl-shaped pencil sharpener!");
              }
              else if(prize >= 10 && prize < 30) {
                Serial.println("A chip clip!");
              }
              else if(prize >= 30 && prize < 65) {
                Serial.println("A pencil!");  
              }
              else if(prize >= 65) {
                Serial.println("A pen!");
              }

      Serial.println("Come win again soon! :)");
    }
    else {
      CircuitPlayground.setPixelColor(0, 0, 0, 0);
    }

  }

  // send to Processing
  //  values[0] = num;
  //  Serial.println(String(values[0]));


  delay(timer);

}
