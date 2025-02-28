#include <iostream>

using namespace std;

class list
{
    struct node
    {
        int data;
        struct node *next;
    } *head;

public:
    list()
    {
        head = NULL;
    }
    struct node *gethead()
    {
        return head;
    }

    // Create New Node
    struct node *createnewnode(int value)
    {
        struct node *newnode = new struct node;
        newnode->data = value;
        newnode->next = NULL;

        return newnode;
    }

    // Insert Acsending
    void insert_ascending(int value)
    {
        struct node *newnode = createnewnode(value);

        if (head == NULL)
        {
            newnode->next = NULL;
            head = newnode;
            return;
        }
        struct node *temp = head;
        if (head->data > value)
        {
            // Insert at the beginning if list is empty or head is greater
            newnode->next = head;
            head = newnode;
        }
        else
        {
            // Traverse to find correct insertion point
            while (temp->next != NULL && temp->next->data < value)
            {
                temp = temp->next;
            }
            // Insert newnode in the correct position
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
    list merge(list l1, list l2)
    {
        list l3;
        struct node *temp1 = l1.gethead();
        struct node *temp2 = l2.gethead();
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->data < temp2->data)
            {
                l3.insert_ascending(temp1->data);
                temp1 = temp1->next;
            }
            else
            {
                l3.insert_ascending(temp2->data);
                temp2 = temp2->next;
            }
        }
        while (temp1 != NULL)
        {
            l3.insert_ascending(temp1->data);
            temp1 = temp1->next;
        }
        while (temp2 != NULL)
        {
            l3.insert_ascending(temp2->data);
            temp2 = temp2->next;
        }
        return l3;
    }
    void display()
    {
        struct node *temp = head;
        if (head == NULL)
        {
            cout << "List is empty";
        }
        else
        {
            while (temp != NULL)
            {
                cout << temp->data << " ->";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};