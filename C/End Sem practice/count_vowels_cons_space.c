// Program to find the count of vowels, consonants and space
#include <stdio.h>
#include <stdlib.h>

// Function to write data into a file
void file(int *vow, int *cons, int *space)
{
    FILE *fp;
    fp = fopen("sample.txt", "w");
    if (fp != NULL)
    {
        fprintf(fp, "Vowels: %d\nConsonants: %d\nSpaces: %d\n", *vow, *cons, *space);
    }
    else
    {
        printf("error\n");
    }
}
// Function to count the length of the word
int length(char *str)
{
    int *count = (int *)malloc(sizeof(int));
    *count = 0;

    while (str[*count] != '\0')
    {
        (*count)++;
    }
    return *count;
}

int main(int argc, char *argv[])
{
    int *vow = (int *)malloc(sizeof(int));
    int *cons = (int *)malloc(sizeof(int));
    int *space = (int *)malloc(sizeof(int));
    int *i = (int *)malloc(sizeof(int));
    int *a = (int *)malloc(sizeof(int));

    *space = argc - 2;

    for (*i = 1; *i < argc; (*i)++)
    {
        for (*a = 0; *a < length(argv[*i]); (*a)++)
        {
            if (argv[*i][*a] == 'a' || argv[*i][*a] == 'e' || argv[*i][*a] == 'i' || argv[*i][*a] == 'o' || argv[*i][*a] == 'u')
            {
                (*vow)++;
            }
            else
            {
                (*cons)++;
            }
        }
    }

    file(vow, cons, space);
}