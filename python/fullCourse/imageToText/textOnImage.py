import numpy as np
import cv2
font = cv2.FONT_HERSHEY_SIMPLEX
# Create a black image
#img = np.zeros((512,512,3), np.uint8)
img = cv2.imread("sample4.png") 
f=open("recognized.txt","r");
for x in r:
	print(x)

//cv2.putText(img,'Hack Projects',(50,99), font, 1,(255,255,255),2)
#Display the image
cv2.imshow("img",img)

cv2.waitKey(0)