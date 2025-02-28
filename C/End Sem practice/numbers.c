#include <stdio.h>
#include <stdlib.h>

//Function to find the sum of numbers in the array
int sum(int arr[],int *length)
{
    int*i=(int*)malloc(sizeof(int));
    int*sum = (int*)malloc(sizeof(int));
    *sum=0;

    for (*i = 0;*i<*length;(*i)++)
    {
        *sum+=arr[*i];
    }
    return *sum;
}

int max(int arr[],int *length)
{
    int*i=(int*)malloc(sizeof(int));
    int*max = (int*)malloc(sizeof(int));
    *max=0;

    for (*i = 0;*i<*length;(*i)++)
    {
        if (arr[*i]>(*max))
        {
            *max = arr[*i];
        }
    }
    return *max;
}

int max(int arr[],int *length)
{
    int*i=(int*)malloc(sizeof(int));
    int*min = (int*)malloc(sizeof(int));
    *min=arr[*i];

    for (*i = 0;*i<*length;(*i)++)
    {
        if (arr[*i]<(*min))
        {
            *min = arr[*i];
        }
    }
    return *max;
}

int main(int argc, char*argv[])
{
    FILE*fp;
    fp=fopen(argv[1],"r");

    if (fp==NULL)
    {
        return 1;
    }

    int*temp = (int*)malloc(sizeof(int));
    char*str = (char*)malloc(100*sizeof(char));
    int*i = (int*)malloc(sizeof(int));
    int*length = (int*)malloc(sizeof(int));
    int*sum = (int*)malloc(sizeof(int));

    while (fscanf(fp,"%d",temp) != EOF)
    {
        str[*i] = *temp;
        (*i)++;
    }
    *length = *i;
    
    for (*i=0;*i<*length;(*i)++)
    {
        printf("%d ",str[*i]);
    }
    //Calculate sum
    *sum=add(str,length);
    printf("This is the sum: %d",*sum);

    //max and min
    maxmin(str,length);

}