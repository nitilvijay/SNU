#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr1;                             // using ptr1, dynamic memory to assign n value form the user
    ptr1 = (int *)malloc(4 * sizeof(int)); // Allocating memory for 1 integers and i, n

    printf("Enter how many numbers you want to enter\n");
    scanf("%d", ptr1);

    int *ptr2;
    ptr2 = (int *)malloc(ptr1[0] * sizeof(int)); // Allocating memory to store the input from the user

    for (ptr1[1] = 0; ptr1[1] < ptr1[0]; ptr1[1]++) // for loop to store the numbers
    {
        printf("Enter the number\n");
        scanf("%d", ptr2 + ptr1[1]);
    }

    printf("Enter the number to find\n");// getting the number to find
    scanf("%d", ptr1 + 2);
    ptr1[3] = 0;

    for (ptr1[1] = 0; ptr1[1] < ptr1[0]; ptr1[1]++) // for loop to check the numbers
    {
        if (ptr2[ptr1[1]] == ptr1[2])
        {
            printf("Found\n");
            ptr1[3] = 1;
        }
    }

    if (ptr1[3] == 0)
    {
        printf("Not found\n");
    }
}
