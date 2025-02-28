key_name = input("Enter the key name to be changed: ")
new_key_name = input("Enter the new key name: ")
d = {"name":"John","age":30,"city":"New York","country":"USA"}

d[new_key_name] = d.pop(key_name)
print(d)
