#include <stdio.h>

int main()
{
    FILE *sample;
    FILE *copy;

    char arr[100];

    sample = fopen("sample.txt", "r");

    copy = fopen("copy.txt", "w");

    if (sample == NULL || copy == NULL)
    {
        printf("Error\n");
        return 1;
    }
    while (fgets(arr, sizeof(arr), sample))
    {
        fprintf(copy,"%s",arr);
    }
    return 0;
}