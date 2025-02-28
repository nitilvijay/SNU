def fact(num):
    fac = 1
    for i in range(1,num+1):
        fac*=i
    return fac

def sin(N,x):
    val = 0
    count = 1
    for i in range(1,N+1,2):

        if count%2==0:
            val-=((x**i)/fact(i))
        else:
            val+=((x**i)/fact(i))

        count+=1
    print(f"sin: {val}")

def cos(N,x):

    val = 0
    count = 1
    for i in range(0,N+1,2):

        if count%2==0:
            val-=((x**i)/fact(i))
        else:
            val+=((x**i)/fact(i))

        count+=1
    print(f"cos: {val}")

N = int(input("Enter the N"))
x = int(input("Enter the x"))

sin(N,(x*(3.14/180)))
cos(N,(x*(3.14/180)))