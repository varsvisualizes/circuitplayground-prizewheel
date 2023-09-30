/* 

A little cute output screen for participants of the 10/13 Outreach Event at the Cox Science Center.

Please run the Arduino sketch "prizewheel.ino" before running this sketch. 

30 Sept 2023
Carmen Peterson

*/

/*

  Import the Serial library into Processing so it can connect with the Arduino code

*/
import processing.serial.*;

Serial myPort;  // Create object from Serial class
static String val;    // Data received from the Arduino serial port
int prizeNum = 0;
PFont f;

void setup()
{
  size(1000,1000);
  noStroke();
  fill(204);

  /*
  Acknowledge that my Arduino exists & where it connects to the computer
  */
  myPort = new Serial(this, Serial.list()[1], 115200);

  /*
  Create the font we'll be using for the text
  */
  f = createFont("Futura",16,true);
}

void draw()
{
  /* 
  Code I took from an example on the Arduino site to get the prize number sent into Processing: 
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
  }  
  
  /* 
  Code to announce the prize that was won
  */

  /*
  Establish background color
  */
  background(204);

  /* 
  Establish font information (size, alignment, color fill)
  */
  textFont(f,60);
  textAlign(CENTER);
  fill(0);

  /*
  Output text corresponding to the prize one, based on the probability of winning that prize!
  */
  if(prizeNum < 10) {
    text("Congratulations! \nYou won a sharpener!",width/2,height/2-30);
  }
  else if(prizeNum >=10 && prizeNum < 30) {
    text("Congratulations! \nYou won a clip chip!",width/2,height/2-30);
  }
  else if(prizeNum >= 30 && prizeNum < 65) {
    text("Congratulations! \nYou won a pencil!",width/2,height/2-30);
  }
  else if(prizeNum >= 65) {
    text("Congratulations! \nYou won a pen!",width/2,height/2-30);
  }
  
}
