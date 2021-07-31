/*
 * Project Pet (debug)
 * Written By: Nolan Chan
 * Version 1.1
 * 
 * THIS PROGRAM IN PARTICULAR IS USED FOR DEBUGGING PURPOSES
 * THE ORIGINAL PROGRAM SIZE IS TOO LARGE TO BE USED FOR DEBUGGING
 * 
 * This project is an Arduino imitation of a "Tamagotchi" pet.
 * This project was designed with the following hardware choices in mind:
 * a 128x32 SSD1306 monochrome OLED display, a WS2812B LED strip (2 LED's long), and
 * two push buttons for user input.
 * 
 * The "pet" has the following stats that impact gameplay (detailed information about 
 * each stat can be found in the README file): hunger, happiness, sickness, discipline, 
 * age (along with a maxium age reached for scorekeeping), number of children, and amount 
 * of money had in hand.
 */


//Library for controlling LED strip
#include <Adafruit_NeoPixel.h>

//Libraries for I2C communication with OLED display
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//Library for reading and writing to EEPROM (non-volatile memory)
#include <EEPROM.h>

//Input pins for user interaction
#define BUTTON1   6
#define BUTTON2   9

//For LED strip
#define LED_PIN     15
#define LED_COUNT   2

//For OLED display
#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT 32


//Objects for controlling LED strip and OLED display
Adafruit_NeoPixel led_strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_SSD1306 oled_display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

//Arrays used to store monochrome bitmap sprites of "pet"
static const unsigned char PROGMEM normal_face[128] = {
    0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 
    0xff, 0xfc, 0x3f, 0xff, 
    0xff, 0xfc, 0x3f, 0xff, 
    0xfc, 0x33, 0xcc, 0x3f, 
    0xfc, 0x33, 0xcc, 0x3f, 
    0xfc, 0xcf, 0xf3, 0x3f, 
    0xfc, 0xcf, 0xf3, 0x3f, 
    0xfc, 0x3c, 0xfc, 0x3f, 
    0xfc, 0x3c, 0xfc, 0x3f, 
    0xfc, 0x03, 0xc0, 0x3f, 
    0xfc, 0x03, 0xc0, 0x3f, 
    0xf0, 0xf0, 0x0f, 0x0f, 
    0xf0, 0xf0, 0x0f, 0x0f, 
    0xc3, 0xff, 0xff, 0xc3, 
    0xcb, 0xff, 0xff, 0xe3, 
    0xcf, 0xff, 0xff, 0xf3, 
    0xcf, 0xff, 0xff, 0xf3, 
    0x0f, 0xff, 0xff, 0xf0, 
    0x2f, 0xff, 0xff, 0xf8, 
    0x3f, 0x3f, 0xcf, 0xf8, 
    0x3f, 0x3f, 0xcf, 0xf8, 
    0x03, 0x3f, 0xcc, 0x30, 
    0x03, 0x3f, 0xcc, 0x3c, 
    0x0f, 0xf0, 0xff, 0xd8, 
    0x2f, 0xf0, 0xff, 0xdc, 
    0x1b, 0xff, 0xfd, 0x38, 
    0x0f, 0xff, 0xff, 0xe0, 
    0xc5, 0x80, 0xed, 0xe3, 
    0xc2, 0x00, 0x01, 0x03, 
    0xf0, 0x00, 0x00, 0x0f, 
    0xf0, 0x00, 0x00, 0x0f
};

static const unsigned char PROGMEM normal_face1[128] = {
    0xff, 0xfc, 0x3f, 0xff, 
    0xff, 0xfc, 0x3f, 0xff, 
    0xfc, 0x33, 0xcc, 0x3f, 
    0xfc, 0x33, 0xcc, 0x3f, 
    0xfc, 0xcf, 0xf3, 0x3f, 
    0xfc, 0xcf, 0xf3, 0x3f, 
    0xfc, 0x3c, 0xfc, 0x3f, 
    0xfc, 0x3c, 0xfc, 0x3f, 
    0xfc, 0x03, 0x40, 0x3f, 
    0xfc, 0x03, 0xc0, 0x3f, 
    0xf3, 0xf0, 0x0f, 0x4f, 
    0xf3, 0xf0, 0x0f, 0xcf, 
    0xf3, 0xff, 0xff, 0xcf, 
    0xf3, 0xff, 0xff, 0xcf, 
    0xf3, 0xff, 0xff, 0xcf, 
    0xf3, 0xff, 0xff, 0xcf, 
    0xcf, 0xff, 0xff, 0xf3, 
    0xcf, 0xff, 0xff, 0xf3, 
    0xcf, 0x3f, 0xcf, 0xf3, 
    0xcf, 0x3f, 0xcf, 0xf3, 
    0xcf, 0x3f, 0xcf, 0xf3, 
    0xcf, 0x3f, 0xcf, 0xf3, 
    0xc0, 0xf0, 0xf0, 0xf3, 
    0xc0, 0xf0, 0xf0, 0xe3, 
    0xc7, 0xff, 0xff, 0xf3, 
    0xcf, 0xff, 0xff, 0xc3, 
    0xcb, 0xff, 0xff, 0xf3, 
    0xcf, 0xff, 0xff, 0xb3, 
    0xf3, 0xff, 0xfe, 0xcf, 
    0xf3, 0xff, 0xff, 0xcf, 
    0xfc, 0x00, 0x00, 0x3f, 
    0xfc, 0x00, 0x00, 0x3f
};

