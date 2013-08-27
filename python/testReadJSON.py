
import urllib2
import json
'''req = urllib2.Request("http://clients.simonheys.com/wolff-olins/o/goals.json")
opener = urllib2.build_opener()
f = opener.open(req)
json = json.load(f.read())
#print json
print json[0]['health']'''


json = json.load(urllib2.urlopen("http://clients.simonheys.com/wolff-olins/o/goals.json"))
print json
