#include <iostream>

using namespace std;

#define size 5

class queue
{
    int arr[5];
    int cur;

public:
    queue()
    {
        cur = 0;
    }

    void enqueue(int);

    void dequeue();

    int peek();

    void display();
};

void queue::enqueue(int value)
{
    if (cur == size)
    {
        cout << "The queue is full\n";
    }

    arr[cur] = value; // This can alos be written as arr[cur++] = value
    cur++;
    display();
}

void queue::dequeue()
{
    if (cur == 0)
    {
        cout << "The queue emptyt\n";
    }

    for (int i = 0; i < (cur - 1); i++)
    {
        arr[i] = arr[i + 1];
    }
    cur--;
    display();
}

int queue::peek()
{
    if (cur == 0)
    {
        cout << "The Queue is empty" << endl;
        return 404;
    }
    return arr[cur - 1];
}

void queue::display()
{
    for(int i = 0; i<5; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}

int main()
{
    queue ca;
    int exit = 1;

    while (exit == 1)
    {
        int choice, val;
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value: ";
            cin >> val;
            ca.enqueue(val);
            break;
        case 2:
            ca.dequeue();
            break;
        case 3:
            val = ca.peek();
            if (val != 404)
            {
                cout << "Front element: " << val << endl;
            }
            break;
        case 4:
            exit = 0;
            break;
        }
    }

    return 0;
}