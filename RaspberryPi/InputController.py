
import RPi.GPIO as GPIO

class InputController:
    def __init__(self, disp_ctrl):
        self.disp_ctrl = disp_ctrl
        GPIO.setmode(GPIO.BCM)
        GPIO.setwarnings(False)
        
    
    def cleanup(self):
        GPIO.cleanup()
