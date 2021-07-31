
from PIL import Image, ImageDraw, ImageFont

class SpriteData:
    
    def __init__(self, sprite_fp, anim_count):
        self.pet_normal_sprites = []
        
        for i in range(0, anim_count):
            img_fp = sprite_fp + "pet_normal" + i + ".pbm"
            img = Image.open(img_fp)
            self.pet_normal_sprites.append(img)
            
    def get_frame(self, mood, frame):
        if mood == 0:
            return self.pet_normal_sprites[frame]