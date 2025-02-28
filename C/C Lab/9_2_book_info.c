#include <stdio.h>

struct book
{
    char title[30];
    char author[30];
    int price;
};
int main()
{
    int size, choice, total;

    printf("Enter the number of books to be bought\n"); // Getting number of books to be bought
    scanf("%d", &size);

    struct book arr[size];
    char term = 'y';
    while (term == 'y')
    {
        printf("Enter number\n 1.Input\n 2.Display\n 3.Total\n");
        scanf("%d", &choice);

        if (choice == 1) // Input
        {
            for (int i = 0; i < size; i++)
            {
                printf("For book %d\n", i + 1);

                printf("Enter the title \n");
                scanf(" %s", arr[i].title);

                printf("Enter the author name\n");
                scanf(" %s", arr[i].author);

                printf("Enter the price\n");
                scanf("%d", &arr[i].price);
            }
            printf("Enter y if you want to continue\n");
            scanf(" %c", &term);
        }

        else if (choice == 2) // Display
        {
            for (int i = 0; i < size; i++)
            {
                printf("For book %d\n", i + 1);

                printf("Title: %s\n", arr[i].title);

                printf("Author name: %s\n", arr[i].author);

                printf("Price: %d\n", arr[i].price);
            }
            printf("Enter y if you want to continue\n");
            scanf(" %c", &term);
        }

        else if (choice == 3) // Total
        {
            for (int i = 0; i < size; i++)
            {
                total += arr[i].price;
            }
            printf("%d\n",total);
            printf("Enter y if you want to continue\n");
            scanf(" %c", &term);
        }
    }
}