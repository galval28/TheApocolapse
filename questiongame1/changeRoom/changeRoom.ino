#include "CurieIMU.h"
#include <stdio.h>
#include <Wire.h>
#include "rgb_lcd.h"
rgb_lcd lcd;
const int powerLButt = 1;
const int lButt = A0;
const int rButt = A1;
const int vibPin = 4;
int room;;
int time=0; //initialies the timer
int r = random(0, 245);
int g = random(0, 245);
int b = random(0, 245);
int key = 0;


void setup() {
  Serial.begin(9600); // initialize Serial communication
  while (!Serial);    // wait for the serial port to open

  // initialize device
  Serial.println("Initializing IMU device...");
  CurieIMU.begin();

  pinMode(powerLButt, OUTPUT);
  digitalWrite(powerLButt, HIGH);
  pinMode(rButt, INPUT);
  pinMode(lButt, INPUT);
  pinMode(vibPin, OUTPUT);
  lcd.begin(16, 2);
  lcd.setRGB(r, g, b);
  dasher();
  lcd.print("Are you ready to");
  lcd.setCursor(0, 1);
  lcd.print("go on adventure?");
  lcd.setCursor(0, 0);
  delay(1500);
  dasher();
  lcd.clear();

//   Set the accelerometer range to 2G
  CurieIMU.setAccelerometerRange(2);
  
  room=5;
   lcd.print("Welcome to the");
 lcd.setCursor(0,1);
 lcd.print("Dungeon");
 lcd.setCursor(0,0);
 delay(1000);

}
void dasher(){
lcd. print("-------------");  

}
int currentRoom=5;
void loop() {
 int orientation;
    int exi = 0;
    int tempcr;
    int newRoom;
    tempcr = currentRoom;
    int lastOrientation = - 1; // previous orientation (for comparison)
    lcd.clear();
    lcd.print("tilt the box");
    lcd.setCursor(0,1);
    lcd.print("where you want to go");
    lcd.setCursor(0,0);
    while(exi=0){ 
         int orientation = - 1;   // the board's orientation
         String orientationString; // string for printing description of orientation
         /*
    The orientations of the board:
    0: flat, processor facing up
    1: flat, processor facing down
    2: landscape, analog pins down
    3: landscape, analog pins up
    4: portrait, USB connector up
    5: portrait, USB connector down
        */
        // read accelerometer:
        int x = CurieIMU.readAccelerometer(X_AXIS);
        int y = CurieIMU.readAccelerometer(Y_AXIS);
        int z = CurieIMU.readAccelerometer(Z_AXIS);
        // calculate the absolute values, to determine the largest
        int absX = abs(x);
        int absY = abs(y);
        int absZ = abs(z);
        if ( (absZ > absX) && (absZ > absY)) {
        // base orientation on Z
           if (z > 0) {
       
              } else {
           }}
        if ( (absY > absX) && (absY > absZ)) {
        // base orientation on Y 
           if (y > 0) {
               orientationString = "left";
               orientation = 2;
               } 
            else { //analog pins up
                 orientationString = "right";
                 orientation = 3;
                 }
           } 
        else {
           // base orientation on X
             if (x < 0) {
                orientationString = "forward";
                orientation = 4;}
            else {
                orientationString = "backward";
                orientation = 5;
                }
              }
       // if the orientation has changed, print out a description:
       if (orientation != lastOrientation) {
          Serial.println(orientationString);
          lcd.clear();
          lcd.print("You went");
          lcd.setCursor(0,1);
          lcd.print(orientationString);
          lcd.setCursor(0,0);
          delay(1500);
          exi=exi+1;
          lastOrientation = orientation;    
          if(orientation == 2){
             tempcr = tempcr%3;
             if(tempcr == 1){
                newRoom=currentRoom;}
             else{newRoom=currentRoom-1;}
             }
           if(orientation==3){
              tempcr=tempcr%3;
              if(tempcr==0){
                 newRoom=currentRoom;}
              else{newRoom=currentRoom-1;}   
              }
           if(orientation==4){
              if(currentRoom<4){
                newRoom=currentRoom; 
                }
              else{newRoom=currentRoom-3;}
              }  
           else{
               if(currentRoom>6){
               newRoom=currentRoom;   
               }
               else{newRoom=currentRoom+3;}
               } }
           lcd.print(newRoom);
           delay(2000);
 }delay(750);}


