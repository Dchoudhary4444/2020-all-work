a={'one':1,'two':2,'three':3}
print(a)
result=1
for i in a:
	result=result*a[i]
print(result)
b={'four':4,'five':5}
print(a.update(b))
print(a)	