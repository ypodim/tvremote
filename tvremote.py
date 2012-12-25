import serial
import time
import sys

ser = serial.Serial('/dev/tty.usbmodem1411', 9600)
print ser.portstr
time.sleep(0.5)

wrote = ser.write(sys.argv[1])
print 'wrote', wrote
ser.flushOutput()

ser.close()