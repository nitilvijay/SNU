#Leap Year

year = int(input('Enter the year'))

if year%100==0:

    if year%400==0:
        print("It is a leap yaer")
    else:
        print('Not a leap year')

elif year%4==0:
    print("It is a leap yaer")

else:
    print("Its not a Leap year")