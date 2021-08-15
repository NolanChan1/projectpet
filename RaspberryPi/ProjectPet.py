import config
from DisplayController import DisplayController
from InputController import InputController
from SaveData import SaveData
import MusicPlayer

import board
import busio
import sys
import signal
import threading

disp_ctrl = None
input_ctrl = None
music_player = None

def main():
    global disp_ctrl
    global input_ctrl
    global music_player
    
    save = SaveData()
    i2c = busio.I2C(board.SCL, board.SDA)
    disp_ctrl = DisplayController(i2c, config.OLED_WIDTH, config.OLED_HEIGHT, config.FONT_FP, config.SPRITE_FP, config.ANIMATION_COUNT, config.SCREEN_COUNT)
    input_ctrl = InputController(disp_ctrl, save)

    music_player1 = MusicPlayer.MusicPlayer(config.MUSIC_FP1, config.TEMPO, config.BUZZER1_PIN)
    music_player2 = MusicPlayer.MusicPlayer(config.MUSIC_FP2, config.TEMPO, config.BUZZER2_PIN)
    
    signal.signal(signal.SIGINT, signal_handler)

    music_player1.start()
    music_player2.start()
    disp_ctrl.animate()
    
    
def signal_handler(sig, frame):
    global disp_ctrl
    global input_ctrl

    disp_ctrl.cleanup()
    input_ctrl.cleanup()
    MusicPlayer.stop_player = True
    sys.exit(0)

if __name__ == "__main__":
    main()
