def find_root(f, a, b):
    num1 = (f[0] * (a**3)) + (f[1] * (a**2)) + (f[2] * a) + f[3]
    num2 = (f[0] * (b**3)) + (f[1] * (b**2)) + (f[2] * b) + f[3]

    if (num1 > 0 and num2 > 0) or (num1 < 0 and num2 < 0):
        print("No root in the given range")
        return

    if num1 > 0:
        start, end = b, a
    else:
        start, end = a, b

    while (end - start) > 1e-6:
        mid = (end + start) / 2
        root = (f[0] * (mid**3)) + (f[1] * (mid**2)) + (f[2] * mid) + f[3]

        print(f"mid: {mid}, root: {root}")

        if abs(root) < 1e-6:
            print(mid)
            break

        if root > 0:    
            end = mid
        else:
            start = mid

    else:   
        print("Not found")

a = -5
b = 10 
f = (1, -6, 11, -6) 
find_root(f, a, b)
