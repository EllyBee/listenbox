import json
from pprint import pprint
import time
import urllib2
from random import randint
import serial

currentHealth = 0
newHealth = 0

#setup arduino
serial_connection = False
SERIAL_PATH = '/dev/ttyAMA0'
SERIAL_SPEED = 9600

def setuparduino():
	try:
		global serial_connection
		serial_connection = serial.Serial(SERIAL_PATH, SERIAL_SPEED)
	except:
		print "Problem connecting to arduino"
		exit()
	

def send(data):
	serial_connection.write(str(chr(int(data))))


def checkNewValue():
	 
	 if(newHealth<currentHealth):
	 	#turn light red
	 	send(72)

	 if(newHealth>currentHealth):
	 	#turn light green
	 	send(73)


setuparduino()

while True:

	#local json file
	'''json_data=open('json/goals.json')

	json2 = json.load(json_data)
	#pprint(data)
	json_data.close()'''

	#online json file
	randomInt = randint(2,9)
	url = 'http://clients.simonheys.com/wolff-olins/o/goals.json?1234' + str(randomInt)
	req = urllib2.Request(url)
	opener = urllib2.build_opener()
	f = opener.open(req)

	json2 = json.loads(f.read())


	'''json2 = json.load(urllib2.urlopen("http://clients.simonheys.com/wolff-olins/o/goals.json"))
	print json2'''

	newHealth = json2[0]["health"]

	if(newHealth!=currentHealth):
		print 'new'
		print newHealth
		checkNewValue()

	currentHealth = newHealth
	time.sleep(2)




