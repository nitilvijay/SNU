#include <stdio.h>
#include <math.h>

// Function to print all Armstrong numbers from 0 to n
int armstrong(int num)  
{
    int temp1, temp2, count, arm;

    if (num >= 0)
    {
        // Loop through each number from 0 to num
        for (int i = 0; i <= num; i++)
        {
            temp2 = i;  // Save the current number
            count = 0;  // Reset count for each number
            arm = 0;    // Reset arm for each number

            // Count the number of digits in the current number
            while (temp2 != 0)
            {
                temp2 = temp2 / 10;
                count++;
            }

            // Reset temp2 to original value to calculate Armstrong sum
            temp2 = i;

            // Calculate the Armstrong sum
            while (temp2 != 0)
            {
                temp1 = temp2 % 10;  // Get last digit
                arm += pow(temp1, count);  // Add digit raised to the power of count
                temp2 = temp2 / 10;  // Remove last digit
            }

            // Check if the sum equals the original number
            if (arm == i)
            {
                printf("%d ", i);  // Print Armstrong number
            }
        }
        printf("\n");
    }
    else
    {
        printf("Input a positive number\n");
    }
    return 0;
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    armstrong(num);

    return 0;
}
