#include <iostream>

using namespace std;

class list
{
    struct node
    {
        struct node *prev;
        int data;
        struct node *next;
    } *head, *tail;

public:
    list()
    {
        head = NULL;
        tail = NULL;
    }

    struct node *create_new_node(int value)
    {
        struct node *newnode = new struct node;
        newnode->data = value;

        return newnode;
    }

    void display() // Time complexity: O(n)
    {
        struct node *temp = head;
        if (temp == NULL)
        {
            cout << "The list empty" << endl;
            return;
        }

        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void insert_beginning(int value) // Time complexity: O(1)
    {
        struct node *newnode = create_new_node(value);

        newnode->next = head;
        newnode->prev = NULL;

        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            head = newnode;
        }
    }

    void insert_end(int value) // Time complexity: O(1)
    {
        struct node *newnode = create_new_node(value);

        if (head == NULL)
        {
            insert_beginning(value);
            return;
        }
        tail->next = newnode;
        newnode->next = NULL;
        newnode->prev = tail;
        tail = newnode;
    }

    void insert_position(int value, int pos) // Time complexity: O(n)
    {
        int i;
        struct node *newnode = create_new_node(value);
        struct node *temp = head;

        if (pos < 1)
        {
            cout << "Invalid" << endl;
            return;
        }

        if (pos == 1)
        {
            insert_beginning(value);
            return;
        }

        for (i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Out of bound" << endl;
            return;
        }

        if (temp->next == NULL)
        {
            insert_end(value);
            return;
        }

        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
        newnode->prev = temp;
    }

    void delete_beginning() // Time complexity: O(1)
    {
        if (head == NULL)
        {
            cout << "The list is empty" << endl;
            return;
        }
        struct node *temp = head;
        head = head->next;
        delete temp;
    }

    void delete_end() // Time complexity: O(1)
    {
        if (head == NULL)
        {
            cout << "The list is empty" << endl;
            return;
        }
        if (head->next == NULL)
        {
            head = NULL;
            tail = NULL;
            return;
        }
        struct node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
    }

    void delete_position(int pos) // Time complexity: O(n)
    {
        struct node *temp = head;
        int i;

        if (head == NULL)
        {
            cout << "The list is empty" << endl;
            return;
        }
        if (pos < 1)
        {
            cout << "Invalid" << endl;
            return;
        }
        if (pos == 1)
        {
            delete_beginning();
            return;
        }

        for (i = 1; i < pos && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Out of bound" << endl;
            return;
        }

        if (temp->next == NULL)
        {
            delete_end();
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
    }

    void search(int value) // Time complexity: O(n)
    {
        struct node *temp = head;
        if (head == NULL)
        {
            cout << "The list empty" << endl;
            return;
        }
        while (temp != NULL)
        {
            if (temp->data == value)
            {
                cout << "The value is found" << endl;
                break;
            }
            temp = temp->next;
        }
    }
};

int main()
{
    int value, choice, pos, exit = 1;
    list l;

    while (exit == 1)
    {
        cout << "\n1. Insert Beginning  2. Insert end  3. Insert Position\n4. Delete Beginning  5. Delete End  6. Delete position\n7. Search            8. Display     9. Exit\n";
            cout
             << "Enter the choice" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value" << endl;
            cin >> value;

            l.insert_beginning(value);
            break;
        case 2:
            cout << "Enter the value" << endl;
            cin >> value;

            l.insert_end(value);
            break;
        case 3:
            cout << "Enter the Value" << endl;
            cin >> value;

            cout << "Enter the position" << endl;
            cin >> pos;

            l.insert_position(value, pos);
            break;
        case 4:
            l.delete_beginning();
            break;
        case 5:
            l.delete_end();
            break;
        case 6:
            cout << "Enter the position" << endl;
            cin >> pos;

            l.delete_position(pos);
            break;
        case 7:
            cout << "Enter the Value" << endl;
            cin >> value;

            l.search(value);
            break;
        case 8:
            l.display();
            break;
        case 9:
            exit = 0;
            break;
        }
    }
}