#include <stdio.h>
// Add and Subtract Two matrices
int main()
{
    int row, col;

    printf("Enter the number of rows\n");
    scanf("%d", &row);

    printf("Enter the number of columns\n");
    scanf("%d", &col);

    int mat1[row][col], mat2[row][col], mat3[row][col];

    // Matrix 1 input

    for (int i = 0; i < row; i++)
    {
        printf("Enter the elements of row %d\n", i + 1);
        // Getting column value
        for (int a = 0; a < col; a++)
        {
            int temp = 0;
            scanf("%d", &temp);
            mat1[i][a] = temp;
        }
    }

    // Matrix 2 input
    printf("This is matrix 2\n");

        for (int i = 0; i < row; i++)
    {
        printf("Enter the elements of row %d\n", i + 1);
        // Getting column value
        for (int a = 0; a < col; a++)
        {
            int temp = 0;
            scanf("%d", &temp);
            mat2[i][a] = temp;
        }
    }

    // Add or Sub
    char oper;
    printf("Enter if You want to add or sub\n");

    scanf(" %c", &oper);

    // add
    if (oper == '+')
    {
        for (int i = 0; i < row; i++)
        {
            for (int a = 0; a < col; a++)
            {
                mat3[i][a] = mat1[i][a] + mat2[i][a];
            }
        }
    }
    // Subtarct
    else if (oper == '-')
    {
        for (int i = 0; i < row; i++)
        {
            for (int a = 0; a < col; a++)
            {
                mat3[i][a] = mat1[i][a] - mat2[i][a];
            }
        }
    }

    else
    {
        printf("Invalid\n");
    }

    // Printing the final matrix

    for (int i = 0; i < row; i++)
    {
        for (int a = 0; a < col; a++)
        {
            printf("%d  ",mat3[i][a]);
        }
        printf("\n");
    }

    return 0;
}