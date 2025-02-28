// Program to implement a menu driven program on singly linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

struct node *createnewnode(int data) // Function to create new node
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    (*temp).next = NULL;
    return temp;
}

int length() // Function to find length
{
    struct node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        length++;
    }
    return length;
}

void insertbegin(int data) // Function to insert at the beginning
{
    struct node *newnode = createnewnode(data);
    newnode->next = head;
    head = newnode;
}

struct node *insertend(int data) // Function to insert at the end
{
    struct node *newnode = createnewnode(data);
    struct node *temp = head;
    struct node *temp1=temp;

    if (head == NULL)
    {
        head=newnode;
    }

    while (temp != NULL)
    {
        temp1=temp;
        temp = temp->next;
    }
    temp1->next = newnode;
    return head;
}

int insertposition(int data, int pos) // Function to insert at a given position
{
    struct node *newnode = createnewnode(data);

    if (pos == 1)
    {
        insertbegin(data);
        return 0;
    }
    struct node *temp = head;
    struct node *temp1 = NULL;
    int count = 1;
    while (count < pos && temp != NULL)
    {
        temp1 = temp;
        temp = temp->next;
        count++;
    }
    if (temp == NULL)
    {
        printf("Invalid\n");
        return 0;
    }
    temp1->next = newnode;
    newnode->next = temp;
}

void deletebegin() // Function to delete at beginning
{
    struct node *temp = head;
    if (head->next == NULL)
    {
        free(temp);
    }
    else
    {
        head = temp->next;
        free(temp);
    }
}
void deleteend() // Function to delete at end
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("The list is empty\n");
    }
    else if (temp->next == NULL)
    {
        head = NULL;
    }
    else
    {
        // struct node *temp1;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void deleteposition(int pos) // Funtion to delete to a position
{
    struct node *temp = head;
    struct node *temp1 = temp;
    int count = 1;
    if (pos == 1)
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
            free(temp);
        }
    }
}

void search(int value) // function to search for a number
{
    struct node *temp = head;
    int val = 0;
    while (temp != NULL)
    {
        if ((*temp).data == value)
        {
            printf("Value found\n");
            val = 1;
            break;
        }
        temp = temp->next;
    }
    if (val == 0)
    {
        printf("Not found\n");
    }
}

void display() // Function to Display
{
    if (head == NULL)
    {
        printf("No Elements\n");
    }
    struct node *temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void displayreverse() // Function to display in reverse
{
    struct node *temp = head;
    int len = length();
    int arr[len];
    int count = len - 1;
    while (temp != NULL)
    {
        arr[count] = temp->data;
        temp = temp->next;
        count--;
    }

    for (int i = 0; i < len; i++)
    {
        printf("%d  ", arr[i]);
    }
}

void reverselink() // Function to reverse link
{
    struct node *temp = head;
    int len = length();
    int arr[len];
    int count = len - 1;
    while (temp != NULL)
    {
        arr[count] = temp->data;
        temp = temp->next;
        count--;
    }

    temp=head;
    for (int i = 0; i < len; i++)
    {
        temp->data=arr[i];
        temp=temp->next;
    }
}

int main()
{
    int choice, value, pos;
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
            displayreverse();
            break;
        case 10:
            reverselink();
            break;
        case 11:
            exit(0);
        default:
            printf("\nInvalid Choice\n");
        }
    }
}
