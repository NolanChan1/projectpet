from SpriteData import SpriteData
from Screen import Screen

import time
import busio
import board
import adafruit_ssd1306

from PIL import Image, ImageDraw, ImageFont

class DisplayController:
    
    def __init__(self, i2c, width, height, font_fp, sprite_fp, anim_count):
        self.oled_display = adafruit_ssd1306.SSD1306_I2C(width, height, i2c)
        self.oled_font = ImageFont.truetype(font_fp, 8)
        self.animation_count = anim_count
        self.sprite_data = SpriteData(sprite_fp, anim_count, width, height)
        self.screens = []
        self.screens.append(Screen(width, height))
        self.screens[0].draw_text(0, oled_font)
        
        #Clear contents on OLED display
        oled_display.fill(0)
        oled_display.show()
        
        self.animate()
        
    def animate():
        animation_frame = 0
        current_screen = self.screens[0].screen_img.copy()
        while True:
            current_frame = sprite_data.get_frame(0, animation_frame).copy()
            current_screen.paste(current_frame, box=(0,0))
            
            self.oled_display.image(current_screen)
            self.oled_display.show()
            animation_frame += 1
            time.sleep(0.1)
            
    