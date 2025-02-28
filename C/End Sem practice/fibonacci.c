#include <stdio.h>
#include <stdlib.h>

int main()
{
int num1, num2, num3;

num1 = 0;
num2 = 1;
num3=0;

printf("%d  %d  ", num1, num2);
for (int i = 0; i < 7; i++)
{
    num3 = num1 + num2;
    num1 = num2;
    num2 = num3;
    printf("%d  ", num3);
}
printf("\n");
}