static const unsigned char PROGMEM normal_face2[128] = {
    0xfc, 0x33, 0xcc, 0x3f, 
    0xfc, 0x33, 0xcc, 0x3f, 
    0xfc, 0xcf, 0xf3, 0x3f, 
    0xfc, 0xcf, 0xf3, 0x3f, 
    0xfc, 0x3c, 0xfc, 0x3f, 
    0xfc, 0x3c, 0xfc, 0x3f, 
    0xfc, 0x03, 0x80, 0x3f, 
    0xfc, 0x03, 0xc0, 0x3f, 
    0xfc, 0xf0, 0x0f, 0x3f, 
    0xfc, 0xf0, 0x0f, 0x3f, 
    0xfc, 0xff, 0xff, 0x3f, 
    0xfc, 0xff, 0xff, 0x3f, 
    0xf3, 0xff, 0xff, 0x8f, 
    0xf3, 0xff, 0xff, 0xcf, 
    0xf3, 0x3f, 0xcf, 0xcf, 
    0xf3, 0x3f, 0xcf, 0xcf, 
    0xf3, 0x3f, 0xcf, 0xcf, 
    0xf3, 0x3f, 0xcf, 0xcf, 
    0xf0, 0xf0, 0xf0, 0xcf, 
    0xf0, 0xf0, 0xf0, 0xcf, 
    0xf3, 0xff, 0xff, 0xcf, 
    0xf3, 0xff, 0xff, 0xcf, 
    0xf3, 0xff, 0xff, 0xcf, 
    0xf3, 0xff, 0xff, 0xcf, 
    0xf3, 0xff, 0xff, 0xcf, 
    0xf3, 0xff, 0xff, 0xcf, 
    0xf0, 0xff, 0xff, 0x8f, 
    0xf3, 0xff, 0xff, 0x8f, 
    0xfc, 0x3f, 0xff, 0x3f, 
    0xfc, 0xaf, 0xff, 0x3f, 
    0xff, 0x00, 0x00, 0xff, 
    0xff, 0x00, 0x00, 0xff
};

static const unsigned char PROGMEM normal_face3[128] = {
    0xfc, 0xcf, 0xf3, 0x3f, 
    0xfc, 0xcf, 0xf3, 0x3f, 
    0xfc, 0x3c, 0xfc, 0x3f, 
    0xfc, 0x3c, 0xfc, 0x3f, 
    0xff, 0x03, 0x40, 0xff, 
    0xff, 0x03, 0xc0, 0xff, 
    0xff, 0x30, 0x30, 0xff, 
    0xff, 0x30, 0x20, 0xff, 
    0xfc, 0xff, 0xff, 0x3f, 
    0xfc, 0xff, 0xff, 0x3f, 
    0xf3, 0xff, 0xff, 0xcf, 
    0xf3, 0xff, 0xff, 0x4f, 
    0xf3, 0x3f, 0xcf, 0xcf, 
    0xf3, 0x3f, 0xcf, 0xcf, 
    0xf3, 0x3f, 0xcf, 0xcf, 
    0xf3, 0x3f, 0xcf, 0xcf, 
    0xc0, 0xf0, 0xf0, 0xf3, 
    0xc0, 0xf0, 0xf0, 0xc3, 
    0xcf, 0xff, 0xff, 0xf3, 
    0xcf, 0xff, 0xff, 0xf3, 
    0xcf, 0xff, 0xff, 0xf3, 
    0xcf, 0xff, 0xff, 0xf3, 
    0xcb, 0xff, 0xff, 0xf3, 
    0xcf, 0xff, 0xff, 0xf3, 
    0xcf, 0xff, 0xff, 0xf3, 
    0xc7, 0xff, 0xff, 0xe3, 
    0xcf, 0xff, 0xff, 0x73, 
    0xc7, 0xff, 0xff, 0xd3, 
    0xf3, 0xff, 0xfe, 0xcf, 
    0xf3, 0xff, 0xff, 0xcf, 
    0xfc, 0x00, 0x00, 0x3f, 
    0xfc, 0x00, 0x00, 0x3f
};

static const unsigned char PROGMEM normal_face4[128] = {
    0xfc, 0x33, 0xcc, 0x3f, 
    0xfc, 0x33, 0xcc, 0x3f, 
    0xfc, 0xcf, 0xf3, 0x3f, 
    0xfc, 0xcf, 0xf3, 0x3f, 
    0xfc, 0x3c, 0xfc, 0x3f, 
    0xfc, 0x3c, 0xfc, 0x3f, 
    0xff, 0x03, 0xc0, 0xff, 
    0xff, 0x03, 0xc0, 0xff, 
    0xff, 0xf0, 0x0f, 0xff, 
    0xff, 0xf0, 0x0f, 0xff, 
    0xff, 0x00, 0x00, 0xff, 
    0xff, 0x00, 0x00, 0xff, 
    0xf0, 0xff, 0xff, 0x0f, 
    0xf0, 0xff, 0xff, 0x0f, 
    0xcf, 0xff, 0xff, 0xf3, 
    0xcf, 0xff, 0xff, 0xf3, 
    0x3f, 0x3f, 0xcf, 0xfc, 
    0x1f, 0x3f, 0xcf, 0xfc, 
    0x3f, 0x3f, 0xcf, 0xfc, 
    0x3f, 0x3f, 0xcf, 0xfc, 
    0x7f, 0xff, 0xff, 0xff, 
    0x7f, 0xff, 0xff, 0xff, 
    0x0f, 0xf0, 0xff, 0x0f, 
    0x0f, 0xf0, 0xff, 0x0f, 
    0xff, 0xff, 0xff, 0xff, 
    0xbf, 0xff, 0xff, 0xff, 
    0xef, 0xff, 0xff, 0xdf, 
    0xff, 0xff, 0xff, 0xfb, 
    0x37, 0xff, 0xff, 0xfc, 
    0x3f, 0xff, 0xff, 0xfc, 
    0xc0, 0x00, 0x00, 0x03, 
    0xc0, 0x00, 0x00, 0x03
};

