import config
import DisplayController

import board
import busio



def main():
    i2c = busio.I2C(board.SCL, board.SDA)
    disp_ctrl = DisplayController(i2c, config.OLED_WIDTH, config.OLED_HEIGHT, config.FONT_FP, config.SPRITE_FP, config.ANIMATION_COUNT)
    input_ctrl = InputController.gpio_setup(disp_ctrl)
    
    

if __name__ == "__main__":
    main()