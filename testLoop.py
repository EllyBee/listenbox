import json
from pprint import pprint
import time

currentHealth = 0
newHealth = 0

while True:

	json_data=open('json/goals.json')

	data = json.load(json_data)
	#pprint(data)
	json_data.close()

	newHealth = data[0]["health"]
	#print(_health)

	if(newHealth!=currentHealth):
		print 'new'

	#else:
		#print 'old news'

	currentHealth = newHealth
	time.sleep(1)
	

