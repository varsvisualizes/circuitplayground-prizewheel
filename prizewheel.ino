#include <Adafruit_CircuitPlayground.h>

int timer = 100;
int lightVal;
int num;
int values[1];

float X, Y, Z, totalAccel;

float highestShake = 0;


void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin();
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:

  //  Serial.println("Come try our prize wheel! Cover the Circuit Playground in your hands and give it a shake.");

  lightVal = CircuitPlayground.lightSensor();

  //  Serial.print("Light Sensor: ");
  //  Serial.println(lightVal);

  if (lightVal < 100) {

    num = random(0, 7);

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

    //        Serial.println(totalAccel);

    if (totalAccel > 20) {
      Serial.println("Buddy, no need to shake so hard!");
    }

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
      
            CircuitPlayground.playTone(523, 100);
            CircuitPlayground.playTone(659, 100);
            CircuitPlayground.playTone(784, 100);
            CircuitPlayground.playTone(1047, 100);

      Serial.println("Congrats! You win a: ");

      if (num > 3) {
        Serial.println("Sticker!");
      }
      else {
        Serial.println("Bookmark!");
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
