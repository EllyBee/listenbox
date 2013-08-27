import serial

serial_connection = False
SERIAL_PATH = '/dev/ttyAMA0''
SERIAL_SPEED = 9600

def main():
	try:
		global serial_connection
		serial_connection = serial.Serial(SERIAL_PATH, SERIAL_SPEED)
	except:
		print "Problem connecting to arduino"
		exit()
	default = ''
	while default.__len__() < 1:
		default = raw_input('Default: ')

	while True:
		indata = raw_input('Send? ')
		if indata.__len__() < 1:
			send(default)
		else:
			send(indata)
		
def send(data):
	serial_connection.write(str(chr(int(data))))
	#print "Wrote", data, "(", chr(int(data) + 20).__str__(), ") over serial"

if __name__ == '__main__':
	main()
