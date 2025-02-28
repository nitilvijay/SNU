// Program to perform opertion in doubly linked list
#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *head = NULL;

struct node *createnewnode(int data) // Function to create a new node
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insertbegin(int data)
{
    struct node *newnode = createnewnode(data);
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
}

void insertend(int data)
{
    struct node *newnode = createnewnode(data);
    struct node *temp = head;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void display() // Function to display
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("No element present\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

void insertposition(int data, int pos) // Function to insert at postion
{
    struct node *temp = head;
    struct node *temp1;
    int count = 1;
    struct node *newnode = createnewnode(data);
    if (head == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        while (count < pos && temp != NULL)
        {
            temp1 = temp;
            temp = temp->next;
            count++;
        }
        temp->prev = newnode;
        temp1->next = newnode;
        newnode->prev = temp1;
        newnode->next = temp;
    }
}

void deletebegin() // Function to delete at beginning
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("The list is empty\n");
    }
    else if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        temp->next->prev = NULL;
        head = temp->next;
        free(temp);
    }
}

void deleteend() // Function to delete at end
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else if (head->next == NULL)
    {
        head == NULL;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
}

void deleteposition(int pos) // Function to delete at position
{
    struct node *temp = head;
    struct node *temp1;
    int count = 1;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else if (pos == 1)
    {
        deletebegin();
    }
    else
    {
        while (count < pos && temp != NULL)
        {
            temp1 = temp;
            temp = temp->next;
            count++;
        }
        if (temp->next == NULL)
        {
            deleteend();
        }
        else
        {
            temp1->next = temp->next;
            temp->next->prev = temp1;
            free(temp);
        }
    }
}
void search(int value)
{
    struct node *temp = head;
    int term = 0;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->data == value)
            {
                printf("Found\n");
                term = 1;
                break;
            }
            temp=temp->next;
        }
        if (term==0)
        {
            printf("Not found\n");
        }
    }
}
int main()
{
    int choice, value, pos;
    while (1)
    {
        printf("\n1. Insert Beginning\n2. Insert End\n3.Insert Position");
        printf("\n4. Delete Beginning\n5. Delete End\n6. Delete Position");
        printf("\n7. Search\n8. Display\n9. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted: \n");
            scanf("%d", &value);
            insertbegin(value);
            break;
        case 2:
            printf("Enter the value to be inserted: \n");
            scanf("%d", &value);
            insertend(value);
            break;
        case 3:
            printf("Enter the value to be inserted: \n");
            scanf("%d", &value);
            printf("Enter the position\n");
            scanf("%d", &pos);
            insertposition(value, pos);
            break;
        case 4:
            deletebegin();
            break;
        case 5:
            deleteend();
            break;
        case 6:
            printf("Enter the position to delete\n");
            scanf("%d", &pos);
            deleteposition(pos);
            break;
        case 7:
            int value;
            printf("Enter the value to search\n");
            scanf("%d", &value);
            search(value);
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
            break;
        }
    }
}
