// writing into a file
#include <stdio.h>

int main()
{
    //char arr[222];
    int arr;
    char arr1[222];
    FILE *fp;
    fp = fopen("sample.txt", "r");

    fscanf(fp, "%s %s", arr,arr1);
    printf("%d, %s\n",arr, arr1);
    fclose(fp);
}