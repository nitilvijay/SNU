#include <stdio.h>

int main()
{
    int row, col;

    // Ask the user for the number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of columns: ");
    scanf("%d", &col);

    // Declare two matrices and a result matrix
    int matrix1[row][col], matrix2[row][col], result[row][col];

    // Get input for the first matrix
    printf("Enter elements for the first matrix:\n");
    for (int i = 0; i < row; i++)
    {
        printf("Enter the elements of row %d: ", i + 1);
        for (int j = 0; j < col; j++)
        {    
            scanf("%d", &matrix1[i][j]); // Fill the first matrix
        }
    }

    // Get input for the second matrix
    printf("Enter elements for the second matrix:\n");
    for (int i = 0; i < row; i++)
    {
        printf("Enter the elements of row %d: ", i + 1);
        for (int j = 0; j < col; j++)
        {    
            scanf("%d", &matrix2[i][j]); // Fill the second matrix
        }
    }

    // Ask the user for the operation
    char operation;
    printf("Enter '+' to add or '-' to subtract the matrices: ");
    scanf(" %c", &operation); // Space before %c to consume any leftover whitespace

    // Perform the operation
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (operation == '+')
            {
                result[i][j] = matrix1[i][j] + matrix2[i][j]; // Addition
            }
            else if (operation == '-')
            {
                result[i][j] = matrix1[i][j] - matrix2[i][j]; // Subtraction
            }
            else
            {
                printf("Invalid operation\n");
                return 1; // Exit if the operation is invalid
            }
        }
    }

    // Print the result
    printf("Resulting matrix:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", result[i][j]); // Print the result matrix
        }
        printf("\n");
    }

    return 0; // Indicate successful execution
}
