#include <iostream>

using namespace std;

class queue
{
    struct node
    {
        int data;
        struct node *next;
    } *head;

public:
    queue()
    {
        head = nullptr;
    }

    // Create New Node
    struct node *createnewnode(int value)
    {
        struct node *newnode = new struct node;
        newnode->data = value;
        newnode->next = nullptr;

        return newnode;
    }

    //Display
    void display()
    {
        if (head = nullptr)
        {
            cout << "The queue is empty" << endl;
            return;
        }
        node* temp = head;

        while (temp!=nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Insert End
    void enqueue(int value)
    {
        struct node *newnode = createnewnode(value);
        if (head == nullptr)
        {
            head = newnode;
        }
        else
        {
            struct node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }

            temp->next = newnode;
        }
        display();
    }

    // Delete Beginning
    void dequeue()
    {
        if (head == nullptr)
        {
            cout << "The queue is empty";
            return;
        }
        struct node *temp = head;
        head = temp->next;
        free(temp);
        display();
    }

    int peek()
    {
        if (head==nullptr)
        {
            cout << "The queue is empty" << endl;
            return 404;
        }

        node* temp = head;

        while (temp->next!=nullptr)
        {
            temp = temp->next;
        }

        return temp->data;
        
    }
};