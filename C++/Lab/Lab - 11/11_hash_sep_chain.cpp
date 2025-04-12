#include <iostream>

using namespace std;

const int SIZE = 10;
const int EMPTY = -1;
const int DELETE = -2;

class sep_chain
{
    struct node
    {
        int data;
        node *next;
    } *head;

    node *table[SIZE];
    int hash(int key)
    {
        int index = key % SIZE;
        return index;
    }

public:
    sep_chain()
    {
        for (int i = 0; i < SIZE; i++)
        {
            table[i] = nullptr;
        }
    }

    void display()
    {
        node *temp;
        for (int i = 0; i < SIZE; i++)
        {
            if (table[i] != nullptr)
            {
                temp = table[i];

                while (temp != nullptr)
                {
                    cout << temp->data << " ";
                    temp = temp->next;
                }
            }
            else
            {
                cout << "Empty";
            }
            cout << endl;
        }
    }

    void insert(int key)
    {
        int index = hash(key);
        node *newnode = new node;
        newnode->data = key;
        newnode->next = nullptr;
        node *temp;

        if (table[index] == nullptr)
        {
            table[index] = newnode;
        }
        else
        {
            temp = table[index];
            table[index] = newnode;
            newnode->next = temp;
        }
    }

    void del(int key)
    {
        int index = hash(key);
        node* temp1 = table[index];
        node* temp2 = table[index];

        if (table[index] == nullptr)
        {
            cout << "No element found" << endl;
        }
        else if (table[index]->data == key)
        {
            table[index] = table[index]->next;
        }
        else
        {
            while(temp1->data != key or temp1!=nullptr)
            {
                temp2 = temp1;
                temp1 = temp1->next;
            }

            if(temp1->next == nullptr)
            {
                temp2->next = nullptr;
                delete temp1;
            }
            else if (temp1->next != nullptr)
            {
                temp2->next = temp1->next;
                delete temp1;
            }
        }
    }

    void search(int key)
    {
        int index = hash(key);
        node* temp = table[index];

        while(temp!=nullptr)
        {
            if(temp->data == key)
            {
                cout << "The value is found" << endl;
                return;
            }
        }
        cout << "The value is not found" << endl;
    }
};

int main()
{
    int exit = 1;
    int choice, value;

    sep_chain sc;

    while (exit)
    {
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit" << endl;

        cin >> choice;

        switch (choice)
        {
        case (1):
            cout << "Enter the value" << endl;
            cin >> value;

            sc.insert(value);
            break;
        case(2):
            cout << "Enter the value to delete" << endl;
            cin >> value;
            sc.del(value);
            break;
        case(3):
            cout << "Enter the value to search" << endl;
            cin >> value;
            sc.search(value);
            break;
        case (4):
            sc.display();
            break;
        case(5):
            exit = 0;
        }
    }
}