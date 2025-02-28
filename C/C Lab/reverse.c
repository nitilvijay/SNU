#include<stdio.h>
#include<string.h>

//Program to reverse a string

int main(){
    int i,len;
    char arr[20];
    printf("Enter the string to reverse\n");
    scanf(" %s",arr);
    len=strlen(arr);

    for (i=len-1;i>=0;i--){
        char val=arr[i];
        printf(" %c\n",val);
    }

    return 0;
}