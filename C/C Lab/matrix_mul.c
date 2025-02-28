#include <stdio.h>

int main()
{
    int row1, col1, row2, col2;

    // Get dimensions for the first matrix
    printf("Enter the number of rows for the 1st matrix: ");
    scanf("%d", &row1);
    printf("Enter the number of columns for the 1st matrix: ");
    scanf("%d", &col1);

    // Get dimensions for the second matrix
    printf("Enter the number of rows for the 2nd matrix: ");
    scanf("%d", &row2);
    printf("Enter the number of columns for the 2nd matrix: ");
    scanf("%d", &col2);

    // Check if multiplication is possible
    if (col1 != row2)
    {
        printf("Error: The number of columns of the first matrix must equal the number of rows of the second matrix.\n");
        return 1; // Exit if dimensions are incompatible
    }

    int matrix1[row1][col1]; // Define the first matrix
    int matrix2[row2][col2]; // Define the second matrix
    int result[row1][col2];  // Define the result matrix

    // Input elements for the first matrix
    printf("Enter elements for the first matrix:\n");
    for (int i = 0; i < row1; i++)
    {
        printf("Enter the elements of row %d: ", i + 1);
        for (int j = 0; j < col1; j++)
        {
            scanf("%d", &matrix1[i][j]); // Fill the first matrix
        }
    }

    // Input elements for the second matrix
    printf("Enter elements for the second matrix:\n");
    for (int i = 0; i < row2; i++)
    {
        printf("Enter the elements of row %d: ", i + 1);
        for (int j = 0; j < col2; j++)
        {
            scanf("%d", &matrix2[i][j]); // Fill the second matrix
        }
    }

    // Initialize result matrix to zero
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            result[i][j] = 0; // Set each element to 0
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            for (int k = 0; k < col1; k++) // or use row2 since col1 == row2
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j]; // Multiply and accumulate
            }
        }
    }

    // Print the result matrix
    printf("Resulting matrix:\n");
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            printf("%d ", result[i][j]); // Print the result matrix
        }
        printf("\n");
    }

    return 0; // Indicate successful execution
}
