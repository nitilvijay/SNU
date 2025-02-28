#include <stdio.h>
#include <stdlib.h>

// Program to find the greatest amoung n numbers

int main()
{
    int *ptr1;                             // using ptr1, dynamic memory to assign n value form the user
    ptr1 = (int *)malloc(2 * sizeof(int)); // Allocating memory for 1 integers
    printf("Enter how many numbers you want to enter\n");
    scanf("%d", ptr1);
    int *ptr2;
    ptr2 = (int *)malloc(2 * sizeof(int)); // Allocating memory to store the input from the user
    ptr2[1] = 0;
    for (ptr1[1] = 0; ptr1[1] < ptr1[0]; (ptr1[1] = ptr1[1] + 1))
    {
        printf("Enter the numbers\n");
        scanf("%d", ptr2);
        if (ptr2[0] > ptr2[1])
        {
            ptr2[1] = ptr2[0];
        }
    }
    printf("This is the greatest:%d\n",ptr2[1]);
}