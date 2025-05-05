#include <cstdio>
#include <cstdlib>
#include "circular_list.h"

int main()
{
    sll l1;
    int choice, time, res;
    
    while (1)
    {
        printf("\n1. Insert process\n2. Execute\n3. Exit\n");
        printf("Enter menu number of operation you want to perform: ");
        scanf("%d", &choice);
        
        while (choice < 1 || choice > 3)
        {
            printf("Error. Enter a valid menu number: ");
            scanf("%d", &choice);
        }
        
        switch (choice)
        {
        case 1:
        {
            printf("Enter integer time: ");
            scanf("%d", &time);
            
            while (time <= 0)
            {
                printf("Error. Enter a valid process time: ");
                scanf("%d", &time);
            }
            
            res = l1.insert_end(time);
            if (res == 1)
            {
                printf("Process with time %d has been inserted.\n", time);
            }
            else
            {
                printf("Failed to insert process.\n");
            }
            break;
        }
        case 2:
        {
            printf("Enter fixed processing time (quantum): ");
            scanf("%d", &time);
            
            while (time <= 0)
            {
                printf("Error. Enter a valid quantum time: ");
                scanf("%d", &time);
            }
            
            res = l1.execute(time);
            if (res == -1)
            {
                printf("Process queue is empty.\n");
            }
            break;
        }
        case 3:
        {
            printf("Exiting program...\n");
            exit(0);
            break;
        }
        default:
        {
            printf("Error: Invalid choice.\n");
            break;
        }
        }
    }
    
    return 0;
}