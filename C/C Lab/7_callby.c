#include <stdio.h>

int value(int num)
{
    int temp = 0;
    int sum = 0;
    while (num != 0)
    {
        temp = num % 10;
        num = num / 10;
        sum = sum + temp; // this sum is different than that in the main()
    }
    return sum;
}

int reference(int num, int *sum)
{
    int temp = 0;
    *sum = 0;
    while (num != 0)
    {
        temp = num % 10;
        num = num / 10;
        *sum = *sum + temp;
    }
    // No need for retrun as the value is directly updated in the memory address of sum
}

int main()
{
    int num, sum = 0 ;
    printf("Enter the number\n");
    scanf("%d", &num);

    // Call by value
    printf("%d\n", value(num));

    // Call by reference
    reference(num,&sum);
    printf("%d\n",sum);
}