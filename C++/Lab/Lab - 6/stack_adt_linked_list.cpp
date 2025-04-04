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
            cout << "Stack underflow" << endl;
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
            cout << "Stack underflow" << endl;
            return 'N';
        }

        return head->data;
    }
};

int main()
{
    int choice, exit = 0;
    char value,temp;

    stack s;
    while (exit == 0)
    {
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value" << endl;
            cin >> value;

            s.push(value);
            break;
        case 2:
            temp = s.pop();
            cout << "Deleted value: " << temp << endl;
            break;
        case 3:
            temp = s.peek();
            cout << "The top value: " << temp << endl;
            break;
        case 4:
            s.display();
            break;
        case 5:
            exit = 1;
            break;
        }
    }
}