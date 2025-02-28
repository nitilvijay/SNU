#include <stdio.h>
#include "headerfile.h"

void linear(int arr[], int num, int value)
{
    int found = 0;

    for (int i = 0; i < num; i++)
    {
        if (arr[i] == value)
        {
            printf("Found\n");
            found = 1;
            break;
        }
        else
        {
            found = 0;
        }
    }
    if (found == 0)
    {
        printf("Not found\n");
    }
}

void binary(int arr[], int num, int value)
{
    int start = 0, end = num - 1, mid;
    while (start <= end)
    {
        mid = (start + end) / 2; // Calculate mid each time
        if (arr[mid] == value)
        {
            printf("Number found\n");
            return; // Exit the function if the number is found
        }
        else if (arr[mid] > value)
        {
            end = mid - 1; // Search the left half
        }
        else
        {
            start = mid + 1; // Search the right half
        }
    }
    printf("Number not found\n"); // Number not found if loop exits
}

int main()
{
    int choice;
    int num;
    int value;

    printf("Enter the number of numbers to be entered\n");

    scanf("%d", &num);

    int arr[num];

    printf("Enter the numbers\n");

    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\n");

    printf("1. Linear Search\n2. Binary search\n");
    scanf("%d", &choice);

    printf("Enter the number to search\n");
    scanf("%d", &value);

    switch (choice)
    {
    case 1:
        linear(arr, num, value);
        break;
    case 2:
        insertion(arr, num);
        binary(arr, num, value);
        break;
    }
}