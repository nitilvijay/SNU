#include <stdio.h>
// Program to find the fibonacci series
int main()
{
    int i, num, fib, num1, num2;
    printf("Enter the nth number of the fibonacci series\n");
    scanf("%d", &num);                                          //Getting the input form the user
    i = 1;
    num1 = 1;
    num2 = 0;
    fib = num1 + num2;
    printf("%d\n", 1);
    while (i <= num)
    {
        num2 = num1;
        num1 = fib;
        fib = num1 + num2;
        i++;
        printf("%d\n", fib);
    }
    return 0;
}
