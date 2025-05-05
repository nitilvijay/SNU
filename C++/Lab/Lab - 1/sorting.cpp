// Menu driven program for sorting
#include <iostream>
using namespace std;
// insertion sort
void insertion(int arr[], int num)
{
    for (int i = 0; i < num; i++)
    {
        int j = i - 1;
        int temp = arr[i];

        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }
}

// Bubble Sort
void bubble(int arr[], int num)
{
    int temp1;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp1 = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp1;
            }
        }
    }
}

// Selection Sort
void selection(int arr[], int num)
{
    int temp2;
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (arr[j]<arr[i])
            {
                temp2 = arr[j];
                arr[j] = arr[i];
                arr[i] = temp2;
            }
        }
    }
}

int main()
{
    int num;
    int choice;

    printf("Enter the number of numbers to be entered\n");

    scanf("%d", &num);

    int arr[num];

    printf("Enter the numbers\n");

    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\n");


    printf("1. Insertion Sort\n2. Bubble Sort\n3. Selection Sort\n4. Exit\n");

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        insertion(arr, num);
        break;
    case 2:
        bubble(arr, num);
        break;
    case 3:
        selection(arr, num);
        break;
    case 4:
        break;
    }
    
    for (int i = 0; i < num; i++)
    {
        printf("%d", arr[i]);
        cout << " ";
    }
    cout << endl;
}