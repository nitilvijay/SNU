def armstrong(n):
    arm = 0
    temp = n
    length = len(str(n))
    while temp!=0:
        rem = temp%10
        arm+=(rem**length)
        temp//=10
    if arm==n:
        print("Armstrong")
    else:
        print("No")

def deficient(n):
    defi = 0
    for i in range(n):
        if n%i==0:
            defi+=i
    
    if defi<n:
        print("Deficient")
    else:
        print("No")

def palindrome(n):
    n = str(n)
    if n==n[::-1]:
        print("Palindrome")
    else:
        print("No")

while True:
    choice = int(input("Enter the choice\n1. Armstrong NUmber\n2. Deficient Number\n3. Palindrome\n4. Exit"))
    number = int(input("Enter the number"))
    if choice==1:
        armstrong(number)
    elif choice==2:
        deficient(number)
    elif choice==3:
        palindrome(number)
    else:
        break

