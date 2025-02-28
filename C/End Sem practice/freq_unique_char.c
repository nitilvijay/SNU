#include <stdio.h>
#include <stdlib.h>

int length(char *str)
{
    int *a = (int *)malloc(sizeof(int));
    int *count = (int *)malloc(sizeof(int));

    for (*a = 0; str[*a] != '\0'; (*a)++)
    {
        (*count)++;
    }
    return *count;
}

int main(int argc, char *argv[])
{
    int *found = (int *)malloc(sizeof(int));
    int *count = (int *)malloc(sizeof(int));
    int *i = (int *)malloc(sizeof(int));
    int *a = (int *)malloc(sizeof(int));
    char *unique = (char *)malloc(10 * sizeof(char));
    int *freq = (int *)malloc(sizeof(int));


    for (*i = 0; *i < length(argv[1]); (*i)++)
    {
        *found = 0;
        *count = 0;
        
        if (*i != 0)
        {
            for (*a = 0; *a < *i; (*a)++)
            {
                if (argv[1][*a] == argv[1][*i])
                {
                    *found = 1;
                }
            }
        }
        if (*found == 0)
        {
            for (*a = *i; *a < length(argv[1]); (*a)++)
            {
                if (argv[1][*a] == argv[1][*i])
                {
                    (*count)++;
                }
            }
            printf("%c = %d\n",argv[1][*i],*count);
        }
    }
    return 0;
}