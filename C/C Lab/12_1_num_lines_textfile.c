#include <stdio.h>

int main()
{
    char arr[100];
    int count = 0;

    FILE *fp;

    fp = fopen("sample.txt", "r");

    if (fp == NULL)
    {
        printf("Error\n");
    }
    else
    {
        while (fgets(arr, sizeof(arr), fp))
        {
            if (arr[0] == '\n') // condition to ignore the empty line
            {
                continue;
            }
            else
            {
                printf("%s",arr);
                count++;
            }
        }
        printf("\nThis is the number of lines: %d\n", count);
    }

    fclose(fp);

    return 0;
}