static const unsigned char PROGMEM happy_face[128] = {
    0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 
    0xff, 0xfc, 0x3f, 0xff, 
    0xff, 0xfc, 0x3f, 0xff, 
    0xfc, 0x33, 0xcc, 0x3f, 
    0xfc, 0x33, 0xcc, 0x3f, 
    0xfc, 0xcf, 0xf3, 0x3f, 
    0xfc, 0xcf, 0xf3, 0x3f, 
    0xfc, 0x3c, 0xfc, 0x3f, 
    0xfc, 0x3c, 0xfc, 0x3f, 
    0xfc, 0x03, 0xc0, 0x3f, 
    0xfc, 0x03, 0xc0, 0x3f, 
    0xf0, 0xf0, 0x0f, 0x0f, 
    0xf0, 0xf0, 0x0f, 0x0f, 
    0xc3, 0xff, 0xff, 0xc3, 
    0xcb, 0xff, 0xff, 0xe3, 
    0xcf, 0xff, 0xff, 0xf3, 
    0xcf, 0xff, 0xff, 0xf3, 
    0x0f, 0x3f, 0xcf, 0xf0, 
    0x2f, 0x3f, 0xcf, 0xf8, 
    0x3f, 0x3f, 0xcf, 0xf8, 
    0x3f, 0x3f, 0xcf, 0xf8, 
    0x03, 0x3f, 0xcc, 0x30, 
    0x03, 0x3f, 0xcc, 0x3c, 
    0x0f, 0xff, 0xff, 0xd0, 
    0x2f, 0xff, 0xff, 0xc8, 
    0x1b, 0xcf, 0x3d, 0x30, 
    0x0f, 0xcf, 0x3f, 0xf0, 
    0xc4, 0x40, 0x01, 0xe3, 
    0xc2, 0x80, 0x61, 0x13, 
    0xf0, 0x00, 0x00, 0x0f, 
    0xf0, 0x00, 0x00, 0x0f
};

static const unsigned char PROGMEM happy_face1[128] = {
    0xff, 0xfc, 0x3f, 0xff, 
    0xff, 0xfc, 0x3f, 0xff, 
    0xfc, 0x33, 0xcc, 0x3f, 
    0xfc, 0x33, 0xcc, 0x3f, 
    0xfc, 0xcf, 0xf3, 0x3f, 
    0xfc, 0xcf, 0xf3, 0x3f, 
    0xfc, 0x3c, 0xfc, 0x3f, 
    0xfc, 0x3c, 0xfc, 0x3f, 
    0xfc, 0x03, 0xc0, 0x3f, 
    0xfc, 0x03, 0xc0, 0x3f, 
    0xf0, 0xf0, 0x07, 0x0f, 
    0xf0, 0xf0, 0x0f, 0x0f, 
    0xf3, 0xff, 0xff, 0xcf, 
    0xf3, 0xff, 0xff, 0xcf, 
    0xf3, 0xff, 0xff, 0xcf, 
    0xf3, 0xff, 0xff, 0xcf, 
    0xcf, 0x3f, 0xcf, 0xf3, 
    0xcf, 0x3f, 0xcf, 0xf3, 
    0xcf, 0x3f, 0xcf, 0xf3, 
    0xcf, 0x3f, 0xcf, 0xf3, 
    0xcf, 0x3f, 0xcf, 0xf3, 
    0xcf, 0x3f, 0xcf, 0xf3, 
    0xc0, 0xff, 0xf0, 0xc3, 
    0xc0, 0xff, 0xf0, 0xc3, 
    0xc3, 0xcf, 0x3f, 0xc3, 
    0xc3, 0xcf, 0x3f, 0xc3, 
    0xc3, 0xf0, 0xff, 0x03, 
    0xc3, 0xf0, 0xff, 0x03, 
    0xf0, 0x00, 0x20, 0x0f, 
    0xf1, 0x40, 0x08, 0x0f, 
    0xfc, 0x00, 0x00, 0x3f, 
    0xfc, 0x00, 0x00, 0x3f
};

