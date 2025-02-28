#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
void display()
{
    if (head == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        struct node *temp = head;
        while (temp != NULL)
        {
            printf("%d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
struct node *insertbegin(int data)
{
    struct node *newnode = createnode(data);
    newnode->next = head;
    head = newnode;
    return newnode;
}
struct node *insertafter(int key, int data)
{
    if (head = NULL)
    {
        printf("The list is empty\n");
    }
}
int main()
{
    int choice, value, pos, key;
    while (1)
    {
        printf("\n1. Insert Beginning\n2. Insert End\n3.Insert Position");
        printf("\n4. Delete Beginning\n5. Delete End\n6. Delete Position");
        printf("\n7. Search\n8. Display\n9. Display Reverse\n10. Reverse Link\n11. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted: \n");
            scanf("%d", &value);
            insertbegin(value);
            break;
        //case 2:
            // display();
        // case 3:
        //     printf("Enter the value to be inserted: \n");
        //     scanf("%d", &value);
        //     printf("Enter the position\n");
        //     scanf("%d", &pos);
        //     insertposition(value, pos);
        //     break;
        case 8:
            display();
        }
    }
}