import config

import RPi.GPIO as GPIO
import time
import threading
import tones

stop_player = False

class MusicPlayer(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)
        self.tempo = config.TEMPO
        
        music_file = open(config.MUSIC_FP, "r")
        self.notes = music_file.readline().rstrip().split(",")
        self.beat = music_file.readline().rstrip().split(",")
        self.length = len(self.notes)
        
        music_file.close()
        
        GPIO.setmode(GPIO.BCM)
        GPIO.setwarnings(False)
        
        GPIO.setup(config.BUZZER_PIN, GPIO.OUT)
        self.buzzer = GPIO.PWM(config.BUZZER_PIN, 440)
        
        
    def play_music(self):
        global stop_player
        
        self.buzzer.start(50)
        for i in range(0, self.length):
            if stop_player:
                return
                
            if self.notes[i] == "P":
                self.buzzer.stop()
            else:
                self.buzzer.stop()
                self.buzzer.ChangeFrequency(tones.tones[self.notes[i]])
                self.buzzer.start(50)

            time.sleep(float(self.beat[i])*self.tempo)
            i += 1
        
        
    def cleanup(self):
        self.buzzer.stop()
        GPIO.cleanup()
        
    def run(self):
        global stop_player
        
        while not stop_player:
            self.play_music()
        
        self.cleanup()
            
    def stop_player(self):
        self.stop = True

