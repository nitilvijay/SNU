def find_root(f, a, b):
    # Evaluate the polynomial at a given point
    def evaluate(poly, x):
        return sum(coef * (x ** i) for i, coef in enumerate(reversed(poly)))

    num1 = evaluate(f, a)
    num2 = evaluate(f, b)

    # Check if both endpoints are roots
    if abs(num1) < 1e-6 and abs(num2) < 1e-6:
        print(f"Both {a} and {b} are roots.")
        return

    # Check if no root exists in the range
    if (num1 > 0 and num2 > 0) or (num1 < 0 and num2 < 0):
        print("No root in the given range")
        return

    # Ensure the range is ordered correctly
    if num1 > 0:
        start, end = b, a
    else:
        start, end = a, b

    # Bisection method
    while (end - start) > 1e-6:
        mid = (end + start) / 2
        root = evaluate(f, mid)

        print(f"mid: {mid}, root: {root}")

        if abs(root) < 1e-6:
            print(f"Root found: {mid}")
            return

        if root > 0:
            end = mid
        else:
            start = mid

    print("Root not found within the desired precision.")

# Example usage
a = -5
b = 10
f = (1, -6, 11, -6)  # Coefficients of x^3 - 6x^2 + 11x - 6
find_root(f, a, b)
