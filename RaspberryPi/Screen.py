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
            self.screen_draw.text((33, 6), "PREGNANT:", font=screen_font, fill=255)
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
