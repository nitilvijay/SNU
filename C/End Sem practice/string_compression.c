// Program for replacing sequences of repeated characters with the character followed by the count
#include <stdio.h>
#include <stdlib.h>

int length(char *str)
{
    int a = 0;
    int count = 0;

    for (a = 0; str[a] != '\0'; a++)
    {
        count++;
    }
    return count;
}

int main(int argc, char *argv[])
{
    char *str = (char *)malloc(100 * sizeof(char)); // Increased size for safety
    int cnt = 1;
    int next = 0;
    char temp[10]; // Buffer to hold the count as a string

    for (int i = 0; i < length(argv[1]); i++)
    {
        if (argv[1][i] == argv[1][i + 1] && i != (length(argv[1]) - 1))
        {
            cnt++;
        }
        else
        {
            str[next] = argv[1][i];
            next++;
            if (cnt > 1)
            {
                sprintf(temp, "%d", cnt);
                for (int j = 0; temp[j] != '\0'; j++, next++)
                {
                    str[next] = temp[j];
                }
                cnt = 1;
            }
        }
    }
    str[next] = '\0'; // Null-terminate the string
    printf("%s\n", str);

    free(str); // Free allocated memory
    return 0;
}