/*

p5.js code I used to calculate the probabilities of the prizes. This will be incorporated into the Processing code later on tonight.

*/

let owls = 10;
let clips = 20;
let pencils = 35;
let pens = 35;

let prob1;
let prob2;
let prob3;
let prob4;

let prize;

function setup() {
  createCanvas(400, 400);
}

function draw() {
  background(220);
  
  prob1 = owls;
  prob2 = owls + clips;
  prob3 = owls + clips + pencils;
  prob4 = owls + clips + pencils + pens;

}

function keyPressed() {
  if(keyCode === 32) {
    prize = round(random(1, prob4));
  }
  if(prize < prob1) {
    owls--;
    console.log(prize + "! You won an owl! There are now " + owls + " owls out of " + prob4 + " prizes.");
  }
  else if(prize >= prob1 && prize < prob2) {
    clips--;
    console.log(prize + "! You won an clip! There are now " + clips + " clips out of " + prob4 + " prizes.");
  }
  else if(prize >=prob2 && prize < prob3) {
    pencils--;
    console.log(prize + "! You won an pencil! There are now " + pencils + " pencils out of " + prob4 + " prizes.");
  }
  else if(prize >= prob3 && prize < prob4) {
    pens--;
    console.log(prize + "! You won an pen! There are now " + pens + " pens out of " + prob4 + " prizes.");
  }
  
  console.log("Probabilities are now " + prob1 + ", " + prob2 + ", " + prob3 + ", " + prob4)
}
