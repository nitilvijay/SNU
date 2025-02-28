#include <stdio.h>
#include <string.h>

// Program to find if two arrays are equal

int main()
{
    int i, len, count, term;

    printf("Enter the number of elements in the array\n");
    scanf("%d", &term);

    char arr[term], arrn[term];

    for (int i = 0; i < term; i++)
    {
        printf("Enter array 1\n");
        scanf(" %c", arr+i);

        printf("Enter array 2\n");
        scanf(" %c", arrn+i);
    }

    for (i = 0; i < term; i++)
    {
        if (arr[i] == arrn[i])
        {
            count = 1;
        }
        else
        {
            count = 0;
        }
    }

    if (count == 1)
    {
        printf("They are equal\n");
    }
    else
    {
        printf("Not equal\n");
    }

    return 0;
}
