#include <stdio.h>
#include <stdlib.h>

int length(char *word)
{
    int *count = (int *)malloc(sizeof(int));
    *count = 0;

    while (word[*count] != '\0')
    {
        (*count)++;
    }
    return *count;
}

char* assign(char*string, char*word)
{
    int*i=(int*)malloc(sizeof(int));
    for (*i=0; word[*i]!='\0';(*i)++)
    {
        string[*i]=word[*i];
    }
    string[*i]='\0';

    return string;
}

int main(int argc, char *argv[])
{
    char *str = (char *)malloc(20 * sizeof(char));
    int *max = (int *)malloc(sizeof(int));
    int *a = (int *)malloc(sizeof(int));

    *max = 0;

    for (*a = 1; *a < argc; (*a)++)
    {
        if (length(argv[*a]) >= *max)
        {
            *max = length(argv[*a]);
            assign(str,argv[*a]);
        }
    }

    printf("%s\n",str);
}