#include <stdio.h>
// Program to find the length of a string call by reference and call by value
// Call by value
int value(char str[])
{
    int count = 0;
    while (1)
    {
        if (str[count] == '\0')
        {
            break;
        }
        count++;
    }
    return count;
}

// Call by reference
void reference(char str[],int*count)
{
    while (1)
    {
        if (str[*count] == '\0')
        {
            break;
        } 
        (*count)++;
    }

}

int main()
{
    int count=0;
    char arr[100];
    printf("Enter the word\n");
    scanf("%s",arr); 
    //call by value
    printf("value length = %d \n", value(arr));
    // call by reference
    reference(arr,&count);
    printf("reference length = %d \n",count);
}