#include <stdio.h>

char* palindrome(char arr[], int length, int count)
{
    if (count >= length) {
        return "True";  // Base case: If we reach the middle without mismatch
    }
    if (arr[count] != arr[length - count - 1]) {
        return "False";  // Mismatch found, not a palindrome
    }
    return palindrome(arr, length, count + 1);  // Recursive call with incremented count
}

int main()
{
    int length;
    printf("Enter the length of the string\n");
    scanf("%d", &length);
    
    char arr[length + 1];  // Include space for null terminator
    printf("Enter the string\n");
    scanf("%s", arr);

    printf("%s\n", palindrome(arr, length, 0));
    return 0;
}
