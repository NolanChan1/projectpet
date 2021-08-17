import config

import time
import RPi.GPIO as GPIO

disp_ctrl = None
led_ctrl = None
save_data = None

def button1_pressed(channel):
    global disp_ctrl
    
    long_press = 2
    start_time = time.time()
    
    while GPIO.input(channel) == 0 and (time.time() - start_time) < 1:
        pass
        
    press_time = time.time() - start_time
    
    if 0.25 <= press_time < 1:
        long_press = 0
    elif press_time >= 1:
        long_press = 1
        
    if long_press == 0:
        pass
        print("TEST1")
    elif long_press == 1:
        disp_ctrl.change_screen(1)
        
    disp_ctrl.update_stats(save_data.get_curr_stats())
    
def button2_pressed(channel):
    global disp_ctrl
    
    long_press = 2
    start_time = time.time()
    
    while GPIO.input(channel) == 0 and (time.time() - start_time) < 1:
        pass
        
    press_time = time.time() - start_time
    
    if 0.25 <= press_time < 1:
        long_press = 0
    elif press_time >= 1:
        long_press = 1
        
    if long_press == 0:
        pass
        print("TEST2")
    elif long_press == 1:
        disp_ctrl.change_screen(-1)
    
    disp_ctrl.update_stats(save_data.get_curr_stats())
    
def button3_pressed(channel):
    global disp_ctrl
    global led_ctrl
    
    disp_ctrl.change_mood()
    led_ctrl.change_mood()
    
def button4_pressed(channel):
    print("TEST3")

class InputController:
    def __init__(self, dctrl, lctrl, save):
        global disp_ctrl
        global led_ctrl
        global save_data

        disp_ctrl = dctrl
        led_ctrl = lctrl
        save_data = save
        
        disp_ctrl.update_stats(save_data.get_curr_stats())
        
        GPIO.setmode(GPIO.BCM)
        GPIO.setwarnings(False)

        GPIO.setup(config.BUTTON1_PIN, GPIO.IN, pull_up_down=GPIO.PUD_UP)
        GPIO.add_event_detect(config.BUTTON1_PIN, GPIO.FALLING, callback=button1_pressed, bouncetime=250)
        GPIO.setup(config.BUTTON2_PIN, GPIO.IN, pull_up_down=GPIO.PUD_UP)
        GPIO.add_event_detect(config.BUTTON2_PIN, GPIO.FALLING, callback=button2_pressed, bouncetime=250)
        GPIO.setup(config.BUTTON3_PIN, GPIO.IN, pull_up_down=GPIO.PUD_UP)
        GPIO.add_event_detect(config.BUTTON3_PIN, GPIO.FALLING, callback=button3_pressed, bouncetime=250)
        GPIO.setup(config.BUTTON4_PIN, GPIO.IN, pull_up_down=GPIO.PUD_UP)
        GPIO.add_event_detect(config.BUTTON4_PIN, GPIO.FALLING, callback=button4_pressed, bouncetime=250)
    
    def cleanup(self):
        GPIO.cleanup()
