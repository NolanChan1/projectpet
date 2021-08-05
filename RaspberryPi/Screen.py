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
            
