from SpriteData import SpriteData
from Screen import Screen

import time
import busio
import board
import adafruit_ssd1306

from PIL import Image, ImageDraw, ImageFont

class DisplayController:
    
    def __init__(self, i2c, width, height, font_fp, sprite_fp, anim_count, scr_count):
        self.oled_display = adafruit_ssd1306.SSD1306_I2C(width, height, i2c)
        self.oled_font = ImageFont.truetype(font_fp, 8)
        self.animation_count = anim_count
        self.screen_count = scr_count
        self.sprite_data = SpriteData(sprite_fp, anim_count)
        
        self.curr_screen_num = 0
        self.curr_mood = 0
        
        self.screens = []
        for i in range(0, self.screen_count):
            self.screens.append(Screen(width, height))
            self.screens[i].draw_text(i, self.oled_font)
        
        
        #Clear contents on OLED display
        self.oled_display.fill(0)
        self.oled_display.show()
        
        #self.animate()
        
    def animate(self):
        animation_frame = 0
        current_screen_num = -1
        
        while True:
            if current_screen_num != self.curr_screen_num:
                current_screen = self.screens[self.curr_screen_num].screen_img.copy()
                current_screen_num = self.curr_screen_num
            
            if animation_frame >= self.animation_count:
                animation_frame = 0

            current_frame = self.sprite_data.get_frame(self.curr_mood, animation_frame).copy()
            if (current_screen_num % 2 == 0):
                current_screen.paste(current_frame, box=(96,0))
            else:
                current_screen.paste(current_frame, box=(0,0))
            
            
            self.oled_display.image(current_screen)
            self.oled_display.show()
            animation_frame += 1
            time.sleep(0.1)
            
    
    def cleanup(self):
        self.oled_display.fill(0)
        self.oled_display.show()
    
    def change_screen(self, amount):
        self.curr_screen_num += amount
        if self.curr_screen_num >= self.screen_count:
            self.curr_screen_num = 0
        elif self.curr_screen_num < 0:
            self.curr_screen_num = self.screen_count - 1
            
    def change_mood(self):
        if self.curr_mood == 0:
            self.curr_mood = 1
        else:
            self.curr_mood = 0
