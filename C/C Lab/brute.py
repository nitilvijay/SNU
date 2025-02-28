import random
list=[65,66,67,68,69,97,98,99,100,101]
val=input("Enter the value: ")
password=""
while True:
    for i in range(0,3):
        password+=chr(random.choice(list))
    if password==val:
        print("Password found: ",password)
        break
    else:
        password=""



