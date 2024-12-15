import sys
import time
import RPi.GPIO as io
import subprocess

io.setmode(io.BOARD)
SHUTOFF_DELAY = 120 # seconds
PIR_PIN=11

# Attention, apres une detection, le PIR renvoyer 1 pendant une 15aine de seconde

def main():
    print ("Detection started.")
    print ("Wait", SHUTOFF_DELAY, "sec before all is OK")
    io.setup(PIR_PIN, io.IN)
    turned_off = False
    last_motion_time = time.time()
    while True:
        if io.input(PIR_PIN):
            last_motion_time = time.time()
            sys.stdout.flush()
            if turned_off:
                turned_off = False
                turn_on()
                print ("ON")
        else:
            if not turned_off and time.time() > (last_motion_time + SHUTOFF_DELAY):
                turned_off = True
                turn_off()
                print ("OFF")
            if not turned_off and time.time() > (last_motion_time + 1):
                time.sleep(.1)

def turn_on():
    subprocess.call("sh /home/pi/Desktop/Cuisine/monitor_on.sh", shell=True)

def turn_off():
    subprocess.call("sh /home/pi/Desktop/Cuisine/monitor_off.sh", shell=True)

if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        io.cleanup()

