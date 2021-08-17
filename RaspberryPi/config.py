#Configuration file for ProjectPet

import board

#BCM pin numbers for GPIO button and buzzer pins
BUTTON1_PIN = 26
BUTTON2_PIN = 6
BUTTON3_PIN = 5
BUTTON4_PIN = 25

BUZZER1_PIN = 14
BUZZER2_PIN = 15

#Width and height in pixels of OLED display
OLED_WIDTH = 128
OLED_HEIGHT = 32

#Filepath of font to use on OLED display
FONT_FP = "assets/font/Minecraftia-Regular.ttf"

#Filepath of directory containing sprites to use on OLED display
SPRITE_FP = "assets/"

#Number of pet sprites per animation cycle
ANIMATION_COUNT = 8

SCREEN_COUNT = 6

SAVE_FP = "saves/pet_save.csv"

MUSIC_FP1 = "assets/music/stardew_overture0.txt"
MUSIC_FP2 = "assets/music/stardew_overture1.txt"
TEMPO = 2.5

LED_PIN = board.D21
NUM_LED = 3
LED_BRIGHTNESS = 0.2
LED_DELAY = 0.1
LED_FP = "assets/led_colours/led0.txt"

START_HUNGER = 50
START_HAPPINESS = 50
START_SALAD = 2
START_CANDY = 2
START_BANK = 10.55
START_SICK = 0
START_RECOVERY = 0
START_MEDICINE = 2
START_CHILDREN = 1
START_CHILD_INC = 0
START_DISCIPLINE = 50
START_BASEWAGE = 15.00
START_BASEMARKET = 10
START_AGE = 0