static const unsigned char PROGMEM happy_face2[128] = {
    0xfc, 0x33, 0xcc, 0x3f, 
    0xfc, 0x33, 0xcc, 0x3f, 
    0xfc, 0xcf, 0xf3, 0x3f, 
    0xfc, 0xcf, 0xf3, 0x3f, 
    0xfc, 0x3c, 0xfc, 0x3f, 
    0xfc, 0x3c, 0xfc, 0x3f, 
    0xfc, 0x03, 0xc0, 0x3f, 
    0xfc, 0x03, 0xc0, 0x3f, 
    0xfc, 0xf0, 0x07, 0x3f, 
    0xfc, 0xf0, 0x0f, 0x3f, 
    0xfc, 0xff, 0xff, 0x3f, 
    0xfc, 0xff, 0xff, 0x3f, 
    0xf0, 0x3f, 0xcf, 0x0f, 
    0xf0, 0x3f, 0xcf, 0x0f, 
    0xf3, 0x3f, 0xcf, 0xcf, 
    0xf3, 0x3f, 0xcf, 0xcf, 
    0xf3, 0x3f, 0xcf, 0xcf, 
    0xf3, 0x3f, 0xcf, 0xcf, 
    0xf0, 0xff, 0xf0, 0xcf, 
    0xf0, 0xff, 0xf0, 0xcf, 
    0xf3, 0xcf, 0x3f, 0xcf, 
    0xf3, 0xcf, 0x3f, 0xcf, 
    0xf3, 0xcf, 0x3f, 0xcf, 
    0xf3, 0xcf, 0x3f, 0xcf, 
    0xf3, 0xf0, 0xff, 0xcf, 
    0xf3, 0xf0, 0xff, 0xcf, 
    0xf0, 0xff, 0xff, 0x0f, 
    0xf0, 0xff, 0xff, 0x0f, 
    0xfc, 0x00, 0x00, 0x3f, 
    0xfc, 0x02, 0x00, 0x3f, 
    0xff, 0x00, 0x00, 0xff, 
    0xff, 0x00, 0x00, 0xff
};

static const unsigned char PROGMEM happy_face3[128] = {
    0xfc, 0xcf, 0xf3, 0x3f, 
    0xfc, 0xcf, 0xf3, 0x3f, 
    0xfc, 0x3c, 0xfc, 0x3f, 
    0xfc, 0x3c, 0xfc, 0x3f, 
    0xff, 0x03, 0xc0, 0xff, 
    0xff, 0x03, 0xc0, 0xff, 
    0xff, 0x00, 0x00, 0xff, 
    0xff, 0x00, 0x00, 0xff, 
    0xfc, 0x3f, 0xfc, 0x3f, 
    0xfc, 0x3f, 0xfd, 0x3f, 
    0xf3, 0xff, 0xff, 0x0f, 
    0xf3, 0xff, 0xff, 0x0f, 
    0xf3, 0x3f, 0xcf, 0xcf, 
    0xf3, 0x3f, 0xcf, 0xcf, 
    0xf3, 0x3f, 0xcf, 0xcf, 
    0xf3, 0x3f, 0xcf, 0xcf, 
    0xc0, 0xff, 0xf0, 0xc3, 
    0xc0, 0xff, 0xf0, 0xc3, 
    0xcf, 0xcf, 0x3f, 0xf3, 
    0xcf, 0xcf, 0x3f, 0xf3, 
    0xcf, 0xcf, 0x3f, 0xf3, 
    0xcf, 0xcf, 0x3f, 0xf3, 
    0xc3, 0xf0, 0xff, 0xe3, 
    0xc3, 0xf0, 0xff, 0xc3, 
    0xc7, 0xff, 0xff, 0xc3, 
    0xc3, 0xff, 0xff, 0xe3, 
    0xc7, 0xff, 0xff, 0x43, 
    0xc3, 0xff, 0xff, 0x03, 
    0xf0, 0x00, 0x00, 0x8f, 
    0xf1, 0x00, 0x00, 0x0f, 
    0xfc, 0x00, 0x00, 0x3f, 
    0xfc, 0x00, 0x00, 0x3f
};

static const unsigned char PROGMEM happy_face4[128] = {
    0xfc, 0x33, 0xcc, 0x3f, 
    0xfc, 0x33, 0xcc, 0x3f, 
    0xfc, 0xcf, 0xf3, 0x3f, 
    0xfc, 0xcf, 0xf3, 0x3f, 
    0xfc, 0x3c, 0xfc, 0x3f, 
    0xfc, 0x3c, 0xfc, 0x3f, 
    0xff, 0x03, 0xc0, 0xff, 
    0xff, 0x03, 0xc0, 0xff, 
    0xff, 0xf0, 0x0f, 0xff, 
    0xff, 0xf0, 0x0f, 0xff, 
    0xff, 0x00, 0x00, 0xff, 
    0xff, 0x00, 0x00, 0xff, 
    0xf0, 0xff, 0xff, 0x0f, 
    0xf0, 0xff, 0xff, 0x0f, 
    0xc3, 0xff, 0xff, 0xc3, 
    0xcb, 0xff, 0xff, 0xc3, 
    0x1f, 0x3f, 0xcf, 0xf0, 
    0x1f, 0x3f, 0xcf, 0xf0, 
    0x3f, 0x3f, 0xcf, 0xfc, 
    0x3f, 0x3f, 0xcf, 0xfc, 
    0x3f, 0xff, 0xff, 0xfc, 
    0x7f, 0xff, 0xff, 0xff, 
    0x0f, 0xcf, 0x3f, 0x0f, 
    0x0f, 0xcf, 0x3f, 0x0d, 
    0x3f, 0xf0, 0xff, 0xfd, 
    0xbf, 0xf0, 0xff, 0xfd, 
    0xef, 0xff, 0xff, 0xcf, 
    0xaf, 0xff, 0xff, 0xc8, 
    0x10, 0xf0, 0x08, 0xb4, 
    0x00, 0x00, 0x20, 0x08, 
    0xc0, 0x00, 0x00, 0x03, 
    0xc0, 0x00, 0x00, 0x03
};

