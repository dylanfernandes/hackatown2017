from clarifai import rest
from clarifai.rest import ClarifaiApp
from clarifai.rest import Image as ClImage
import json
import sys


#First approve the image to detect
def ApproveImage(ResultOfClarifai):
    result = ResultOfClarifai["status"]["description"]
    
    # this is the right way to parse this:
    # print(ResultOfClarifai["outputs"][0]["data"]["regions"][0]["region_info"]["bounding_box"]["top_row"])
    
    if result == "Ok":
        return True
    else:
        return False

def RetrieveBoundingBox(ResultOfClarifai):
    for s in ResultOfClarifai["outputs"]:
        for obj in s:
            #print(obj)
            if(obj == "data"):
                #print(obj)
                return s[obj]

def Test(data):
    text_file = open("Output.txt","w")
    
    top_row = 'top_row' #y1
    left_col = 'left_col' #x1
    bottom_row = 'bottom_row' #y2
    right_col = 'right_col' #x2
    for regions in data:
        for region_info in data[regions]:
            for bounding_box in region_info:
                myString = str(region_info[bounding_box])

                # top_row
                index = myString.find(top_row)
                y1 = myString[(index+10):]
                y1 = y1[:10]

                # left_col
                index = myString.find(left_col)
                x1 = myString[(index+11):]
                x1 = x1[:10]

                # bottom_row
                index = myString.find(bottom_row)
                y2 = myString[(index+13):]
                y2 = y2[:10]

                # right_col
                index = myString.find(right_col)
                x2 = myString[(index+12):]
                x2 = x2[:9]

                text_file.write("x1:%s" %x1)
                text_file.write("\n")
                text_file.write("y1:%s " %y1)
                text_file.write("\n")
                text_file.write("x2:%s " %x2)
                text_file.write("\n")
                text_file.write("y2:%s " %y2)
                text_file.write("\n")
    text_file.close()



app = ClarifaiApp("nn1bgfNLFp0GqNmhbtnHFfDgAWIZAN4DwkS7PBht","_U8j2SDC-Y7lcwrBnEKwar3ml2fHoAXK2jrF50n_")
# get the general model
#model = app.models.get("general-v1.3")
model = app.models.get('a403429f2ddf4b49b307e318f00e528b')
# predict with the model
image = ClImage(url='https://samples.clarifai.com/face-det.jpg')
myvar = model.predict([image])


if ApproveImage(myvar):
    data = RetrieveBoundingBox(myvar)
    lastElem = Test(data)

else:
    print("Not able to analyse this image, sorry!")

