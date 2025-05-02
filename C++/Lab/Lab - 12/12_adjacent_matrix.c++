#include <iostream>
#include <vector>
using namespace std;

class adj_mat
{
    int row = 5;
    int col = 5;
    int mat[5][5];

public:
    adj_mat()
    {
        for (int q = 0; q<row; q++)
        {
            for (int k = 0; k<col; k++)
            {
                mat[q][k] = 0;
            }
        }
    }
    void insert(int i, int j)
    {
        if (mat[i][j] == 1)
        {
            cout << "Already exist" << endl;
            return;
        }
        mat[i][j] = 1;
        mat[j][i] = 1;
    
    }

    void del(int i, int j)
    {
        mat[i][j] = 0;
        mat[j][i] = 0;
    }

    void search(int i, int j)
    {
        if (mat[i][j]==1)
        {
            cout << "Available" << endl;
            return;
        }
        cout << "Not Available" <<endl;
    }

    void display()
    {
        for (int a = 0; a<row; a++)
        {
            for (int h = 0; h<col; h++)
            {
                cout << mat[a][h] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int choice, i,j,exit = 1;

    adj_mat am;

    while(exit==1)
    {
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit" << endl;

        cin >> choice;

        switch (choice)
        {
        case (1):
            cout << "Enter the vertex values: i, j" << endl;
            cin >> i;
            cin >> j;

            am.insert(i-1,j-1);
            break;
        case(2):
            cout << "Enter the vertex values to delete: i, j" << endl;
            cin >> i;
            cin >> j;
            am.del(i-1,j-1);
            break;
        case(3):
            cout << "Enter the vertex values to search: i, j" << endl;
            cin >> i;
            cin >> j;
            am.search(i-1,j-1);
            break;
        case (4):
            am.display();
            break;
        case(5):
            exit = 0;
        }
    }
}