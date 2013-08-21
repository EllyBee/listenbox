import json
from pprint import pprint
json_data=open('json/goals.json')

data = json.load(json_data)
#pprint(data)
json_data.close()

_health = data[0]["health"]
pprint(_health)
