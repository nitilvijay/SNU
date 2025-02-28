def triplets(n):

    for i in range(3,n):
        for a in range(1,i):
            for h in range(a,i):

                if a!=h and (a**2)+(h**2)==(i**2):
                    print(f"{a}^2 + {h}^2 = {i}^2")


n = int(input("Enter the number"))
triplets(n)