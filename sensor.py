#!/opt/python3/bin/python3.4
import Adafruit_BBIO.GPIO as GPIO

GPIO.setup("P8_14", GPIO.OUT)
GPIO.output("P8_14", GPIO.HIGH)
