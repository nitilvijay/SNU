#include <iostream>

using namespace std;

class list
{
    struct node
    {
        node *prev;
        int data;
        node *next;
    } *head;

public:
    list()
    {
        head = nullptr;
    }

    struct node *create_new_node(int value)
    {
        node *newnode = new struct node;
        newnode->data = value;
        return newnode;
    }

    void display()
    {
        node *temp = head;
        if (head == nullptr)
        {
            cout << "The list is empty" << endl;
            return;
        }

        cout << temp->data << " ";
        temp = temp->next;

        while (temp != head)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void insert_beginning(int value)
    {
        node *newnode = create_new_node(value);
        node *temp = head;
        if (head == nullptr)
        {
            head = newnode;
            newnode->next = head;
            return;
        }

        while (temp->next != head)
        {
            temp = temp->next;
        }

        newnode->next = head;
        head = newnode;
        temp->next = head;
    }

    void insert_end(int value)
    {
        node *newnode = create_new_node(value);

        if (head == nullptr)
        {
            head = newnode;
            newnode->next = head;
            return;
        }

        node *temp = head;

        newnode->next = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }

    void insert_position(int value, int pos)
    {
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

        node *newnode = create_new_node(value);
        node *temp = head;
        int count = 1;

        while (count < pos - 1 && temp != nullptr)
        {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr)
        {
            cout << "Out Of Bound" << endl;
            return;
        }
        if (temp->next == nullptr)
        {
            insert_end(value);
            return;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }

    void delete_beginning()
    {
        if (head == nullptr)
        {
            cout << "The list is empty" << endl;
            return;
        }
        if (head->next == head)
        {
            head = nullptr;
            return;
        }

        node *temp = head;
        node *temp1 = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        head = head->next;
        delete temp1;
        temp->next = head;
    }

    void delete_end()
    {
        if (head == nullptr)
        {
            cout << "The list is empty" << endl;
            return;
        }
        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }
        node *temp = head;

        while (temp->next->next != head)
        {
            temp = temp->next;
        }

        node *todelete = temp->next;
        temp->next = head;
        delete todelete;
    }
    void delete_position(int pos)
    {
        if (pos < 1)
        {
            cout << "Invalid" << endl;
            return;
        }

        if (head == nullptr)
        {
            cout << "The list is empty" << endl;
            return;
        }
        if (pos == 1)
        {
            delete_beginning();
            return;
        }

        node *temp = head;
        int count = 1;

        while (count < pos - 1 && temp != head)
        {
            temp = temp->next;
            count++;
        }

        if (temp == head)
        {
            cout << "Out of Bound" << endl;
            return;
        }
        node *temp1;
        temp1 = temp->next;

        temp->next = temp->next->next;

        delete temp1;
    }

    void search(int value)
    {
        if (head == nullptr)
        {
            cout << "The lsit is empty" << endl;
            return;
        }
        struct node *temp = head;

        do
        {
            if (temp->data == value)
            {
                cout << "The value is found: " << value << "\n";
                return;
            }
            temp = temp->next;
        } while (temp->next != NULL);

        cout << "The number is not found\n";
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
        // case 7:
        //     cout << "Enter the Value" << endl;
        //     cin >> value;

        //     l.search(value);
        //     break;
        case 8:
            l.display();
            break;
        case 9:
            exit = 0;
            break;
        }
    }
}