text = input("Enter the string: ")
N = int(input("Enter the number of lines (N): "))

length = 0
for _ in text:
    length += 1

chars_per_line = length // N
extra_chars = length % N

i = 0
for line in range(N):
    sub_str = ""
    line_length = chars_per_line + (1 if line < extra_chars else 0)

    j = 0
    while j < line_length and i < length:
        sub_str += text[i]
        i += 1
        j += 1
    
    print(sub_str)