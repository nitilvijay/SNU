#include <stdio.h>

char* reverse(char arr[], char temp[], int length, int count)
{
    if (count < length)
    {
        temp[count] = arr[length - count - 1];
        return reverse(arr, temp, length, count + 1);
    }
    else
    {
        return temp;
    }
}
int main()
{
    int length, count = 0;
    char*ptr;
    printf("Enter the length of the stringn\n");
    scanf("%d", &length);

    // array input
    char temp[length];
    char arr[length];
    printf("Enter the array\n");
    scanf("%s", arr);

    // function call
    ptr = reverse(arr, temp, length, count);

    // printing the reversed array

    for (int i = 0; i < length; i++)
    {
        printf("%c",temp[i]);
       
    }
     printf("\n");
     return 0;
}