#include <stdio.h>
#include <stdlib.h>

int length(char *string) // Function to find the length of the string
{
    int *cnt = (int *)malloc(sizeof(int));
    *cnt = 0;
    while (string[*cnt] != '\0')
    {
        (*cnt)++;
    }
    return *cnt;
}

void file(int *pos)
{
    FILE *fp;
    fp = fopen("sample.txt", "w");
    if (fp != NULL)
    {
        fprintf(fp,"%s %d","This is the position:",*pos);
    }
}

int main(int argc, char *argv[])
{
    int *h = (int *)malloc(sizeof(int));
    int *i = (int *)malloc(sizeof(int));
    int *a = (int *)malloc(sizeof(int));
    char *str = (char *)malloc(30 * sizeof(char));
    int *len_str = (int *)malloc(sizeof(int));
    int *term = (int *)malloc(sizeof(int));
    int *found = (int *)malloc(sizeof(int));
    int *space = (int *)malloc(sizeof(int));
    int *pos = (int *)malloc(sizeof(int));
    int *start_pos = (int *)malloc(sizeof(int));

    *term = 0;
    *space = 0;
    *pos = 0;
    *start_pos = 0;

    // Store the last argument (substring to search for)
    for (*h = 0; argv[argc - 1][*h] != '\0'; (*h)++)
    {
        str[*h] = argv[argc - 1][*h];
    }
    str[*h] = '\0';

    printf("%s\n", str);

    *len_str = length(str);
    printf("Length of str: %d\n", *len_str);

    for (*i = 1; *i < argc - 1; (*i)++) // Loop through each word
    {
        *space += 1; // Increment space count between words
        if (length(argv[*i]) < *len_str)
        {
            *found = 0;
            *pos += length(argv[*i]);
            continue;
        }

        for (*a = 0; *a < length(argv[*i]); (*a)++) // Loop through each character
        {
            (*pos)++; // Increment overall position counter

            if (argv[*i][*a] == str[*term])
            {
                if (*term == 0) // Starting position of the substring
                {
                    *start_pos = *pos;
                }
                (*term)++;
                if (*term == *len_str) // If the whole substring is matched
                {
                    *found = 1;
                    break;
                }
            }
            else
            {
                *term = 0; // Reset matching
            }
        }
        if (*found == 1)
        {
            *start_pos += 7 + (*space);
            file(start_pos);
            break;
        }
    }

    if (*found == 0)
    {
        printf("Substring not found.\n");
    }

    // Free allocated memory
    free(h);
    free(i);
    free(a);
    free(str);
    free(len_str);
    free(term);
    free(found);
    free(space);
    free(pos);
    free(start_pos);

    return 0;
}