//Global variables

//Variables for values stored in EEPROM
byte age;
byte max_age;
byte hunger;
byte happiness;
int bank_acc;
byte sickness;
byte discipline;
byte children_count;

//String values of byte values stored in EEPROM (used for display purposes)
String s_age;
String s_mage;
String s_bankacc;

//Variables used for reading user button presses
int last_button_state1 = HIGH;
int last_button_state2 = HIGH;
unsigned long last_debounce_time1 = 0;
unsigned long last_debounce_time2 = 0;
boolean primed1 = false;
boolean primed2 = false;
boolean can_prime = true;

//Variables used for user input for increasing discipline of "pet"
unsigned long d_count = 0;
unsigned long d_hit;
unsigned long hit_time;
boolean d_prime = false;

//Current screen of the program
byte screen = 0;

//Current animation frame of the "pet"
int animation_frame = 0;

//Used to keep track of the current state of the LED strip(what LEDs are on, and what color they are)
int led_frame = 0;      //For what LED's are on or off
int color_frame = 0;    //For "happy" mood
int n_color_frame = 0;  //For "normal" mood

//Arrays storing RGB rainbow color values for "happy" mood
static const byte red[7] = {255, 255, 255, 0, 0, 0, 153};
static const byte green[7] = {0, 102, 255, 255, 204, 0, 0};
static const byte blue[7] = {0, 0, 0, 0, 255, 255, 204};

//Array storing blue RGB values for "normal" mood
static const byte n_blue[5] = {0, 16, 80, 96, 128};


