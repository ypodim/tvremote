#!/usr/bin/env python

import serial
import time
import sys

PORT = '/dev/tty.usbmodem1411'
PORT = '/dev/ttyACM0'

ser = serial.Serial(PORT, 9600)
print ser.portstr
time.sleep(0.5)
# code = raw_input()
# print code

wrote = ser.write(sys.argv[1])
print 'wrote', wrote
# ser.flushOutput()
# print ser.read()

ser.close()