// Program to find if a number is armstrong or not
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Function to write into file
void file(int*found,int*arm)
{
    FILE*fp;
    fp=fopen("sample.txt","w");
    if (fp!=NULL && *found==1)
    {
        fprintf(fp,"%d %s",*arm," is an armstrong number");
    }
}

int main(int argc, char *argv[])
{
    int *num = (int *)malloc(sizeof(int));
    int *last_digit = (int *)malloc(sizeof(int));
    int *temp = (int *)malloc(sizeof(int));
    int *arm = (int *)malloc(sizeof(int));
    int *length = (int *)malloc(sizeof(int));
    int *found = (int*)malloc(sizeof(int));

    // convert string to number
    *num = atoi(argv[1]);
    
    *temp = *num;
    *length = 0;
    *arm = 0;

    while (*temp != 0)
    {
        *temp = (*temp) / 10;
        (*length)++;
    }
    
    *temp = *num; // reset temp to original number

    while (*temp != 0)
    {
        *last_digit = *temp % 10;
        *temp = *temp / 10;
        *arm += pow(*last_digit, *length);
    }

    if (*arm == *num)
    {
        *found = 1;
    }
    else
    {
        *found = 0;
    }
    file(found,arm);

    free(num);
    free(last_digit);
    free(temp);
    free(arm);
    free(length);
}