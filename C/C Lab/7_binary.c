#include <stdio.h>

int value(int num)
{
    int bin[100];
    int temp = 0;
    int length = 0;
    for (int i = 0; num != 0; i++)
    {
        temp = num % 2;
        num = num / 2;
        bin[i] = temp;
        length++;
    }

    printf("This is the binary value\n");
    for (int a = length-1; a >= 0; a--)
    {
        printf("%d", bin[a]);
    }
    printf("\n");
}
int main()
{
    int num;
    printf("Enter the decimal number\n");
    scanf("%d", &num);
    value(num);
}