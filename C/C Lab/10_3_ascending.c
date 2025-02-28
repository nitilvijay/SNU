#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr1;                             // using ptr1, dynamic memory to assign n value form the user
    ptr1 = (int *)malloc(3 * sizeof(int)); // Allocating memory for 1 integers and i, n
    // ptr1[0]= how many numbers
    // ptr1[1]= i value in loop
    // ptr1[2]=j value in loop
    // ptr[3]=temp
    printf("Enter how many numbers you want to enter\n");
    scanf("%d", ptr1);

    int *ptr2;
    ptr2 = (int *)malloc(ptr1[0] * sizeof(int)); // Allocating memory to store the input from the user

    for (ptr1[1] = 0; ptr1[1] < ptr1[0]; ptr1[1]++) // for loop to store the numbers
    {
        printf("Enter the number\n");
        scanf("%d", ptr2 + ptr1[1]);
    }

    for (ptr1[1] = 0; ptr1[1] < ptr1[0] - 1; ptr1[1]++) // sorting the given numbers
    {
        for (ptr1[2] = ptr1[1]+1; ptr1[2] < ptr1[0]; ptr1[2]++)
        {
            if (ptr2[ptr1[1]] > ptr2[ptr1[2]])
            {
                ptr1[3]=ptr2[ptr1[1]];
                ptr2[ptr1[1]] = ptr2[ptr1[2]];
                ptr2[ptr1[2]]=ptr1[3];
            }
        }
    }

    for (ptr1[2] = 0; ptr1[2] < ptr1[0]; ptr1[2]++)
    {

        printf("%d", ptr2[ptr1[2]]);
    }

    return 0;
}