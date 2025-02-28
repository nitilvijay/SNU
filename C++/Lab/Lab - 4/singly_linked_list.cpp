#include <iostream>
using namespace std;

// Implementing singly linked list

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

    // Create New Node
    struct node *createnewnode(int value)
    {
        struct node *newnode = new struct node;
        newnode->data = value;
        newnode->next = NULL;

        return newnode;
    }

    // Display
    void display()
    {
        struct node *temp = head;
        if (head == NULL)
        {
            cout << "The list is empty\n";
        }
        else
        {
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
    }

    // Insert Beginning
    void insert_beginning(int value)
    {
        struct node *newnode = createnewnode(value);
        newnode->next = head;
        head = newnode;
    }

    // Insert End
    void insert_end(int value)
    {
        struct node *newnode = createnewnode(value);
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            struct node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newnode;
        }
    }
    // Insert Position
    void insert_position(int value, int pos)
    {
        if (pos < 1)
        {
            cout << "Invalid\n";
            return;
        }
        if (pos == 1)
        {
            insert_beginning(value);
            return;
        }
        int count = 1;
        struct node *newnode = createnewnode(value);
        struct node *temp = head;

        while (count < pos - 1 && temp->next != NULL)
        {
            temp = temp->next;
            count++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

    // Delete Beginning
    void delete_beginning()
    {
        if (head == NULL)
        {
            cout << "The List is empty";
            return;
        }
        struct node *temp = head;
        head = temp->next;
        free(temp);
    }

    // Delete End
    void delete_end()
    {
        if (head == NULL)
        {
            cout << "The list is empty\n";
            return;
        }
        if (head->next == NULL)
        {
            head = NULL;
            return;
        }
        struct node *temp = head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;
    }

    // Delete Position
    void delete_position(int pos)
    {
        if (pos < 1 || head == NULL)
        {
            cout << "Invalid input\n";
            return;
        }
        if (pos == 1)
        {
            delete_beginning();
            return;
        }

        struct node *temp = head;
        int count = 1;

        while (count < pos - 1 && temp->next != NULL)
        {
            temp = temp->next;
            count++;
        }

        if (temp->next == nullptr)
        {
            cout << "Position out of bounds!" << endl;
            return;
        }

        temp->next = temp->next->next;
    }

    void search(int value)
    {
        if (head == NULL)
        {
            cout << "The lsit is empty\n";
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

    void display_reverse()
    {
        int arr[50];
        struct node *temp = head;
        int count = 0;

        if (head == NULL)
        {
            cout << "The list is empty\n";
            return;
        }
        while (temp != NULL)
        {
            arr[count] = temp->data;
            temp = temp->next;
            count++;
        }
        for (int i = count - 1; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    void reverse_link()
    {
        node *curr = head, *prev = nullptr, *next;

        // Traverse all the nodes of Linked List
        while (curr != nullptr)
        {

            // Store next
            next = curr->next;

            // Reverse current node's next pointer
            curr->next = prev;

            // Move pointers one position ahead
            prev = curr;
            curr = next;
        }
        head = prev;
    }
};

int main()
{
    int choice, value, pos, exit = 0;

    class list l;
    while (exit != 1)
    {
        cout << "\n1. Insert Beginning  2. Insert end  3. Insert Position\n4. Delete Beginning  5. Delete End  6. Delete position\n7. Search            8. Display     9.Display Reverse\n10. Reverse Link\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to be inserted\n";
            cin >> value;
            l.insert_beginning(value);
            break;
        case 2:
            cout << "Enter the value to be inserted\n";
            cin >> value;
            l.insert_end(value);
            break;
        case 3:
            cout << "Enter the value\n";
            cin >> value;
            cout << "Enter the position\n";
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
            cout << "Enter the position\n";
            cin >> pos;
            l.delete_position(pos);
            break;
        case 7:
            cout << "Enter the value\n";
            cin >> value;
            l.search(value);
            break;
        case 8:
            l.display();
            break;
        case 9:
            l.display_reverse();
            break;
        case 10:
            l.reverse_link();
            break;
        case 11:
            exit = 1;
            break;
        }
    }
}