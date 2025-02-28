// Binary search
#include <stdio.h>

int main()
{
    int end = 100;
    int find;
    int mid;
    int start = 0;

    printf("Enter the number to find\n");
    scanf("%d", &find);

    while (start <= end)
    {
        mid = (start + end) / 2;
        if (find < start || find > end)
        {
            printf("Not found\n");
            break;
        }
        else if (mid == find)
        {
            printf("Found\n");
            break;
        }
        else if (find < mid)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    if (start > end)
    {
        printf("Not found\n");
    }

    return 0;
}