#include <iostream>
#include "stck_sll.h"
#include <string>

using namespace std;

void check_balance(string str)
{
    stack s;
    char temp;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            s.push(str[i]);
        }
        else
        {
            if (s.peek() == 'N')
            {
                cout << "It is not Balanced" << endl;
                return;
            }
            temp = s.pop();
        }
    }
    
    if (s.peek() == 'N')
    {
        cout << "It is Balanced" << endl;
    }
    else
    {
        cout << "It is not Balanced" << endl;
    }
}

int main()
{
    string str;
    int exit = 0, choice;

    while (exit == 0)
    {
        cout << "1. Check Balance\n2. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the string" << endl;
            cin >> str;
            check_balance(str);
            break;
        case 2:
            exit = 1;
            break;
        }
    }
}