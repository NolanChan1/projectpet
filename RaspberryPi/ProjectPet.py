import config
from DisplayController import DisplayController
from InputController import InputController

import board
import busio
import sys
import signal

disp_ctrl = None
input_ctrl = None

def main():
    global disp_ctrl
    global input_ctrl

    i2c = busio.I2C(board.SCL, board.SDA)
    disp_ctrl = DisplayController(i2c, config.OLED_WIDTH, config.OLED_HEIGHT, config.FONT_FP, config.SPRITE_FP, config.ANIMATION_COUNT, config.SCREEN_COUNT)
    input_ctrl = InputController(disp_ctrl)

    signal.signal(signal.SIGINT, signal_handler)

    disp_ctrl.animate()
    
    
def signal_handler(sig, frame):
    global disp_ctrl
    global input_ctrl

    disp_ctrl.cleanup()
    input_ctrl.cleanup()
    sys.exit(0)

if __name__ == "__main__":
    main()
