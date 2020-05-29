import cv2 
import pytesseract 

def generateReceipt(imageToBeProcessed,fImage,a,b,pathToSaveImage):
	pytesseract.pytesseract.tesseract_cmd = r'C:\\Program Files\\Tesseract-OCR\\tesseract';
	img = cv2.imread(imageToBeProcessed) 
	finalImage = cv2.imread(fImage)
	gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY) 
	ret, thresh1 = cv2.threshold(gray, 0, 255, cv2.THRESH_OTSU | cv2.THRESH_BINARY_INV) 

	# Specify structure shape and kernel size. 
	# Kernel size increases or decreases the area 
	# of the rectangle to be detected. 
	# A smaller value like (10, 10) will detect 
	# each word instead of a sentence. 
	rect_kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (18, 18)) 

	# Appplying dilation on the threshold image 
	dilation = cv2.dilate(thresh1, rect_kernel, iterations = 1) 

	# Finding contours 
	contours, hierarchy = cv2.findContours(dilation, cv2.RETR_EXTERNAL, 
												cv2.CHAIN_APPROX_NONE) 

	# Creating a copy of image 
	im2 = img.copy() 

	# A text file is created and flushed 
	file = open("recognized.txt", "w+") 
	file.write("") 
	file.close() 
	# Looping through the identified contours 
	# Then rectangular part is cropped and passed on 
	# to pytesseract for extracting text from it 
	# Extracted text is then written into the text file

	for cnt in contours: 
		x, y, w, h = cv2.boundingRect(cnt) 
		print(x,y,w,h)	
		# Drawing a rectangle on copied image 
		rect = cv2.rectangle(im2, (x, y), (x + w, y + h), (0, 255, 0), 2) 
		
		# Cropping the text block for giving input to OCR 
		cropped = im2[y:y + h, x:x + w] 
		
		# Open the file in append mode 
		file = open("recognized.txt", "a") 
		
		# Apply OCR on the cropped image 
		text = pytesseract.image_to_string(cropped) 
		print(text)
		if text in a:
			print("-----------change krna hai")	
			# Appending the text into file 
			file.write(text)
			file.write("\n") 
			file.write(str(x))
			file.write("\n") 
			file.write(str(y))
			file.write("\n") 
			file.write(str(w))
			file.write("\n") 
			file.write(str(h)) 
			file.write("\n") 
			# Close the file 
			file.close 
			font = cv2.FONT_HERSHEY_SCRIPT_COMPLEX
			print(b.get(text))
			try:
				cv2.putText(finalImage,b.get(text),(x+int(w/10),y+(int(h/2)+int(font))), font, 1,(0,0,255),2)		
			except:
				print("gadbad hue")
	cv2.imwrite(pathToSaveImage+"finalImage.png",finalImage)
	cv2.imshow("final Image",finalImage)
	cv2.waitKey(0)



a=["[date]","[no]","[name]","[amount]"];
print(a) 
b={"[date]":"02/10/1998","[no]":"21","[name]":"Deepak Choudhary","[amount]":"10000/-"}
print(b);
generateReceipt("sample4.png","sample6.png",a,b,"c://2020//deepak//python//fullCourse//imageToText//del//")
