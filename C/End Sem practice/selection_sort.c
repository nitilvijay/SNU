#include <stdio.h>

int main()
{
    int arr[] = {5, 3, 1, 2, 4};
    int size = 5;
    int index;
    int temp;

    for (int i = 0; i < size - 1; i++)
    {
        index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[index])
            {
                index = j;
            }
        }

        // Swap the elements
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }

    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}