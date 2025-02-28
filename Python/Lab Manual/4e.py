num1 = int(input("Enter decimal number: "))
num2 = int(input("Enter decimal number: "))


print(f"number 1: {num1}")

print(f"Binary: {bin(num1)}")

print(f"Octal: {oct(num1)}")

print(f"Hexadecimal: {hex(num1)}")


print(f"Number 2: {num2}")

print(f"Binary: {bin(num2)}")

print(f"Octal: {oct(num2)}")

print(f"Hexadecimal: {hex(num2)}")


and_result = num1 & num2

or_result = num1 | num2

not_num1 = ~num1

not_num2 = ~num2

left_shift_num1 = num1 << 2

right_shift_num1 = num1 >> 2



print(f"AND Operation: {num1} & {num2} = {and_result} (Binary: {bin(and_result)})")

print(f"OR Operation: {num1} | {num2} = {or_result} (Binary: {bin(or_result)})")

print(f"NOT Operation on {num1}: ~{num1} = {not_num1} (Binary: {bin(not_num1)})")

print(f"NOT Operation on {num2}: ~{num2} = {not_num2} (Binary: {bin(not_num2)})")

print(f"Left Shift {num1} by 2: {left_shift_num1} (Binary: {bin(left_shift_num1)})")

print(f"Right Shift {num1} by 2: {right_shift_num1} (Binary: {bin(right_shift_num1)})")
