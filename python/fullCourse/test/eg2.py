a=[1,2,3,4]
b=[4,5,6,7]
index=0;
flag=False;
while index<len(a):
    j=0
    while j<len(b):
        try:
            if a[index]==b[j]:
                flag=True
            else:
                pass;
        except:
            print("Somthing went wrong")
            
        j+=1
        
    index+=1
if flag:
    print(flag)
