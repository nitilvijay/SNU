basic_pay = int(input("Enter the Basic Pay"))

da = 0.15*basic_pay
hra = 0.10*basic_pay
pf = 0.12*basic_pay

salary = basic_pay+da+hra - pf

print("The Salary is: ",salary)
print(f"Da = {da}, HRA = {hra}, PF = {pf}")