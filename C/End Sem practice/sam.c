#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE*fp;
    fp=fopen("sample.txt","r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    char str[100];
    char str1[100];
    int temp;

    fseek(fp, 0, SEEK_SET);
    while (fscanf(fp,"%d",&temp)!=EOF)
    {
        printf("%d\n",temp);
    }
    return 0;
}
