def addition(x,y):
    print(x+y)
def subtraction(x,y):
    print(x-y)
def multiplication(x,y):
    print(x*y)
def division(x,y):
    print(x/y)
    
def askChoice(x,y):
    while True:
        print("1.addition")
        print("2.subtraction")
        print("3.multiplication")
        print("4.division")
        print("5.Exit")
        choice=int(input("Enter your choice"))
        if(choice==1):
            addition(x,y)
        if(choice==2):
            subtraction(x,y)
        if(choice==3):
            multiplication(x,y)
        if(choice==4):
            division(x,y)
        if(choice==5):
            break
def takeInput():
    x=int(input("Enter first number"))
    y=int(input("Enter second number"))
    askChoice(x,y)

def main():
    takeInput()
if __name__=="__main__":
    main()
