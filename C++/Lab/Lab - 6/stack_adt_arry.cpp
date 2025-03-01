#include <iostream>

using namespace std;

class stack
{
    char arr[5];
    int cur;

public:
    stack()
    {
        cur = 0;
    }

    void display()
    {
        cout << endl;
        if (cur == 0)
        {
            cout << "The stack is empty" << endl;
            return;
        }

        for (int i = 0; i < cur; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void push(int value)
    {
        if (cur == 5)
        {
            cout << "Stack overflow" << endl;
            return;
        }

        for (int i = cur; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = value;
        cur++;
    }

    char pop()
    {
        if (cur == 0)
        {
            cout << "Stack underflow" << endl;
            return 'N';
        }
        else
        {
            char temp = arr[0];

            for (int i = 0; i < cur; i++)
            {
                arr[i] = arr[i + 1];
            }
            cur--;
            return temp;
        }
    }

    char peek()
    {
        if (cur == 0)
        {
            cout << "Stack underflow" << endl;
            return 'N';
        }

        else
        {
            return arr[0];
        }
    }
};

int main()
{
    int choice, exit = 0;
    char value,temp;

    stack s;
    while (exit == 0)
    {
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value" << endl;
            cin >> value;

            s.push(value);
            break;
        case 2:
            temp = s.pop();
            cout << "Deleted value: " << temp << endl;
            break;
        case 3:
            temp = s.peek();
            cout << "The top value: " << temp << endl;
            break;
        case 4:
            s.display();
            break;
        case 5:
            exit = 1;
            break;
        }
    }
}