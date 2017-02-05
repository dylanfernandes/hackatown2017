import json
import httplib
headers = { "charset" : "utf-8", "Content-Type": "application/json" }

#refer from http://stackoverflow.com/questions/28778384/sending-json-data-from-python-to-php
#missing avi and image file to send (maybe through ssh)?

#extract all coordinates
driverLicensePlate = '123456'
driverName = 'Lawrence'

#sample of other driver:
otherDriverLicensePlate = '567890'

data = {
	'licensePlate' = driverLicensePlate
	'driverFName'  = driverName

	
json_str = json.dumps(data)
conn = httplib.HTTPConnection("localhost")

conn.request("POST", "/process.php", json_str, headers)

response = conn.getresponse()

print(response.read())

conn.close()

