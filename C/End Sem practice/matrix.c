// Program to perform matrix addition and subtrction
#include <stdio.h>
#include <stdlib.h>

void add(int **arr1, int **arr2, int **arr3, int *row, int *col)
{
    int* g = (int*)malloc(sizeof(int));
    int* h = (int*)malloc(sizeof(int));

    for (*g = 0; *g < *row; *g++)
    {
        for (*h = 0; *h < *col; *h++)
        {
            arr3[*g][*h] = arr1[*g][*h] + arr2[*g][*h];
        }
    }
    free(g);
    free(h);
}

void sub(int **arr1, int **arr2, int **arr3, int *row, int *col)
{
    int* g = (int*)malloc(sizeof(int));
    int* h = (int*)malloc(sizeof(int));

    for (*g = 0; *g < *row; *g++)
    {
        for (*h = 0; *h < *col; *h++)
        {
            arr3[*g][*h] = arr1[*g][*h] - arr2[*g][*h];
        }
    }
    free(g);
    free(h);
}

void mul(int **arr1, int **arr2, int *row, int *col)
{
    //mul
}

int main(int argc, char *argv[])
{
    int *row = (int *)malloc(sizeof(int));
    int *col = (int *)malloc(sizeof(int));
    int *i = (int *)malloc(sizeof(int));
    int *a = (int *)malloc(sizeof(int));
    int *count = (int *)malloc(sizeof(int));
    char *choice = (char *)malloc(2*sizeof(char));

    *row = atoi(argv[1]);
    *col = atoi(argv[2]);
    *count = 3;

    *choice = argv[argc - 1][0];

    int **arr1 = (int **)malloc((*row) * sizeof(int *));
    int **arr2 = (int **)malloc((*row) * sizeof(int *));
    int **arr3 = (int **)malloc((*row) * sizeof(int *));

    // assigning memory for the 2d array through for loop

    // Matrix 1
    for (*i = 0; *i < *row; (*i)++)
    {
        arr1[*i] = (int *)malloc((*col) * sizeof(int));

        // assigning the values in the matrix

        for (*a = 0; *a < *col; (*a)++)
        {
            arr1[*i][*a] = atoi(argv[*count]);
            (*count)++;
        }
    }

    // Matrix 2
    for (*i = 0; *i < *row; (*i)++)
    {
        arr2[*i] = (int *)malloc((*col) * sizeof(int));

        // assigning the values in the matrix

        for (*a = 0; *a < *col; (*a)++)
        {
            arr2[*i][*a] = atoi(argv[*count]);
            (*count)++;
        }
    }

    // Matrix 3
    for (*i = 0; *i < *row; (*i)++)
    {
        arr3[*i] = (int *)malloc((*col) * sizeof(int));
    }

    switch (*choice)
    {
    case '+':
        add(arr1, arr2, arr3, row, col);
        break;

    case '-':
        sub(arr1, arr2, arr3, row, col);
        break;

    case '*':
        mul(arr1, arr2, row, col);
        break;
    }

    //Display
    for (*i = 0; *i < *row; (*i)++)
    {
        for (*a = 0; *a < *col; (*a)++)
        {
            printf("%d ",arr3[*i][*a]);
        }
        printf("\n");
    }
    for (*i = 0; *i < *row; (*i)++)
    {
        free(arr1[*i]);
        free(arr2[*i]);
        free(arr3[*i]);
    }
    free(arr1);
    free(arr2);
    free(arr3);

    free(row);
    free(col);
    free(i);
    free(a);
    free(count);
    free(choice);

    return 0;
}