//Initialization code
void setup() {
  
  //Setup OLED display (some debug code is commented out in order to save program space)
  Serial.begin(115200);
  if(!oled_display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
    Serial.println("SSD1306 allocation failed");
    for(;;);
  }
  delay(2000);

  oled_display.clearDisplay();
  oled_display.setTextSize(1);
  oled_display.setTextColor(WHITE);
  
  //Setup LED strip
  led_strip.begin();
  led_strip.show();
  led_strip.setBrightness(128);

  //Setup buttons
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  
  //Setup random number generator
  randomSeed(analogRead(A0));
  long random_num;

  //Setup value for discipline input
  d_hit = random(20, 50);
  
  /* Wipe EEPROM memory (resets game and stats)
  for (int i = 0 ; i < EEPROM.length() ; i++) {
    EEPROM.write(i, 0);
  }
  */

  //Display changes from last session of "pet" program
  oled_display.drawBitmap(0, 0, happy_face, 32, 32, 1);
  oled_display.setCursor(34, 0);
  oled_display.print("Since Last Powe");
  oled_display.setCursor(34, 8);
  oled_display.print("GSICK:  AGEI: ");
  oled_display.setCursor(34, 16);
  oled_display.print("REPRODUCED: ");
  oled_display.setCursor(34, 24);
  oled_display.print("WAGE: $");

  //Decrease discipline level (varies on happiness level)
  discipline = EEPROM.read(7);
  happiness = EEPROM.read(3);
  byte d_decrement = double((1.0 - (double(happiness)/60.0))*10.0) + 2;
  decrementByte(&discipline, d_decrement);
  EEPROM.write(7, discipline);

  //Get age and update
  age = EEPROM.read(0);

  //Discipline stat affects if age increases for the session or not
  random_num = random(20);
  double a_chance = 1.0 - (double(discipline)/50.0) - 0.10;
  int a_c = a_chance * 20.0;  

  if(random_num >= a_c){
    //Increase age
    if(age < 99){
      age++;
      EEPROM.write(0, age);
    }
    oled_display.fillRect(112, 8, 8, 7, WHITE);
  }else{
    //Age was not increased
    oled_display.drawRect(112, 8, 8, 7, WHITE);
  }
  
  //Get max_age and update
  max_age = EEPROM.read(1);
  if(age > max_age){
    max_age = age;
    EEPROM.write(1, max_age);
  }

  //Update sickness (chance of pet becoming sick depends on hunger level)
  hunger = EEPROM.read(2);
  sickness = EEPROM.read(6);

  //If the pet is not already sick
  if(sickness == 0){
    random_num = random(20);
    double s_chance = 1.0 - (double(hunger)/90.0) - 0.20;
    int s_c = s_chance * 20.0;
    
    if(random_num < s_c){
      //If pet gets sick
      oled_display.fillRect(70, 8, 8, 7, WHITE);
      sickness = 1;
      EEPROM.write(6, sickness);
    }else{
      //If pet stays healthy
      oled_display.drawRect(70, 8, 8, 7, WHITE);
    }
  }else{
    oled_display.drawRect(70, 8, 8, 7, WHITE);
  }

  //Update children count
  children_count = EEPROM.read(8);

  //"pet" only has a chance of reproducing if its over the age of 18
  if(age > 18){
    random_num = random(10);
    
    if(random_num == 0){
      //If pet reproduces
      children_count++;

      //Max children count is 3
      if(children_count > 3){
        children_count = 3;
      }

      oled_display.fillRect(100, 16, 10, 7, WHITE);
    }else{
      //If pet does not reproduce
      oled_display.drawRect(100, 16, 10, 7, WHITE);
    }
  }else{
    oled_display.drawRect(100, 16, 10, 7, WHITE);
  }
  EEPROM.write(8, children_count);


  //Update hunger
  //Decrease hunger by a random amount
  random_num = random(10);

  byte h_decrease;
  if(random_num == 0){
    h_decrease = 25;
  }else if(random_num == 1 || random_num == 2){
    h_decrease = 20;
  }else if(random_num == 3 || random_num == 4){
    h_decrease = 15;
  }else if(random_num >= 5 && random_num <= 7){
    h_decrease = 10;
  }else if(random_num == 8 || random_num == 9){
    h_decrease = 5;
  }

  //If pet is sick, hunger depletion is increased by 1.3 times
  if(sickness == 1){
    h_decrease = (double(h_decrease) * 1.3);
  }
  
  decrementByte(&hunger, h_decrease);
  EEPROM.write(2, hunger);

  
  //Update happiness
  //Change hunger by a random amount
  random_num = random(10);

  byte ha_decrease = 0;
  if(random_num == 0){
    ha_decrease = 15;
  }else if(random_num >= 1 && random_num <= 3){
    ha_decrease = 10;
  }else if(random_num >= 4 && random_num <= 6){
    ha_decrease = 5;
  }else if(random_num == 7 || random_num == 8){
    happiness += 5;

    //Max happiness value is 60
    if(happiness > 60){
      happiness = 60;
    }
  }

  //If pet is sick, happiness depletion is increased by 1.5 times
  if(sickness == 1){
    ha_decrease = (double(ha_decrease) * 1.5);
  }
  if(ha_decrease != 0){
    decrementByte(&happiness, ha_decrease);
  }
  EEPROM.write(3, happiness);


  //Get bank account and update
  bank_acc = int((EEPROM.read(4) << 8) + EEPROM.read(5));

  //Increase bank account by random amount
  random_num = random(10);

  byte b_increase = 0;
  if(random_num == 0){
    b_increase = 5;
  }else if(random_num >= 1 && random_num <= 4){
    b_increase = 10;
  }else{
    b_increase = 15;
  }

  bank_acc += b_increase;

  //Max bank account value is 999
  if(bank_acc >= 1000){
    bank_acc = 999;
  }

  //Display amount earned for the session to the beginning screen
  String w = String(b_increase) + ".00";
  oled_display.print(w);

  EEPROM.write(4, bank_acc >> 8);
  EEPROM.write(5, bank_acc & 0xFF);

  //If "pet" has died, reset game
  if(hunger == 0){
    //Reset age
    EEPROM.write(0, 0);
    //Reset hunger
    EEPROM.write(2, 90);
    //Reset happiness
    EEPROM.write(3, 60);
    //Reset bank account
    unsigned int b_acc = 50;
    EEPROM.write(4, b_acc >> 8);
    EEPROM.write(5, b_acc & 0xFF);
    //Reset sickness
    EEPROM.write(6, 0);
    //Reset discipline
    EEPROM.write(7, 50);
    //Reset children
    EEPROM.write(8, 0);
  }

  //Cast age and max age values as Strings to be displayed on OLED display
  s_age = String(age);
  s_mage = String(max_age);

  oled_display.display();
  delay(5000);
}

