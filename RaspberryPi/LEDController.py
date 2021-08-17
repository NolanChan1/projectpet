
import board
import time
import neopixel

class LEDController:
    def __init__(self, led_pin, num_led, led_brightness, led_fp):
        self.led_strip = neopixel.NeoPixel(led_pin, num_led, brightness=led_brightness, auto_write=False)
        self.led_count = num_led
        self.curr_mood = 0
        
        try:
            led_file = open(led_fp, "r")
        except FileNotFoundError as e:
            print("ERROR: Could not open text file to read LED colours. File: " + str(led_fp) + " could not be found.")
            
        self.normal_led = []
        self.happy_led = []
        
        txt_line = led_file.readline().rstrip()
        while not "HAPPY:" in txt_line and len(txt_line) > 1:
            led_values = txt_line.split(",")
            if len(led_values) != self.led_count*3:
                print("ERROR: Text file containing LED colours formatted incorrectly. There should be: " + str(self.led_count*3) + " numbers on each line with each number on the same line separated by a comma.")
                break
                
            tmp_list = []
            for i in range(0, self.led_count):
                tmp_list.append((led_values[i*3], led_values[i*3 + 1], led_values[i*3 + 2]))
                
            self.normal_led.append(tmp_list)
            txt_line = led_file.readline().rstrip()
            
        txt_line = led_file.readline().rstrip()
        while len(txt_line) > 1:
            led_values = txt_line.split(",")
            if len(led_values) != self.led_count*3:
                print("ERROR: Text file containing LED colours formatted incorrectly. There should be: " + str(self.led_count*3) + " numbers on each line with each number on the same line separated by a comma.")
                break
                
            tmp_list = []
            for i in range(0, self.led_count):
                tmp_list.append((led_values[i*3], led_values[i*3 + 1], led_values[i*3 + 2]))
                
            self.happy_led.append(tmp_list)
            txt_line = led_file.readline().rstrip()
            
        led_file.close()
        
        self.animation_frame = 0
        self.normal_animation_count = len(self.normal_led)
        self.happy_animation_count = len(self.happy_led)
        
        # Reset LED colours
        self.led_strip.fill((0,0,0))
        self.led_strip.show()
        
    def next_frame(self):
        if self.curr_mood == 0:
            if self.animation_frame >= self.normal_animation_count:
                self.animation_frame = 0
            
            for i in range(0, self.led_count):
                self.led_strip[i] = (int(self.normal_led[self.animation_frame][i][0]), int(self.normal_led[self.animation_frame][i][1]), int(self.normal_led[self.animation_frame][i][2]))
                self.led_strip.show()
        elif self.curr_mood == 1:
            if self.animation_frame >= self.happy_animation_count:
                self.animation_frame = 0
                
            for i in range(0, self.led_count):
                self.led_strip[i] = (int(self.happy_led[self.animation_frame][i][0]), int(self.happy_led[self.animation_frame][i][1]), int(self.happy_led[self.animation_frame][i][2]))
                self.led_strip.show()
                
        self.animation_frame += 1
            
        
    def light_led(self):
        global stop_led
        global led_mood
        
        i = 0
        while i < len(self.normal_led) and not stop_led and led_mood == 0:
            for j in range(0, self.led_count):
                self.led_strip[j] = (int(self.normal_led[i][j][0]), int(self.normal_led[i][j][1]), int(self.normal_led[i][j][2]))
                
                self.led_strip.show()
                i += 1
                time.sleep(self.delay)
            
        k = 0
        while k < len(self.happy_led) and not stop_led and led_mood == 1:
            for j in range(0, self.led_count):
                try:
                    print(k)
                    self.led_strip[j] = (int(self.happy_led[k][j][0]), int(self.happy_led[k][j][1]), int(self.happy_led[k][j][2]))
                except IndexError as e:
                    print(str(k) + "," + str(j))
                self.led_strip.show()
                k += 1
                time.sleep(self.delay)
                
            
    
    def cleanup(self):
        self.led_strip.fill((0,0,0))
        self.led_strip.show()
        
    def change_mood(self):
        if self.curr_mood == 0:
            self.curr_mood = 1
        elif self.curr_mood == 1:
            self.curr_mood = 0
            
        
