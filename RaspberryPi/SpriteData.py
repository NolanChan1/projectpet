
from PIL import Image, ImageDraw, ImageFont

class SpriteData:
    
    def __init__(self, sprite_fp, anim_count):
        self.pet_normal_sprites = []
        self.pet_happy_sprites = []
        self.pet_extra_sprite = Image.open(sprite_fp + "pet_extra.pbm")
        self.pet_sick_sprite = Image.open(sprite_fp + "pet_sick.pbm")
        self.pet_dead_sprite = Image.open(sprite_fp + "pet_dead.pbm")
        
        for i in range(0, anim_count):
            nimg_fp = sprite_fp + "pet_normal" + str(i) + ".pbm"
            nimg = Image.open(nimg_fp)
            self.pet_normal_sprites.append(nimg)
            
            himg_fp = sprite_fp + "pet_happy" + str(i) + ".pbm"
            himg = Image.open(himg_fp)
            self.pet_happy_sprites.append(himg)
            
    def get_frame(self, mood, frame):
        if mood == 0:
            return self.pet_normal_sprites[frame]
        elif mood == 1:
            return self.pet_happy_sprites[frame]
        elif mood == 10:
            return self.pet_extra_sprite
        elif mood == 11:
            return self.pet_sick_sprite
        elif mood == 12:
            return self.pet_dead_sprite