void loop() {
  //The multiplier to the cost of food, food is more expensive the more children there are
  byte cost_multiplier = 1 + children_count;

  //Handle user inputs
  //Read user input from BUTTON1 and handle debounce
  int reading = digitalRead(BUTTON1);
  if(reading != last_button_state1){
    last_debounce_time1 = millis();
    can_prime = true;
  }
  if((millis() - last_debounce_time1) > 100){
    if((millis() - last_debounce_time1) > 1000){
      //If user held BUTTON1 for more than 1 second, change screen by 1 forward
      if(reading == LOW){
        //Disable short press functionality for the button if button is held
        primed1 = false;
        can_prime = false;
        
        screen++;
        if(screen > 2){
          screen = 0;
        }        
      }
      last_debounce_time1 = millis();
    }else if(reading == LOW && can_prime){
      //"Prime" BUTTON1 for short press functionality
      primed1 = true;
    }
  }

  //If BUTTON1 is "primed" and the button is let go
  if(primed1 == true && reading == HIGH){
    primed1 = false;

    //If on screen 0, feed pet "candy" if user can afford and pet is not dead
    if(screen == 0 && bank_acc >= (5*cost_multiplier) && hunger != 0){
      //Feed candy to "pet" and update stats
      bank_acc -= (5*cost_multiplier);
      hunger += 3;
      happiness += 10;
      if(hunger > 90){
        hunger = 90;
      }
      if(happiness > 60){
        happiness = 60;
      }
      
      EEPROM.write(2, hunger);
      EEPROM.write(3, happiness);
      EEPROM.write(4, bank_acc >> 8);
      EEPROM.write(5, bank_acc & 0xFF);
      
      flashDisplay();
    }else if(screen == 1 && bank_acc >= 30 && hunger != 0){
      //If on screen 1, feed pet medicine to cure sickness if user can afford and pet is not dead
      bank_acc -= 30;
      sickness = 0;
      EEPROM.write(6, sickness);
      flashDisplay();
    }    
  }
  last_button_state1 = reading;

  //Read user input for BUTTON2 and handle debounce
  reading = digitalRead(BUTTON2);
  if(reading != last_button_state2){
    last_debounce_time2 = millis();
    can_prime = true;
  }
  if((millis() - last_debounce_time2) > 100){
    if((millis() - last_debounce_time2) > 1000){
      //If user held button for more than 1 second, change screen by one backward
      if(reading == LOW){
        //Disable short press functionality if button is held
        primed2 = false;
        can_prime = false;

        if(screen == 0){
          screen = 2;
        }else{
          screen--;
        }

        last_debounce_time2 = millis();
      }
    }else if(reading == LOW && can_prime){
      //"Prime" BUTTON2 for short press functionality
      primed2 = true;

      //Handle user input for increasing discipline of "pet"
      if(d_prime == true && hunger != 0){
        //"Unprime" the discipline increase and the regular short press functionality of BUTTON2
        d_prime = false;
        primed2 = false;

        //Amount of discipline increase is based upon how quickly after BUTTON2 is pressed after the flash
        long diff = millis() - hit_time;
        if(diff > 1000){
          diff = 1000;
        }
        diff = 1000 - diff;
        double d_increase = double(diff)/1000.0*20.0;
        discipline += byte(d_increase);

        //Maximum discipline value is 50
        if(discipline > 50){
          discipline = 50;
        }
        EEPROM.write(7, discipline);
  
        flashDisplay();
      }
    }
  }

  //If BUTTON2 is "primed" and it is let go
  if(primed2 == true && reading == HIGH){
    primed2 = false;

    //If user is on screen 0, feed pet "salad" only if user can afford and pet is not dead
    if(screen == 0 && bank_acc >= (3*cost_multiplier) && hunger != 0){
      //Feed salad to "pet" and update stats
      bank_acc -= (3*cost_multiplier);
      hunger += 9;
      if(hunger > 90){
        hunger = 90;
      }
      decrementByte(&happiness, 2);
      
      EEPROM.write(2, hunger);
      EEPROM.write(3, happiness);
      EEPROM.write(4, bank_acc >> 8);
      EEPROM.write(5, bank_acc & 0xFF);

      flashDisplay();
    } 
  }
  last_button_state2 = reading;


  //Display menu information for the current screen (not including "pet")
  //Cast current bank account value to strip to a String to display on OLED
  String s_bankacc = String(bank_acc);

  //Clear display and display text for current stats
  oled_display.clearDisplay();

  //x coordinate of where to draw "pet"
  int x_coord = 0;
  if(screen == 0){
    //If on screen 0, display relevant information
    x_coord = 96;
    
    oled_display.setCursor(0, 0);
    oled_display.println("HUNGER: \nHAPPINESS: ");
    oled_display.println("BANK: $" + s_bankacc + ".00");
    oled_display.println("AGE: " + s_age + " MAGE: " + s_mage);

    //Display hunger bar on OLED display
    byte t_hunger = hunger;
    int i = 42;
    while(i <= 90){
      oled_display.fillRoundRect(i, 0, 5, 7, 1, WHITE);
  
      i += 6;
      if(t_hunger <= 10){
        break;
      }
      t_hunger -= 10;
    }
    while(i <= 90){
      oled_display.drawRoundRect(i, 0, 5, 7, 1, WHITE);
      
      i += 6;
    }
  
    //Display happiness bar on OLED display
    byte t_happiness = happiness;
    i = 61;
    while(i <= 91){
      if(t_happiness <= 0){
        break;
      }
      oled_display.fillCircle(i, 11, 2, WHITE);
  
      i += 6;
      if(t_happiness < 10){
        break;
      }
      t_happiness -= 10;
    }
    while(i <= 91){
      oled_display.drawCircle(i, 11, 2, WHITE);
  
      i += 6;
    }
  }else if(screen == 1){
    //If on screen 1, display relevant information
    oled_display.setCursor(34, 0);
    oled_display.print("IS SICK: ");
    oled_display.setCursor(34, 8);
    oled_display.print("DISCIPLINE: ");
    oled_display.setCursor(34, 16);
    oled_display.print("BANK: $" + s_bankacc + ".00");
    oled_display.setCursor(34, 24);
    oled_display.print("CHILDREN: ");

    //Display children count on OLED display
    byte t_children = children_count;
    int j = 90;
    while(j <= 102){
      if(t_children <= 0){
        break;
      }
      oled_display.fillCircle(j, 27, 2, WHITE);
  
      j += 6;
      t_children--;
    }
    while(j <= 102){
      oled_display.drawCircle(j, 27, 2, WHITE);
  
      j += 6;
    }

    //Display bar to show if "pet" is sick or not
    if(sickness == 0){
      oled_display.drawRoundRect(82, 0, 46, 7, 1, WHITE);
    }else{
      oled_display.fillRoundRect(82, 0, 46, 7, 1, WHITE);
    }

    //Display bar to show discipline level of pet
    oled_display.drawRoundRect(100, 8, 28, 7, 1, WHITE);
    double disci = double(discipline)/50.0 * 28.0;
    int i_disci = int(disci);
    oled_display.fillRoundRect(100, 8, i_disci, 7, 1, WHITE);

    //Handle discipline input
    if(d_count == d_hit && hunger != 0){
      //If d_count reaches d_hit, flash screen and "prime" input for discipline increase
      flashDisplay();
      hit_time = millis();
      d_prime = true;
    }
    d_count++;
  }else if(screen == 2){
    //If on screen 2, show relevant information (about screen)
    x_coord = 96;

    oled_display.setCursor(0, 0);
    oled_display.println("BY: NOLAN CHAN\nVERSION: 1.1\nREPO: github.com\n/NolanChan1/projectpet");
  }
  

  //Determine mood
  double mood = double(happiness)/60.0*0.70 + double(hunger)/80.0*0.30;

  //Display "pet" on OLED and colors/state of LED strip
  if(hunger == 0){
    //Display dead "pet" on OLED
    oled_display.drawBitmap(x_coord, 0, happy_face, 32, 32, 1);
    
    //Display red flashing (one frame) on LED strip
    if(led_frame % 2 == 0){
      led_strip.setPixelColor(0, 0, 0, 0);
      led_strip.setPixelColor(1, 0, 0, 0);
    }else{
      led_strip.setPixelColor(0, 128, 0, 0);
      led_strip.setPixelColor(1, 128, 0, 0);
    }    
  }else if(sickness == 1){
    //Display sick "pet" on OLED
    oled_display.drawBitmap(x_coord, 0, happy_face, 32, 32, 1);

    //Display pink flashing on LED strip
    if(led_frame == 0){
      led_strip.setPixelColor(0, 0, 0, 0);
      led_strip.setPixelColor(1, 0, 0, 0);
    }else{
      led_strip.setPixelColor(0, 153, 0, 204);
      led_strip.setPixelColor(1, 153, 0, 204);
    }
  }else if(mood >= 0.8){
    //Display happy "pet" on OLED
    if(animation_frame == 0){
      oled_display.drawBitmap(x_coord, 0, happy_face, 32, 32, 1);
    }else if(animation_frame == 1){
      oled_display.drawBitmap(x_coord, 0, happy_face1, 32, 32, 1);
    }else if(animation_frame == 2){
      oled_display.drawBitmap(x_coord, 0, happy_face2, 32, 32, 1);
    }else if(animation_frame == 3){
      oled_display.drawBitmap(x_coord, 0, happy_face3, 32, 32, 1);
    }else if(animation_frame == 4){
      oled_display.drawBitmap(x_coord, 0, happy_face4, 32, 32, 1);
    }

    //Display rainbow (one frame) on LED strip
    if(led_frame % 2 == 0){
      led_strip.setPixelColor(0, red[color_frame], green[color_frame], blue[color_frame]);
      led_strip.setPixelColor(1, 0, 0, 0);
    }else{
      led_strip.setPixelColor(0, 0, 0, 0);
      led_strip.setPixelColor(1, red[color_frame], green[color_frame], blue[color_frame]);
    }

    //Update color_frame
    color_frame++;
    if(color_frame > 6){
      color_frame = 0;
    }
  }else if(mood < 0.8){
    //Display normal "pet" on OLED
    if(animation_frame == 0){
      oled_display.drawBitmap(x_coord, 0, normal_face, 32, 32, 1);
    }else if(animation_frame == 1){
      oled_display.drawBitmap(x_coord, 0, normal_face1, 32, 32, 1);
    }else if(animation_frame == 2){
      oled_display.drawBitmap(x_coord, 0, normal_face2, 32, 32, 1);
    }else if(animation_frame == 3){
      oled_display.drawBitmap(x_coord, 0, normal_face3, 32, 32, 1);
    }else if(animation_frame == 4){
      oled_display.drawBitmap(x_coord, 0, normal_face4, 32, 32, 1);
    }

    //Display blue pulse (one frame) on LED strip
    if(led_frame == 0){
      led_strip.setPixelColor(0, 0, 128, n_blue[n_color_frame]);
      led_strip.setPixelColor(1, 0, 0, 0);
    }else if(led_frame == 1){
      led_strip.setPixelColor(1, 0, 128, n_blue[n_color_frame]);
    }else if(led_frame == 2){
      led_strip.setPixelColor(0, 0, 0, 0);
    }else if(led_frame == 3){
      led_strip.setPixelColor(0, 0, 128, n_blue[n_color_frame]);
    }

    //Update n_color_frame;
    n_color_frame++;
    if(n_color_frame > 4){
      n_color_frame = 0;
    }
  }

  
  oled_display.display();
  led_strip.show();

  //Update animation_frame and led_frame
  animation_frame++;
  if(animation_frame > 4){
    animation_frame = 0;
  }

  led_frame++;
  if(led_frame > 3){
    led_frame = 0;
  }

  delay(100);
}

//Function used to flash the OLED display giving feedback for user input
void flashDisplay(){
  oled_display.invertDisplay(true);
  oled_display.display();
  delay(150);
  
  oled_display.invertDisplay(false);
  oled_display.display();
}

//Function used to decrement a byte value so it does not overflow
void decrementByte(byte* value, byte decrement_value){
  if(*value < decrement_value){
    *value = 0;
  }else{
    *value = *value - decrement_value;
  }
}
