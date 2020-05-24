print("searching for word python")

try:
	with open("data.txt") as file: 
		data = file.readlines() 
		for line in data: 
			word = line.split(" ")
			for i in word:
				if(i=='python'):
					print("found")		
except Exception as e:
	print(e)