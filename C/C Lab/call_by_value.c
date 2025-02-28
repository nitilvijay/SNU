#include<stdio.h>

int change(int num1, int num2)
{
    printf("This is in the fuction, before change\n");
    printf("num1=%d num2=%d\n",num1, num2);
    
    num1=2;
    num2=1;
    
    printf("This is after the change, inside the function \n");
    printf("num1=%d num2=%d\n",num1,num2);
    return 0;
}
int main()
{
    int num1, num2;
    num1=1;
    num2=2;
    printf("Before function\n");
    printf("num1=%d num2=%d\n",num1,num2);
    
    change(num1,num2);
    
    printf("This is after the function process \n");
    printf("num1=%d num2=%d \n",num1,num2);
    
}