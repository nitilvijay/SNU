#include <stdio.h>

int main()
{
    int n, a, i;

    // Getting the length of array to define it
    printf("Enter the number of elements in array 1\n");
    scanf("%d", &n);
    printf("Enter the number of elements in array 2\n");
    scanf("%d", &a);

    int arr1[n], arr2[a], arr3[n + a];

    // Getting the input for the arrays
    // Array 1
    printf("Enter the elements of array 1\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }

    // Array 2
    printf("Enter the elements of array 2\n");
    for (i = 0; i < a; i++)
    {
        scanf("%d", &arr2[i]); // Corrected index from arr2[a] to arr2[i]
    }

    // Arranging array 1 in ascending order
    for (i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr1[i] > arr1[j])
            {
                int temp = arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = temp;
            }
        }
    }

    // Arranging array 2 in ascending order
    for (i = 0; i < a - 1; i++)
    {
        for (int j = i + 1; j < a; j++)
        {
            if (arr2[i] > arr2[j])
            {
                int temp = arr2[i];
                arr2[i] = arr2[j];
                arr2[j] = temp;
            }
        }
    }
    // Now merging the two ascending arrays into an ascending order array
    // Copy arr1 into arr3
    for (i = 0; i < n; i++)
    {
        arr3[i] = arr1[i];
    }

    // Copy arr2 into arr3 after arr1
    for (int j = 0; j < a; j++)
    {
        arr3[i + j] = arr2[j];
    }

    // Sorting arr3
    int q = a + n; // Length of arr3
    for (i = 0; i < q - 1; i++)
    {
        for (int j = i + 1; j < q; j++)
        {
            if (arr3[i] > arr3[j])
            {
                int temp = arr3[i];
                arr3[i] = arr3[j];
                arr3[j] = temp;
            }
        }
    }

    // Printing the merged array
    printf("Merged array in ascending order: \n");
    for (i = 0; i < q; i++)
    {
        printf("%d ", arr3[i]); // Added space for better readability
    }
    printf("\n");

    return 0;
}
