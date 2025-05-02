#include <iostream>
#include "adj_lst.h"
#include <vector>

using namespace std;

int main()
{
    adj_list al;
    int choice, i, j, wght, exit = 1;
    al.lst[1];

    while (exit == 1)
    {
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit" << endl;

        cin >> choice;

        switch (choice)
        {
        case (1):
            cout << "Enter the vertex values: i, j, wght" << endl;
            cin >> i;
            cin >> j;
            cin >> wght;

            al.insert(i, j, wght);
            break;
        case (2):
            cout << "Enter the vertex values to delete: i, j" << endl;
            cin >> i;
            cin >> j;
            al.del(i, j);
            break;
        case (3):
            cout << "Enter the vertex values to search: i, j" << endl;
            cin >> i;
            cin >> j;
            if (al.search(i, j))
            {
                cout << "Available" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
            break;
        case (4):
            al.display();
            break;
        case (5):
            exit = 0;
        }
    }
}