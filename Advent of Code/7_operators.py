# program to find the sum of the test values that can be obtained by the combination of 
# adding or multiplying the numbers 
import itertools
    


with open("day_f_7.txt", "r") as file:
    
    sum_of_test_values=0
    
    for read in file:
        line=read.partition(":") # partition the line into 3 parts based on :  ["77", ":", " 7"]

        test_values=line[0]
        number=line[2].split() # Store the numbers in a list

        length=len(number)
        combination=itertools.product(["*","+"], repeat=length-1) # Generate all possible combinations of operators
        templist1=[]
        term=False
        tempstr=''

        
        for i in range (0,length):    
            templist1=templist1+[number[i]]+[" "]
        
        templist1.pop() #removing the last operator ' '
        
        for a in combination:
                
                count=1
                tempstr=''
                
                for h in range(0,len(a)):
                    templist1[count]=a[h]
                    count+=2
                
                value=0
                for b in range(0,len(templist1)):  # Adding the elements of the list to a string
                    tempstr=tempstr+templist1[b]
                    if b%2==0 and b>1:
                        value=eval(tempstr)
                        tempstr=str(value)
                    
                    
                if value==int(test_values):
                    sum_of_test_values+=int(test_values)
                    term=True
                    break
        
                if term==True:
                    break
    
    print(sum_of_test_values)
