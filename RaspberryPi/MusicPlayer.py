
import RPi.GPIO as GPIO
import time
import threading
import tones

stop_player = False

class MusicPlayer(threading.Thread):
    def __init__(self, music_fp, music_tempo, buzzer_pin):
        global stop_player
        
        threading.Thread.__init__(self)
        self.tempo = music_tempo
        
        try:
            music_file = open(music_fp, "r")
        except FileNotFoundError as e:
            print("ERROR: Could not open text file to read music. File: " + str(music_fp) + " could not be found")
            stop_player = True
            
        self.notes = []
        self.beat = []
        while True:
            tmp_notes = music_file.readline().rstrip().split(",")
            tmp_beat = music_file.readline().rstrip().split(",")
            
            if not tmp_beat or not tmp_beat[0].replace('.','',1).isdigit():
                break
            else:
                self.notes.extend(tmp_notes)
                self.beat.extend(tmp_beat)
        
        if len(self.notes) != len(self.beat):
            print("ERROR: Music text file " + str(music_fp) + " formatted incorrectly. There must be the same amount of 'notes' as number of 'beat values'")
            stop_player = True
            
        self.length = len(self.notes)
        
        music_file.close()
        
        GPIO.setmode(GPIO.BCM)
        GPIO.setwarnings(False)
        
        GPIO.setup(buzzer_pin, GPIO.OUT)
        self.buzzer = GPIO.PWM(buzzer_pin, 440)
        
        
    def play_music(self):
        global stop_player
        
        recording_state = False
        recorded_startindex = -1
        recorded_endindex = -1
        
        playback_state = False
        
        saved_index = -1
        
        self.buzzer.start(50)
        i = 0
        while i < self.length and not stop_player:
                
            if self.notes[i] == "SR" and recording_state == False and playback_state == False:
                self.buzzer.stop()
                recording_state = True
                recorded_startindex = i
            elif self.notes[i] == "ER" and recording_state == True and playback_state == False:
                self.buzzer.stop()
                recording_state = False
                recorded_endindex = i
            elif self.notes[i] == "RP" and recording_state == False and playback_state == False:
                self.buzzer.stop()
                playback_state = True
                saved_index = i + 1
                i = recorded_startindex
            elif self.notes[i] == "P":
                self.buzzer.stop()  
            else:
                self.buzzer.stop()
                self.buzzer.ChangeFrequency(tones.tones[self.notes[i]])
                self.buzzer.start(50)

            time.sleep(float(self.beat[i])*self.tempo)
            
            i += 1
            
            if playback_state == True and i >= recorded_endindex:
                playback_state = False
                i = saved_index
        
        
    def cleanup(self):
        self.buzzer.stop()
        GPIO.cleanup()
        
    def run(self):
        global stop_player
        
        while not stop_player:
            self.play_music()
        
        self.cleanup()
            

