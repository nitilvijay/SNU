#include <stdio.h>

int digit_sum(int num);

int main()

    int num,
    quot = 1, rem, sum = 0;

printf("Enter the Number");

scanf("%d", &num);


int digit_sum(int num)
{

    while (quot > 0)
    {

        quot = num / 10;

        rem = num % 10;

        num = quot;

        sum = sum + rem;
    }

    return sum;
}

printf("The sum of the Digits:%d", digit_sum(num))