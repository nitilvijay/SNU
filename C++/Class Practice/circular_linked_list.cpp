#include <iostream>

using namespace std;

class circular
{
    struct node
    {
        struct node *next;
        int data;
    } *head;

public:
    circular()
    {
        head = NULL;
    }

    node *newnode(int value)
    {

        struct node *temp = new node;
        temp->data = value;
    }
    void display();
    void insert_beginning(int value);
    void insert_end(int value);
    void insert_position(int value, int pos);
};


void circular::insert_beginning(int value)
{
    struct node *newnde = newnode(value);

    if (head == NULL)
    {
        newnde->next = newnde;
    }
    else
    {
        newnde->next = head;
        head = newnde;
    }
}

void circular::insert_end(int value)
{
    struct node *newnde = newnode(value);
    newnde->next = head;
    struct node *temp = head;

    if (head!=NULL)
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnde;
    }
    else
    {
        printf("The list is empty\n");
    }
}

void circular::insert_position(int value, int pos)
{
    
}
