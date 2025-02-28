#include <stdio.h>
#include <stdlib.h>

void insertionsort(int arr[], int size)
{
    int cur;
    for (int a = 1; a < size; a++)
    {
        int j = a - 1;
        cur = arr[a];

        while (j >= 0 && arr[j] > cur)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = cur;
    }
}

int main()
{
    int arr[5];
    int size = 5;
    for (int i = 0; i < 5; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", arr + i);
    }

    insertionsort(arr, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
