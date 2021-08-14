from PIL import Image, ImageDraw, ImageFont

class Screen:
    def __init__(self, width, height):
        self.screen_img = Image.new("1", (width, height))
        self.screen_draw = ImageDraw.Draw(self.screen_img)
        
    def draw_text(self, screen_type, screen_font):
        if screen_type == 0:
            self.screen_draw.text((0, -2), "HUNGER:", font=screen_font, fill=255)
            self.screen_draw.text((0, 6), "HAPPINESS:", font=screen_font, fill=255)
            self.screen_draw.text((0, 14), "SALAD:", font=screen_font, fill=255)
            self.screen_draw.text((0, 22), "CANDY:", font=screen_font, fill=255)
        elif screen_type == 1:
            self.screen_draw.text((33, -2), "SALAD:", font=screen_font, fill=255)
            self.screen_draw.text((33, 6), "CANDY:", font=screen_font, fill=255)
            self.screen_draw.text((33, 14), "MARKET:", font=screen_font, fill=255)
            self.screen_draw.text((33, 22), "BANK:", font=screen_font, fill=255)
        elif screen_type == 2:
            self.screen_draw.text((0, -2), "SICKNESS:", font=screen_font, fill=255)
            self.screen_draw.text((0, 6), "RECOVERY:", font=screen_font, fill=255)
            self.screen_draw.text((0, 14), "MEDICINE:", font=screen_font, fill=255)
            self.screen_draw.text((0, 22), "BANK:", font=screen_font, fill=255)
        elif screen_type == 3:
            self.screen_draw.text((33, -2), "CHILDREN:", font=screen_font, fill=255)
            self.screen_draw.text((33, 6), "CHILD_INC:", font=screen_font, fill=255)
            self.screen_draw.text((33, 14), "WAGE:", font=screen_font, fill=255)
            self.screen_draw.text((33, 22), "DISCIPLINE:", font=screen_font, fill=255)
        elif screen_type == 4:
            self.screen_draw.text((0, -2), "AGE:", font=screen_font, fill=255)
            self.screen_draw.text((0, 6), "MAX AGE:", font=screen_font, fill=255)
            self.screen_draw.text((0, 14), "DAYS:", font=screen_font, fill=255)
            self.screen_draw.text((0, 22), "TOTAL TRIES:", font=screen_font, fill=255)
        elif screen_type == 5:
            self.screen_draw.text((33, -2), "BY: NOLAN CHAN", font=screen_font, fill=255)
            self.screen_draw.text((33, 6), "VERSION: ALPHA", font=screen_font, fill=255)
            self.screen_draw.text((33, 14), "github.com/Nolan", font=screen_font, fill=255)
            self.screen_draw.text((33, 22), "Chan1/projectpet", font=screen_font, fill=255)
    
    def print_stats(self, screen_type, stats, misc_sprites, screen_font):
        if screen_type == 0:
            filled_hungerbars = int(stats[0]/10)
            filled_happybars = int(stats[1]/10)
            
            total_hungerbars = 9
            total_happybars = 6
            
            saladbars = stats[2]
            candybars = stats[3]
            
            for i in range(0, filled_hungerbars):
                self.screen_draw.rounded_rectangle((40 + i*6, 0, 44 + i*6, 6), radius=1, outline=255, fill=255)
                total_hungerbars -= 1
                
            for i in range(0, total_hungerbars):
                self.screen_draw.rounded_rectangle((88 - i*6, 0, 92 - i*6, 6), radius=1, outline=255, fill=0)
            
            for i in range(0, filled_happybars):
                self.screen_img.paste(misc_sprites[0], box=(55 + i*6, 8))
                total_happybars -= 1
                
            for i in range(0, total_happybars):
                self.screen_img.paste(misc_sprites[1], box=(85 - i*6, 8))
                
            for i in range(0, saladbars):
                self.screen_img.paste(misc_sprites[2], box=(32 + i*8, 16))
                
            for i in range(0, candybars):
                self.screen_img.paste(misc_sprites[3], box=(32 + i*7, 24))
            """
            for i in range(0, filled_happybars):
                self.screen_draw.ellipse((54 + i*7, 9, 59 + i*7, 14), outline=255, fill=255, width=1)
                total_happybars -= 1
                
            for i in range(0, total_happybars):
                self.screen_draw.ellipse((89 - i*7, 9, 94 - i*7, 14), outline=255, fill=0, width=1)
            """
        elif screen_type == 1:
            saladbars = stats[2]
            candybars = stats[3]
            
            bank_acc = str(round(stats[4], 2))
            
            for i in range(0, saladbars):
                self.screen_img.paste(misc_sprites[0], box=(65 + i*8, 0))
                
            for i in range(0, candybars):
                self.screen_img.paste(misc_sprites[1], box=(65 + i*7, 8))
                
            self.screen_draw.text((65, 22), "$ " + bank_acc, font=screen_font, fill=255)
        elif screen_type == 2:
            medicinebars = stats[7]
            
            bank_acc = str(round(stats[4], 2))
            
            for i in range(0, medicinebars):
                self.screen_img.paste(misc_sprites[0], box=(46 + i*6, 16))
                
            self.screen_draw.text((32, 22), "$ " + bank_acc, font=screen_font, fill=255)
        elif screen_type == 3:
            childrenbars = stats[8]
            
            for i in range(0, childrenbars):
                self.screen_img.paste(misc_sprites[0], box=(83 + i*10, 0))
            
