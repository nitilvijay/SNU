#include <iostream>

using namespace std;

class list
{
    struct node
    {
        struct node *prev;
        int data;
        struct node *next;
    } *head;

public:
    list()
    {
        head = NULL;
    }

    struct node *newnode(int value)
    {
        struct node *newnode = new struct node;
        newnode->data = value;

        return newnode;
    }

    void display()
    {
        struct node *temp = head;

        if (head == NULL)
        {
            cout << "The list empty\n";
        }
        else
        {
            while (temp != NULL)
            {
                cout << temp->data << "->";
                temp = temp->next;
            }
        }
    }

    void insert_beginning(int value)
    {
        struct node *node = newnode(value);

        node->prev = NULL;
        node->next = head;

        head = node;
    }

    void insert_end(int value)
    {
        struct node *temp = head;
        struct node *node = newnode(value);
        node->next = NULL;

        if (head == NULL)
        {
            head = node;
            node->prev = NULL;
        }

        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            node->prev = temp;
            temp->next = node;
        }
    }
    void insert_position(int value, int pos)
    {
        while (int i=0, i<pos, i++)
        {
            
        }
    }
};

int main()
{

    list l;
    int exit = 1;

    while (exit)
    {
        int choice, value, pos, k;

        cout << "\nEnter choice:\n"
             << "1. Insert Beginning\n2. Insert End\n3. Insert Position\n"
             << "4. Delete Beginning\n5. Delete End\n6. Delete Position\n"
             << "7. Search\n8. Display\n9. Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            l.insert_beginning(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            l.insert_end(value);
            break;
        case 3:
            cout << "Enter value: \n";
            cin >> value;
            cout << "Enter the position";
            cin >> pos;
            l.insert_position(value, pos);
        case 8:
            l.display();
            break;
        case 9:
            exit = 0;
            break;
        }
    }
}