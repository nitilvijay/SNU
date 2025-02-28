#include<stdio.h>
#include<string.h>

//Program to find the palindrome a string

int main(){
    int i,len,a;
    char arr[20];
    printf("Enter the string to find\n");
    scanf("%s",arr);
    len=strlen(arr);
    i=len-1;
    a=0;
    int inc=0;
    int count=0;
    while (inc<len){
        if (arr[i]==arr[a]){
            count++;
        }
        else{
            count=0;
        }
        a++;
        i--;
        inc++;
    }
    if (count!=0){
        printf("True");
    }
    else{
        printf("false");
    }
    
    return 0;
}

// #include <stdio.h>
// #include <string.h>

// // Program to find if a string is a palindrome

// int main() {
//     int i, len;
//     char arr[20];
    
//     printf("Enter the string to find\n");
//     scanf("%s", arr);
//     len = strlen(arr);
    
//     int isPalindrome = 1; // Assume it's a palindrome initially

//     for (i = 0; i < len / 2; i++) {
//         if (arr[i] != arr[len - 1 - i]) {
//             isPalindrome = 0; // Found a mismatch
//             break;
//         }
//     }

//     if (isPalindrome) {
//         printf("True\n");
//     } else {
//         printf("false\n");
//     }

//     return 0;
// }
// //