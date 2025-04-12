#include <iostream>

using namespace std;

const int SIZE = 10;
const int EMPTY = -1;
const int DELETE = -2;

class quad_prob
{
    int table[SIZE];

    int hash(int key)
    {
        int index = key % SIZE;
        return index;
    }

public:
    quad_prob()
    {
        for (int i = 0; i < SIZE; i++)
        {
            table[i] = EMPTY;
        }
    }

    void display()
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (table[i] == EMPTY)
            {
                cout << "Empty" << " ";
            }
            else if (table[i] == DELETE)
            {
                cout << "Deleted" << " ";
            }
            else
            {
                cout << table[i] << " ";
            }
        }
        cout << endl;
    }

    void insert(int key)
    {
        int i = 1;
        int index = hash(key);
        int newindex = index;

        while (table[newindex] != EMPTY and table[newindex] != DELETE)
        {
            if (i == SIZE)
            {
                cout << "The table is full" << endl;
                return;
            }

            newindex = (index + (i * i)) % SIZE;
            i++;
        }

        table[newindex] = key;
    }

    void del(int key)
    {
        int i = 1;
        int index = hash(key);
        int newindex = index;

        while (table[newindex] != key)
        {
            if (i == SIZE)
            {
                cout << "Element not found" << endl;
                return;
            }

            newindex = (index + (i * i)) % SIZE;
            i++;
        }
        table[newindex] = DELETE;
    }

    void search(int key)
    {
        int i = 1;
        int index = hash(key);
        int newindex = index;

        while (table[newindex] != key)
        {
            if (i == SIZE)
            {
                cout << "Element not found" << endl;
                return;
            }

            newindex = (index + (i * i)) % SIZE;
            i++;
        }
        cout << "The element is found" << endl;
    }
};

int main()
{
    int exit = 1;
    int choice, value;

    quad_prob qp;

    while (exit)
    {
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit" << endl;

        cin >> choice;

        switch (choice)
        {
        case (1):

            cout << "Enter the value" << endl;
            cin >> value;
            qp.insert(value);
            break;
        case (2):
            cout << "Enter the element to delete" << endl;
            cin >> value;
            qp.del(value);
            break;
        case (3):
            cout << "Enter the element to search" << endl;
            cin >> value;
            qp.search(value);
            break;
        case (4):

            qp.display();
            break;
        case(5):
            exit = 0;
        }
    }
}