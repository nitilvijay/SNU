#include <iostream>

using namespace std;

class stack
{
    struct node
    {
        char data;
        struct node *next;
    } *head;

public:
    stack()
    {
        head = nullptr;
    }

    node *create_new_node(char value)
    {
        node *newnode = new struct node;
        newnode->data = value;
        return newnode;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "The stack is empty" << endl;
            return;
        }
        node *temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void push(char value)
    {
        node *newnode = create_new_node(value);
        newnode->next = head;
        head = newnode;
    }

    char pop()
    {
        if (head == nullptr)
        {
            return 'N';
        }
        node *temp = head;
        char value = head->data;

        head = head->next;
        delete temp;

        return value;
    }

    char peek()
    {
        if (head == nullptr)
        {
            return 'N';
        }

        return head->data;
    }
};