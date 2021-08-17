
import board
import time
import threading
import neopixel

stop_led = False
led_mood = 0

class LEDController(threading.Thread):
    def __init__(self, led_pin, num_led, led_brightness, led_delay, led_fp):
        global stop_led
        
        threading.Thread.__init__(self)
        
        self.led_strip = neopixel.NeoPixel(led_pin, num_led, brightness=led_brightness, auto_write=False)
        self.led_count = num_led
        self.delay = led_delay
        
        try:
            led_file = open(led_fp, "r")
        except FileNotFoundError as e:
            print("ERROR: Could not open text file to read LED colours. File: " + str(led_fp) + " could not be found.")
            stop_led = True
            
        self.normal_led = []
        self.happy_led = []
        
        txt_line = "NULL"
        while not txt_line.contains("HAPPY:") or not len(txt_line) <= 1:
            txt_line = led_file.readline().rstrip()
            led_values = txt_line.split(",")
            if len(led_values) != self.led_count*3:
                print("ERROR: Text file containing LED colours formatted incorrectly. There should be: " + str(self.led_count*3) + "numbers on each line with each number on the same line separated by a comma.")
                stop_led = True
                break
                
            tmp_list = []
            for i in range(0, self.led_count):
                tmp_list.append((led_values[i*3], led_values[i*3 + 1], led_values[i*3 + 2]))
                
            self.normal_led.append(tmp_list)
            
        while not len(txt_line) <= 1:
            txt_line = led_file.readline().rstrip()
            led_values = txt_line.split(",")
            if len(led_vales) != self.led_count*3:
                print("ERROR: Text file containing LED colours formatted incorrectly. There should be: " + str(self.led_count*3) + "numbers on each line with each number on the same line separated by a comma.")
                stop_led = True
                break
                
            tmp_list = []
            for i in range(0, self.led_count):
                tmp_list.append((led_values[i*3], led_values[i*3 + 1], led_values[i*3 + 2]))
                
            self.happy_led.append(tmp_list)
            
        led_file.close()
        
        
        
    def light_led(self):
        global stop_led
        global led_mood
        
        i = 0
        while i < len(self.normal_led) and not stop_led and led_mood == 0:
            for j in range(0, self.led_count):
                self.led_strip[j] = (self.normal_led[i][j][0], self.normal_led[i][j][1], self.normal_led[i][j][2])
                
                self.led_strip.show()
                i += 1
                time.sleep(self.delay)
            
        i = 0
        while i < len(self.happy_led) and not stop_led and led_mood == 1:
            for j in range(0, self.led_count):
                self.led_strip[j] = (self.normal_led[i][j][0], self.normal_led[i][j][1], self.normal_led[i][j][2])
                
                self.led_strip.show()
                i += 1
                time.sleep(self.delay)
                
            
    
    def cleanup(self):
        self.led_strip.fill((0,0,0))
        self.led_strip.show()
    
    def run(self):
        global stop_led
        
        while not stop_led:
            self.light_led()
            
        self.cleanup()
        
    def change_mood(self):
        global led_mood
        
        if led_mood == 0:
            led_mood = 1
        elif led_mood == 1:
            led_mood = 0
            
        