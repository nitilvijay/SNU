#include <stdio.h>

int main()
{
    int arr[] = {5, 3, 1, 2, 4};
    int size = 5;
    int temp;

    for (int i = 0; i < size - 1; i++)
    {
        for (int a = 0; a < size - i - 1; a++)
        {
            if (arr[a] > arr[a + 1])
            {
                temp = arr[a];
                arr[a] = arr[a + 1];
                arr[a + 1] = temp;
            }
        }
    }
    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}