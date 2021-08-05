from PIL import Image, ImageDraw, ImageFont

class Screen:
    def __init__(self, width, height):
        self.screen_img = Image.new("1", (width, height))
        self.screen_draw = ImageDraw.Draw(self.screen_img)
        
    def draw_text(self, screen_type, screen_font):
        if screen_type == 0:
            self.screen_draw.text((0, -1), "HUNGER:", font=screen_font, fill=255)
            self.screen_draw.text((0, 7), "HAPPINESS:", font=screen_font, fill=255)
            self.screen_draw.text((0, 15), "SALAD:", font=screen_font, fill=255)
            self.screen_draw.text((0, 23), "CANDY:", font=screen_font, fill=255)
        elif screen_type == 1:
            self.screen_draw.text((32, -1), "SALAD:", font=screen_font, fill=255)
            self.screen_draw.text((32, 7), "CANDY:", font=screen_font, fill=255)
            self.screen_draw.text((32, 15), "MARKET:", font=screen_font, fill=255)
            self.screen_draw.text((32, 23), "BANK:", font=screen_font, fill=255)
        elif screen_type == 2:
            self.screen_draw.text((0, -1), "SICKNESS:", font=screen_font, fill=255)
            self.screen_draw.text((0, 7), "RECOVERY:", font=screen_font, fill=255)
            self.screen_draw.text((0, 15), "MEDICINE:", font=screen_font, fill=255)
            self.screen_draw.text((0, 23), "BANK:", font=screen_font, fill=255)
        elif screen_type == 3:
            self.screen_draw.text((32, -1), "CHILDREN:", font=screen_font, fill=255)
            self.screen_draw.text((32, 7), "PREGNANT:", font=screen_font, fill=255)
            self.screen_draw.text((32, 15), "WAGE:", font=screen_font, fill=255)
            self.screen_draw.text((32, 23), "DISCIPLINE:", font=screen_font, fill=255)
        elif screen_type == 4:
            self.screen_draw.text((0, -1), "AGE:", font=screen_font, fill=255)
            self.screen_draw.text((0, 7), "MAX AGE:", font=screen_font, fill=255)
            self.screen_draw.text((0, 15), "DAYS:", font=screen_font, fill=255)
            self.screen_draw.text((0, 23), "TOTAL TRIES:", font=screen_font, fill=255)
        elif screen_type == 5:
            self.screen_draw.text((0, -1), "BY: NOLAN CHAN", font=screen_font, fill=255)
            self.screen_draw.text((0, 7), "VERSION: ALPHA", font=screen_font, fill=255)
            self.screen_draw.text((0, 15), "REPO: github.com/", font=screen_font, fill=255)
            self.screen_draw.text((0, 23), "NolanChan1/projectpet", font=screen_font, fill=255)
