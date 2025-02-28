// Program to check if a substring part of a string
#include <stdio.h>
#include <stdlib.h>

int length(char *string, int *count)
{
    *count = 0;
    while (string[*count] != '\0')
    {
        (*count)++;
    }
    return *count;
}

void copy_string(char *dest, char *src)
{
    int *g = (int *)malloc(sizeof(int));
    for (*g = 0; src[*g] != '\0'; (*g)++)
    {
        dest[*g] = src[*g];
    }
    dest[*g] = '\0';
    free(g);
}

int main(int argc, char *argv[])
{
    char *str = (char *)malloc(30 * sizeof(char));
    char *temp = (char *)malloc(30 * sizeof(char));
    int *i = (int *)malloc(sizeof(int));
    int *a = (int *)malloc(sizeof(int));
    int *h = (int *)malloc(sizeof(int));
    int *pos = (int *)malloc(sizeof(int));
    int *found = (int *)malloc(sizeof(int));
    int *count = (int *)malloc(sizeof(int));
    int *space = (int *)malloc(sizeof(int));

    // Assigning each character to the memory allocated through str
    for (*h = 0; argv[argc - 1][*h] != '\0'; (*h)++)
    {
        str[*h] = argv[argc - 1][*h];
    }
    str[*h] = '\0';

    printf("%s\n", str);
    // str[*h] = '\0'; // assigning last element as null terminator

    *pos = 0; // initializing the position to zero
    *found = 0;
    *space = 0; // Initializing the value of space to 0 at first

    for (*i = 0; *i < argc - 1; (*i)++) // Using the function len to find the length of the string

    {
        if (length(argv[*i], count) != length(str, count))
        {
            *found = 0;
        }
        else
        {
            for (*a = 0; *a < length(str, count); (*a)++)
            {
                // printf(" %c %c \n",str[*a],argv[*i][*a]);
                // copy_string(temp, argv[*i]);
                if (str[*a] == argv[*i][*a])
                {
                    *found = 1;
                    break;
                }
            }
        }

        if (*found == 0)
        {
            *pos += length(argv[*i], count);
        }
        else
        {
            break;
        }

        *space += 1; // Incresing the value of space for everytime when the word is not found
    }

    if (*found == 1)
    {
        FILE *fp;
        fp = fopen("sample.txt", "w");

        if (fp == NULL)
        {
            printf("Error while wrting into file\n");
        }
        else
        {
            *pos += *space;
            fprintf(fp, "%s %d", "The position is: ", *pos);
        }
    }
    else
    {
        printf("Not found\n");
    }

    // Free allocated memory
    free(str);
    free(temp);
    free(i);
    free(a);
    free(h);
    free(pos);
    free(found);
    free(count);

    return 0;
}