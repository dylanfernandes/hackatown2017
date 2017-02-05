import json

headers = { "charset" : "utf-8", "Content-Type": "application/json" }

#refer from http://stackoverflow.com/questions/28778384/sending-json-data-from-python-to-php
#missing avi and image file to send (maybe through ssh)?

#extract all coordinates
driverLicensePlate = '123456'
driverName = 'Lawrence'

#sample of other driver:
otherDriverLicensePlate = '567890'
data ='licensePlate:'+ driverLicensePlate+";driverName:"+driverName+";otherdriverlicense:"+otherDriverLicensePlate

json_str = json.dumps(data)
with open('data.txt', 'w') as outfile:
    outfile.write(data)
	
