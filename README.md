# PROJECT PET (WIP)
An Tamagotchi imitation of sorts developed initially on Arduino, and which is currently being ported to work on a Raspberry Pi.
This project makes use of the following pieces of hardware: a 128x32 SSD1306 monochrome OLED display, a WS2812B LED strip, 
two passive piezoelectric buzzers (Raspberry Pi version only), and two(Arduino)/four(Raspberry Pi) push buttons for user input.
 

## MOTIVATION
Initially for me to play around with the Arduino Pro Micro, and other pieces of hardware (e.x. monochrome I2C OLED display)
that I bought initially for a keyboard macro project. The Raspberry Pi port is being worked on as a way for me to get some 
hands-on practice designing and developing a small object-oriented software project and to learn Python.


## DEMO
The following YouTube video shows a demo of an early version of the Raspberry Pi port running (please excuse the poor video/audio
quality).
https://www.youtube.com/watch?v=8HMey3eF_vQ


## DEPENDENCIES
### ARDUINO
- Adafruit GFX and SSD1306 libraries, and Arduino Wire library for controlling SSD1306 display
- Adafruit Neopixel library for controlling LED strip
- Arduino EEPROM library for storing save data

### RASPBERRY PI
- Pandas library for managing CSV files (save data)
- Adafruit CircuitPython NeoPixel library for controlling LED strip
- Adafruit CircuitPython SSD1306 library for controlling SSD1306 display
- Pillow library for supplying "images" to Adafruit CircuitPython SSD1306 library

## TODO
- Documentation
- Finish porting features from Arduino to Raspberry Pi version
- Add "gaming" features to Raspberry Pi version


## IMPORTANT NOTES
THE PET SPRITES/FONT/MUSIC IN THIS REPOSITORY ARE NOT MINE. THE PET SPRITES IN PARTICULAR WERE TAKEN AND MODIFIED FROM TERRARIA
(SLIME AND BEE) AND STARDEW VALLEY (CHICKEN). THE MUSIC IN THE RASPBERRY PI VERSION IS FROM STARDEW VALLEY (OVERTURE) AND THE 
FONT WAS DOWNLOADED FROM: https://www.dafont.com/minecraftia.font.

