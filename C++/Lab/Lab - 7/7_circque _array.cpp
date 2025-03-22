#include <iostream>
using namespace std;

class circ_arr
{
    int front = 0; // Front index
    int rear = 0;  // Rear index
    int cur = 0;   // Tracks current number of elements
    int arr[5];    // Array of size 5

public:
    void enqueue(int value)
    {
        if (cur == 5)
        {
            cout << "The Queue is full" << endl;
            return;
        }

        arr[rear] = value;
        rear = (rear + 1) % 5; // Circular increment
        cur++;                 // Increment element count
        display();
    }

    int dequeue()
    {
        if (cur == 0)
        {
            cout << "The Queue is empty" << endl;
            return 404;
        }

        int temp = arr[front];
        front = (front + 1) % 5; // Circular increment
        cur--;                   // Decrement element count
        display();
        return temp;
    }

    int peek()
    {
        if (cur == 0)
        {
            cout << "The Queue is empty" << endl;
            return 404;
        }
        return arr[front];
    }

    void display()
    {
        if (cur == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        int i = front;
        for (int count = 0; count < cur; count++)
        {
            cout << arr[i] << " ";
            i = (i + 1) % 5; // Circular increment
        }
        cout << endl;
    }
};

int main()
{
    circ_arr ca;
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
            val = ca.dequeue();
            if (val != 404)
            {
                cout << "Dequeued: " << val << endl;
            }
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
