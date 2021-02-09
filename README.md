# animalSoundGame
A system to test your knowledge of animal sounds!


## Animal Sound Game 
Animal Sound Game is a game designed to test players knowledge. Players will be shown a series of animal images and played a series of sounds. Afterwards, they will be prompted to input which sound they thought was the correct one. This is repeated until the last image, and the user is informed of their score. \\

Images are loaded onto a raw partition on an SD card attached to the uLCD. Sounds are loaded onto an SD card interfaced to MBED. An I2C capacitive touch pad registers inputs via a software interrupt routine. A speaker and audio amp play animal sounds.  

The program flow begins with a welcome screen and 4 second wait, followed by a prompt to press 0 to begin the game. Once 0 is pressed on the touchpad, the first image of a bear is displayed. Three sounds are played, two incorrect and one correct. After this, an image asking the user to select which sound they think is correct is displayed on the LCD. The user is then informed whether they are incorrect or correct on another image. This is repeated twice more. At the end, the user is thanked and the number of correct answers displayed. 

{{/media/uploads/gotmilk/win_20161031_165735.jpg}}  


## Required parts 
The game uses an LCD, two SD cards (One for loading images on the LCD, another for loading sounds), a touchpad for input, and speaker with audio driver. The LCD and audio driver are powered by an external 5V power supply. \\
* MPR121 I2C Capacitive Touch Sensor with 2 4.7K pullup resistors
* uLCD-144-G2 128 by 128 Smart Color LCD
* TI TPA2005D1 Class D Audio Amp
* speaker
* 2 microSD cards
* mbed
* SparkFun microSD breakout board
* wires



=== uLCD wiring ===
| mbed | pin |
| ---- | --- |
|External 5V | +5V    |
|p27 | TX     |
|p28 | RX     |
|GND | GND    |
|p30 | RES    |
  
---
**NOTE**

One microSD card goes onto the uLCD itself. Image loading must be done using the 4D IDE graphical tool.

---

=== I2C Touchpad ===
| mbed | pin|
| ---- | -- |
|GND |GND |
|Vu |VCC |
|p9 | SDA|
|p10 | SCL|
|p26 | IRQ |
  
---
**NOTE**

SDA and SCL must be pulled up!

---

=== TI TPA2005D1 Class D Audio Amp ===
| mbed | pin | speaker|
| ---- | --- | ------ |
|GND | pwr-,in- | |
|External 5V | pwr+ | |
|p26 | in +| |
||out+ | + |
||out- | - |

=== SD card reader ===
| mbed| pin|
| --- | -- |
|GND|GND|
|VU|VCC|
|p8|CS|
|p5|DI|
|p6|DO|
|p7|SCK|

Mbed code at: https://developer.mbed.org/users/gotmilk/code/AnimalSoundGame/


### Video
[![Watch it in action!](https://img.youtube.com/vi/_tn-hKYD9F8/0.jpg)](https://www.youtube.com/watch?v=_tn-hKYD9F8)

