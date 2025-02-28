#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int *i = (int *)malloc(sizeof(int));
    int *j = (int *)malloc(sizeof(int));
    *j = 1;
    for ((*i) = 0; (*i) < 5; (*i) ++)
    {
        printf(" %c\n",argv[*j][*i]);
    }
    return 0;
}