#include "mbed.h"
#include "uLCD_4DGL.h"
#include "SDFileSystem.h"
#include "wave_player.h"
#include "mpr121.h"


DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);
SDFileSystem sd(p5, p6, p7, p8, "sd");
AnalogOut DACout(p18);
wave_player waver(&DACout);     //speaker
uLCD_4DGL uLCD(p28,p27,p30); // serial tx, serial rx, reset pin;
InterruptIn interrupt(p26);
I2C i2c(p9,p10);
Mpr121 mpr121(&i2c, Mpr121::ADD_VSS);   //touchpad
int global = 0;     //global variable for control statements

void fallInterrupt() {
  int key_code=0;
  int i=0;
  int value=mpr121.read(0x00);
  value +=mpr121.read(0x01)<<8;
  // LED demo mod
  i=0;
  // puts key number out to LEDs for demo
  for (i=0; i<12; i++) {
  if (((value>>i)&0x01)==1) key_code=i+1;
  }
  led4=key_code & 0x01;
  led3=(key_code>>1) & 0x01;
  led2=(key_code>>2) & 0x01;
  led1=(key_code>>3) & 0x01;
  if (key_code != 0) {
     global = key_code; 
     printf("%d\n", global);
    }   

}

int main() {
    interrupt.fall(&fallInterrupt);     //interupt routine for touchpad 
    interrupt.mode(PullUp);
    int score = 0;          //score of player
    volatile int v = 0;
    uLCD.media_init();      //init uLCd SD card
    uLCD.set_sector_address(0x003B, 0x5145);    //Welcome screen
    uLCD.display_image(0,0);
    wait(4.0);
    uLCD.cls();
    uLCD.printf("\n Press 0\n on touchpad\n to continue");
    while(global != 1) {        //block statement till user selects 0
        led1 = 1;
        };
    led1 = 0;           //flip LED for visual cue
    global = 0;         //reset global variable
    uLCD.cls();
    uLCD.set_sector_address(0x003B, 0x5000);    //bear image
    uLCD.display_image(0,0);
    FILE *wave_file;
    wave_file=fopen("/sd/cow.wav","r");
    waver.play(wave_file);
    fclose(wave_file);
    led1 = 1;
    FILE *wave_file1;
    wave_file1=fopen("/sd/bear_growl.wav","r");
    waver.play(wave_file1);
    fclose(wave_file1);    
    led1 = 0;
    FILE *wave_file2;
    wave_file2=fopen("/sd/lion.wav","r");
    waver.play(wave_file2);
    fclose(wave_file2);
    led1 = 1;
    uLCD.cls();
    uLCD.set_sector_address(0x003B, 0x5186);   //Select which sound you think is correct!
    uLCD.display_image(0,0); 
    while(v!=100) {         //infinite while until user selects choice
    printf("Inside while\n");
    if (global == 1 || global == 3) {       //wrong choices 
        uLCD.cls();
        uLCD.set_sector_address(0x003B, 0x5104);    //Incorrect!
        uLCD.display_image(0,0);
        wait(3);  
        v=100;      //exit while loop
        }
    else if (global == 2) {     //correct choice
        uLCD.cls();
        uLCD.set_sector_address(0x003B, 0x50C3);        //correct!
        uLCD.display_image(0,0);               
        score++;        //increment user score
        wait(3);
        v=100;
        }
    }//end while
    v = 0;          //reset while condition
    led1 = 0;       //flip led
    global = 0;
    uLCD.cls();
    uLCD.set_sector_address(0x003B, 0x5041);    //beaver image
    uLCD.display_image(0,0);         
    FILE *wave_file3;
    wave_file3=fopen("/sd/ape.wav","r");
    waver.play(wave_file3);
    fclose(wave_file3);
    led1 = 1;
    FILE *wave_file4;
    wave_file4=fopen("/sd/cat.wav","r");
    waver.play(wave_file4);
    fclose(wave_file4);    
    led1 = 0;
    FILE *wave_file5;
    wave_file5=fopen("/sd/beaver.wav","r");
    waver.play(wave_file5);
    fclose(wave_file5);
    led1 = 1;
    uLCD.cls();
    //uLCD.printf("\nSelect which sound you think is correct!\n");      
    uLCD.set_sector_address(0x003B, 0x5186);   
    uLCD.display_image(0,0);     
    while(v!=100) {
    printf("Inside while\n");
    if (global == 1 || global == 2) {
        uLCD.cls();
        //uLCD.printf("\nIncorrect!\n");  
        uLCD.set_sector_address(0x003B, 0x5104);    
        uLCD.display_image(0,0);
        wait(3);  
        v=100;  
        }
    else if (global == 3) {
        uLCD.cls();
        //uLCD.printf("\nCorrect!\n");
        uLCD.set_sector_address(0x003B, 0x50C3);    
        uLCD.display_image(0,0);               
        score++;
        wait(3);
        v=100;
        }
    }//end while
    v = 0;
    led1 = 0;
    global = 0;    
    uLCD.cls();
    uLCD.set_sector_address(0x003B, 0x5082);    //fox image
    uLCD.display_image(0,0);     
    FILE *wave_file6;
    wave_file6=fopen("/sd/racoon.wav","r");
    waver.play(wave_file6);
    fclose(wave_file6);
    led1 = 1;
    FILE *wave_file7;
    wave_file7=fopen("/sd/wolf.wav","r");
    waver.play(wave_file7);
    fclose(wave_file7);    
    led1 = 0;
    FILE *wave_file8;
    wave_file8=fopen("/sd/fox.wav","r");
    waver.play(wave_file8);
    fclose(wave_file8);
    led1 = 1;
    uLCD.cls();
    //uLCD.printf("\nSelect which sound you think is correct!\n");      
    uLCD.set_sector_address(0x003B, 0x5186);   
    uLCD.display_image(0,0);        
    while(v!=100) {
    printf("Inside while\n");
    if (global == 1 || global == 2) {
        uLCD.cls();
        //uLCD.printf("\nIncorrect!\n");  
        uLCD.set_sector_address(0x003B, 0x5104);    
        uLCD.display_image(0,0);
        wait(3);  
        v=100;  
        }
    else if (global == 3) {
        uLCD.cls();
        //uLCD.printf("\nCorrect!\n");
        uLCD.set_sector_address(0x003B, 0x50C3);    
        uLCD.display_image(0,0);               
        score++;
        wait(3);
        v=100;
        }
    }//end while
    v = 0;
    led1 = 0;
    global = 0;        
    uLCD.cls();         //End of game
    uLCD.printf("\nThanks for playing!\n");               
    uLCD.printf("\nYour score: %2D\n", score);          //display score          
    //can write file to SD card here
    while(1) {}
}
