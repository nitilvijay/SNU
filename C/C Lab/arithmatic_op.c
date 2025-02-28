#include <stdio.h>

int main()
{
    char sym;
    printf("Enter the operator");
    scanf(" %c", &sym);
    if (sym == '+')
    {
        printf("enter the 2 numbers to add");
        int num1, num2;
        scanf("%d\n%d", &num1, &num2);
        int sum;
        sum = num1 + num2;
        printf("This is the sum %d", sum);
    }
    if (sym == '-')
    {
        printf("enter the 2 numbers to subtract");
        int num1, num2;
        scanf("%d\n%d", &num1, &num2);
        int diff;
        diff = num1 - num2;
        printf("This is the difference %d", diff);
    }
    if (sym == '*')
    {
        printf("enter the 2 numbers to multiply");
        int num1, num2;
        scanf("%d\n%d", &num1, &num2);
        int mul;
        mul = num1 * num2;
        printf("This is the mul %d", mul);
    }

    if (sym == '/')
    {
        printf("enter the 2 numbers to divide");
        int num1, num2;
        scanf("%d\n%d", &num1, &num2);
        int div;
        div = num1 / num2;
        printf("This is the div %d", div);
    }
    if (sym == '%')
    {
        printf("enter the 2 numbers to give remainder");
        int num1, num2;
        scanf("%d\n%d", &num1, &num2);
        int rmd;
        rmd = num1 % num2;
        printf("This is the remainder %d", rmd);
    }
    if (sym == '&')
    {
        printf("enter the 2 numbers to peform bitwise AND");
        int num1, num2;
        scanf("%d\n%d", &num1, &num2);
        int and;
        and = num1 & num2;
        printf("This is the bitwise and output %d", and);
    }
    if (sym == '|')
    {
        printf("enter the 2 numbers to perform OR");
        int num1, num2;
        scanf("%d\n%d", &num1, &num2);
        int or ;
        or = num1 | num2;
        printf("This is the bitwise or output %d", or);
    }
    if (sym == '^')
    {
        printf("enter the 2 numbers to perform bitwise XOR");
        int num1, num2;
        scanf("%d\n%d", &num1, &num2);
        int xor;
        xor = num1 ^ num2;
        printf("This is the XOR%d", xor);
    }

    return 0;
}