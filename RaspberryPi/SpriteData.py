from PIL import Image, ImageDraw, ImageFont

class SpriteData:
    
    def __init__(self, sprite_fp, anim_count):
        self.pet_normal_sprites = []
        self.pet_happy_sprites = []
        self.pet_extra_sprite = Image.open(sprite_fp + "pet_extra.pbm")
        self.pet_sick_sprite = Image.open(sprite_fp + "pet_sick.pbm")
        self.pet_dead_sprite = Image.open(sprite_fp + "pet_dead.pbm")
        
        self.happinessbar_empty = Image.open(sprite_fp + "happinessbar_empty.pbm")
        self.happinessbar_full = Image.open(sprite_fp + "happinessbar_full.pbm")
        self.food_salad = Image.open(sprite_fp + "food_salad0.pbm")
        self.food_candy = Image.open(sprite_fp + "food_candy0.pbm")
        self.pet_child = Image.open(sprite_fp + "pet_child0.pbm")
        self.medicine_pill = Image.open(sprite_fp + "medicine_pill.pbm")
        
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
            
    def get_misc_sprites(self, screen):
        if screen == 0:
            return [self.happinessbar_full, self.happinessbar_empty, self.food_salad, self.food_candy]
        elif screen == 1:
            return [self.food_salad, self.food_candy]
        elif screen == 2:
            return [self.medicine_pill]
        elif screen == 3:
            return [self.pet_child]
