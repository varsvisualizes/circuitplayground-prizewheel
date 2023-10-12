/* 
 
 A little cute output screen for participants of the 10/13 Outreach Event at the Cox Science Center.
 
 
 Please run the Arduino sketch "prizewheel.ino" before running this sketch. 
 
 This sketch was made to as a cute output screen for the Circuit Playground Bluefruit being used as 
 a prize wheel for the STEM Teachers Open House at the Cox Science Center & Aquarium.
 
 The way to play is cupping the CPB in your hand and shaking it like a die. The Neopixel
 lights will sweep back and forth for a random number of runs, and then the Serial Monitor
 will output the prize won by the player.
 
 Our prize inventory is:
 
 40 Owl Shaped Pencil Sharpeners
 80 clip chips
 ~150 pencils
 ~150 pens
 
 The numbers will update as each prize is given out, so the probability will update automatically.
 
 Confetti background animation is an adaptation of Christy Garreau's "Meh Confetti Processing" code:
 https://gist.github.com/christygarreau/1a1aa1f23053d1562000e0b5ef4ebd96
 
 12 Oct 2023
 Carmen Peterson
 
 */

/*

 Import the Serial library into Processing so it can connect with the Arduino code
 
 */
import processing.serial.*;

Serial myPort;  // Create object from Serial class
static String val;    // Data received from the serial port
int prizeNum = 0;
PFont f;

// prize probabilities - if i wanted to make it iterative after all...
int owls = 40;
int chipClips = 80;
int pencils = 150;
int pens = 150;

int prob1;
int prob2;
int prob3;
int prob4;

int readingTime = 10000;
int drawTime;
int prevTime;

float y;

int[] colors = {#13ADA7, #F69421, #FCF47C};
int bg = #F5F3DA;

void setup()
{
  
  size(1440, 900);
  noStroke();

  y = 0;

  myPort = new Serial(this, Serial.list()[1], 115200);

  f = createFont("Futura", 16, true);
}

void draw()
{
  /* 
   Code I took from an example on the Arduino site: 
   https://www.arduino.cc/education/visualization-with-arduino-and-processing/
   */
  if ( myPort.available() > 0) {  // If data is available,
    val = myPort.readStringUntil('\n'); 
    try {
      prizeNum = Integer.valueOf(val.trim());
    }
    catch(Exception e) {
      ;
    }
    println(prizeNum); // confirm receipt of prize num!
    prevTime = millis(); // note the time we received the num
    println("prevTime is");
    println(prevTime);
  }  
  
  /*
  
  Code in the probabilities of winning each prize
  
  */
  
  prob1 = owls;
  prob2 = owls + chipClips;
  prob3 = owls + chipClips + pencils;
  prob4 = owls + chipClips + pencils + pens;

  /* 
   Code to announce the prize that was won
   */

  background(bg);
  textFont(f, 90);
  textAlign(CENTER);
  fill(colors[0]);

  if (prizeNum == 0) {
    text("Shake the \nCircuit Playground!", width/2, height/2-120);
  } else {
    
    if (prizeNum > 0 && prizeNum < 10) {
      background(bg);
      text("Congratulations! \nYou won a sharpener!", width/2, height/2-100);

      owls--;
    } else if (prizeNum >=10 && prizeNum < 30) {
      background(bg);
      text("Congratulations! \nYou won a clip chip!", width/2, height/2-100);

      chipClips--;
    } else if (prizeNum >= 30 && prizeNum < 65) {
      background(bg);
      text("Congratulations! \nYou won a pencil!", width/2, height/2-100);

      pencils--;
    } else if (prizeNum >= 65) {
      background(bg);
      text("Congratulations! \nYou won a pen!", width/2, height/2-100);

      pens--;
    }
    
      drawTime = millis();
      println("drawtime is ");
      println(drawTime);

      confetti();
  }

  if (prob4 == 0) {
    background(204);
    text("All prizes won!", width/2, height/2-80);
  }

  println("time passed is");
  println(drawTime - prevTime);

  if (drawTime - prevTime > readingTime) {
    prizeNum = 0;
    y = 0;
  }
}

void confetti() {
  for (int i = 0; i < width / 50; i++) {
    for (int j = 0; j < height/50; j++) {
      float rand1 = random(30);
      float rand2 = random(30);
      noStroke();
      fill(colors[round(random(0,2))]);
      ellipse(i*100 + rand1-rand2+15, y+rand1-rand2 + (j*50) - 100, 10, 15);
    }
  }
  y += 10;
}
