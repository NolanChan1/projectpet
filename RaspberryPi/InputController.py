
import RPi.GPIO as GPIO

import config

def button1_pressed(channel):
    global disp_ctrl
    
    disp_ctrl.change_screen(-1)
    
def button2_pressed(channel):
    global disp_ctrl
    
    disp_ctrl.change_screen(1)
    
def button3_pressed(channel):
    global disp_ctrl
    
    disp_ctrl.change_mood()

class InputController:
    def __init__(self, disp_ctrl):
        self.disp_ctrl = disp_ctrl
        GPIO.setmode(GPIO.BCM)
        GPIO.setwarnings(False)
        
        GPIO.setup(config.BUTTON1_PIN, GPIO.IN, pull_up_down=GPIO.PUD_UP)
        GPIO.add_event_detect(config.BUTTON1_PIN, GPIO.FALLING, callback=button1_pressed, bouncetime=250)
        GPIO.setup(config.BUTTON2_PIN, GPIO.IN, pull_up_down=GPIO.PUD_UP)
        GPIO.add_event_detect(config.BUTTON2_PIN, GPIO.FALLING, callback=button2_pressed, bouncetime=250)
        GPIO.setup(config.BUTTON3_PIN, GPIO.IN, pull_up_down=GPIO.PUD_UP)
        GPIO.add_event_detect(config.BUTTON3_PIN, GPIO.FALLING, callback=button3_pressed, bouncetime=250)
    
    def cleanup(self):
        GPIO.cleanup()
