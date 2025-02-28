#include <stdio.h>

void palindrome(char arr[], int size)
{
    int pal = 1;
    for (int i = 0; i < size / 2; i++)
    {
        if (arr[i] == arr[size - 1 - i])
        {
            pal = 0;
        }
        else
        {
            pal = 1;
            break;
        }
    }
    if (pal == 0)
    {
        printf("Palindrome\n");
    }
    else
    {
        printf("Not a palindrome \n");
    }
}
int main()
{
    int size;
    printf("Enter the number of digits\n");
    scanf("%d", &size);

    char arr[size];

    printf("Enter the number \n");
    scanf("%s", arr);
    palindrome(arr, size); 
}