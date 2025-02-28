#include <stdio.h>
// Program to multiply two matrix
int main()
{
    int row1, col1, row2, col2;
    // rows 1
    printf("Enter the number of rows for matrix 1\n");
    scanf("%d", &row1);

    // column 1
    printf("Enter the number of columns for matrix 1\n");
    scanf("%d", &col1);

    // row 2
    printf("Enter the number of rows for matrix 1\n");
    scanf("%d", &row1);

    // column 2
    printf("Enter the number of columns for matrix 1\n");
    scanf("%d", &col1);

    if (col1 == row2)
    {
        int mat1[row1][col1], mat2[row2][col2], mat3[row1][col2];
       
        // Matrix 1 input

        for (int i = 0; i < row1; i++)
        {
            printf("Enter the elements of row %d\n", i + 1);
            // Getting column value
            for (int a = 0; a < col1; a++)
            {
               scanf("%d", &mat1[i][a]);
            }
        }

        // Matrix 2 input
       
        printf("This is matrix 2\n");

        for (int i = 0; i < row2; i++)
        {
            printf("Enter the elements of row %d\n", i + 1);
            // Getting column value
            for (int a = 0; a < col2; a++)
            {
                scanf("%d", &mat2[i][a]);
            }
        }

        
    }
}