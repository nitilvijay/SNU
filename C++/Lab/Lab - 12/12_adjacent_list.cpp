#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class adj_list
{
    struct Node
    {
        vector<int> data;
        Node *next;
        Node() : data(2) {}
    };

    Node *lst[7];

public:
    adj_list()
    {

        for (int i = 0; i < 7; i++)
        {
            lst[i] = nullptr;
        }
    }
    bool search(int i, int j)
    {
        Node *head = lst[i];
        while (head != nullptr)
        {
            if ((head->data)[0] == j)
            {
                return true;
            }
            head = head->next;
        }
        return false;
    }

    Node *insert_linked_list(Node *head, int i, int j, int wght)
    {
        Node *newnode = new Node;
        newnode->next = head;
        newnode->data[0] = i;
        (newnode->data)[1] = j;
        (newnode->data)[2] = wght;

        head = newnode;
        return head;
    }

    void insert(int i, int j, int wght)
    {
        if (!search(i, j))
        {
            lst[i] = insert_linked_list(lst[i], i, j, wght);
            lst[j] = insert_linked_list(lst[j], j, i, wght);
        }
    }

    void del(int i, int j)
    {
        Node *head1 = lst[i];
        Node *head2 = lst[j];
        Node *temp;
        bool found;

        if (head1 == nullptr or head2 == nullptr)
        {
            cout << "Not Available" << endl;
            return;
        }
        if (head1->data[1] == j)
        {
            lst[i] = head1->next;
            found = true;
        }

        while (head1->next != nullptr and found != true)
        {
            if (head1->next->data[1] == j)
            {
                temp = head1->next->next;
                head1->next = temp;
                lst[i] = head1;
                break;
            }
            head1 = head1->next;
        }

        if (head2->data[1] == i)
        {
            lst[j] = head2->next;
            return;
        }

        while (head2->next != nullptr)
        {
            if (head2->next->data[1] == i)
            {
                temp = head2->next->next;
                head2->next = temp;
                lst[j] = head2;
                return;
            }
            head2 = head2->next;
        }
        cout << "Value Not found" << endl;
    }

    void display()
    {
        for (int i = 0; i < 7; i++)
        {
            Node *head = lst[i];
            cout << i << " - ";
            if (head == nullptr)
            {
                cout << "nullptr" << " ";
            }
            while (head != nullptr)
            {
                cout << "(" << head->data[0] << " " << head->data[1] << " " << head->data[2] << ") ";
                head = head->next;
            }
            cout << endl;
        }
    }

    void prims()
    {
        priority_queue<vector<int>, vector<vector<int>>, std::greater<vector<int>>> pq;
        vector<int> visited(7, 0); // Assuming 7 vertices: 0 through 6
        vector<vector<int>> path;
        Node *head;
        int sum = 0;

        pq.push({0, 0, 0}); // cost, from, to

        while (!pq.empty())
        {
            vector<int> top = pq.top();
            pq.pop();

            int cost = top[0];
            int from = top[1];
            int to = top[2];

            if (visited[to] == 0)
            {
                visited[to] = 1;
                sum += cost;

                if (from != to) // skip the initial self-edge
                    path.push_back({from, to});

                head = lst[to];
                while (head != nullptr)
                {
                    pq.push({head->data[2], to, head->data[1]}); // cost, from=to, to=neighbor
                    head = head->next;
                }
            }
        }

        for (const auto &edge : path)
        {
            cout << "(" << edge[0] << "," << edge[1] << ") ";
        }
        cout << endl;
        cout << "The sum: " << sum << endl;
    }
};

int main()
{
    adj_list al;
    int choice, i, j, wght, exit = 1;

    while (exit == 1)
    {
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display\n5. Prims\n6. Exit" << endl;

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
            al.prims();
            break;
        case (6):
            exit = 0;
        }
    }
}