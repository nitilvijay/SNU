#include <stdio.h>

// Tic Tac Toe GAME
int main()
{
    int turn = 0, count, terminate = 1, stop = 0;
    char num;
    char arr[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

    while (terminate == 1)
    {
        // Turn of X
        if (turn % 2 == 0)
        {
            turn++;
            // printing the game
            for (int h = 0; h < 3; h++)
            {
                for (int k = 0; k < 3; k++)
                {
                    printf("%c\t", arr[h][k]);
                }
                printf("\n");
            }
            printf("Enter where you want to enter X\n");
            scanf(" %c", &num);

            for (int i = 0; i < 3; i++)
            {
                for (int a = 0; a < 3; a++) // Replacing the numbers with X using index position
                {
                    if (arr[i][a] == num)
                    {
                        arr[i][a] = 'X';
                        stop = 1;
                    }
                }
                if (stop == 1)
                {
                    stop = 0;
                    break;
                }
            }
            for (int j = 0; j < 3; j++) // Checking for 3 vertical X using for
            {
                count = 0;
                for (int g = 0; g < 3; g++)
                {
                    if (arr[g][j] == 'X')
                    {
                        count += 1;
                    }
                }
                if (count == 3) // Checking if there is any X rows for vertical
                {
                    printf("X won\n");
                    terminate = 0;
                    stop = 1;
                    break;
                }
            }
            if (stop == 1)
            {
                stop = 0; // terminating while loop
                break;
            }

            // Checking for horizontal X
            for (int j = 0; j < 3; j++) // Checking for 3 horizonatal X using for
            {
                count = 0;
                for (int g = 0; g < 3; g++)
                {
                    if (arr[j][g] == 'X')
                    {
                        count += 1;
                    }
                }

                if (count == 3) // Checking if there is any X rows in horizontal
                {
                    printf("X won\n");
                    terminate = 0;
                    stop = 1;
                    break;
                }
            }
            if (stop == 1)
            {
                stop = 0;
                break;
            }

            // Checking diagonals
            if (arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] == 'X')
            {
                printf("X won\n");
                break;
            }

            if (arr[0][2] == 'X' && arr[1][1] == 'X' && arr[2][0] == 'X')
            {
                printf("X won\n");
                break;
            }
        }

        // for O

        if (turn % 2 != 0)
        {
            turn++;
            // printing the game
            for (int h = 0; h < 3; h++)
            {
                for (int k = 0; k < 3; k++)
                {
                    printf("%c \t", arr[h][k]);
                }
                printf("\n");
            }
            printf("Enter where you want to enter O\n");
            scanf(" %c", &num);

            for (int i = 0; i < 3; i++)
            {
                for (int a = 0; a < 3; a++) // Replacing the numbers with O using index position
                {
                    if (arr[i][a] == num)
                    {
                        arr[i][a] = 'O';
                        break;
                    }
                }
            }
            for (int j = 0; j < 3; j++) // Checking for 3 vertical X using for
            {
                count = 0;
                for (int g = 0; g < 3; g++)
                {
                    if (arr[g][j] == 'O')
                    {
                        count += 1;
                    }
                }
                if (count == 3) // Checking if there is any X rows for vertical
                {
                    printf("O won\n");
                    terminate = 0;
                    stop = 1;
                    break;
                }
            }
            
            if (stop == 1)
            {
                stop = 0;
                break;
            }

            // Checking for horizontal X
            for (int j = 0; j < 3; j++) // Checking for 3 horizontal X using for
            {
                count = 0;
                for (int g = 0; g < 3; g++)
                {
                    if (arr[j][g] == 'O')
                    {
                        count += 1;
                    }
                }

                if (count == 3) // Checking if there is any X rows in horizontal
                {
                    printf("O won\n");
                    terminate = 0; 
                    stop = 1;
                    break;
                }
            }
            
            if (stop == 1)
            {
                stop = 0;
                break;
            }

            if (arr[0][0] == 'O' && arr[1][1] == 'O' && arr[2][2] == 'O')
            {
                printf("O won\n");
                break;
            }

            if (arr[0][2] == 'O' && arr[1][1] == 'O' && arr[2][0] == 'O')
            {
                printf("O won\n");
                break;
            }
        }
    }
    return 0;
}
