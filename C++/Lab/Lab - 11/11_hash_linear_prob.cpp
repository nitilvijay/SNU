#include <iostream>

using namespace std;

const int SIZE = 10;
const int EMPTY = -1;
const int DELETE = -2;

class linear_probbing
{
    int table[SIZE];

    int hash(int num)
    {
        int index = num % SIZE;
        return index;
    }

public:
    linear_probbing()
    {
        for (int i = 0; i < SIZE; i++)
        {
            table[i] = EMPTY;
        }
    }

    void display()
    {
        for (int i = 0; i<SIZE; i++)
        {
            if(table[i] == EMPTY)
            {
                cout << "Empty" << " ";
            }
            else if(table[i] == DELETE)
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
        int index = hash(key);
        int temp = index;

        while(table[index] != EMPTY and table[index] != DELETE)
        {
            index = (index+1)%SIZE;

            if(index == temp)
            {
                cout << "The table is full" << endl;
                break;
            }
        }

        table[index] = key;
    }

    void del(int key)
    {
        int index = hash(key);
        int temp = index;

        while (table[index] != key)
        {
            index = (index+1)%SIZE;

            if(index == temp)
            {
                cout << "The key is not found" << endl;
                break;
            }
        }

        table[index] = DELETE;
    }

    void search(int key)
    {
        int index = hash(key);
        int temp = index;

        while (table[index] != key)
        {
            index = (index+1)%SIZE;

            if(index == temp)
            {
                cout << "The key is not found" << endl;
                return;
            }
        }

        cout << "The element is found" << endl;
    }
};

int main()
{
    int exit = 1;
    int choice, value;

    linear_probbing lp;

    while(exit)
    {
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit" << endl;

        cin >> choice;

        switch(choice)
        {
            case(1):

                cout << "Enter the value" << endl;
                cin >> value;

                lp.insert(value);
                break;
            case(2):
                cout << "Enter the value to delete" << endl;
                cin >> value;

                lp.del(value);
                break;
            case(3):
                cout << "Enter the value to search" << endl;
                cin >> value;

                lp.search(value);
                break;
            case(4):
                lp.display();
                break;
            case(5):
                exit = 0;
        }
    }
}