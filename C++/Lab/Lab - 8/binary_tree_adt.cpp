#include <iostream>
#include <queue>

using namespace std;

class binary_tree
{
    struct node
    {
        int data;
        node *left;
        node *right;
    };

public:
    node* root;
    binary_tree()
    {
        root = nullptr;
    }

    void insert(node *&root, int value)
    {
        node *newNode = new node;
        newNode->data = value;
        newNode->left = newNode->right = NULL;

        if (root == NULL)
        {
            root = newNode;
            return;
        }

        queue<node *> q;
        q.push(root);

        while (!q.empty())
        {
            node *temp = q.front();
            q.pop();

            if (temp->left == NULL)
            {
                temp->left = newNode;
                break;
            }
            else
            {
                q.push(temp->left);
            }

            if (temp->right == NULL)
            {
                temp->right = newNode;
                break;
            }
            else
            {
                q.push(temp->right);
            }
        }
    }

    void inorder(node *root)
    {
        if (root == nullptr)
        {
            return;
        }

        inorder(root->left);
        cout << root->data << endl;
        inorder(root->right);
    }

    void preorder(node *root)
    {
        if (root == nullptr)
        {
            return;
        }

        cout << root->data << endl;
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(node *root)
    {
        if (root == nullptr)
        {
            return;
        }

        postorder(root->left);
        postorder(root->right);
        cout << root->data << endl;
    }

    bool search(node *root, int value)
    {
        if (root == nullptr)
        {
            return false;
        }

        queue<node *> q;
        q.push(root);

        while (!q.empty())
        {
            node *temp = q.front();
            q.pop();

            if (temp->data == value)
            {
                return true;
            }
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        return false;
    }
};

int main()
{
    binary_tree bt;
    int choice, value;

    while (true)
    {
        cout << "\n1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. Search\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            bt.insert(bt.root, value); // Inserting into the tree
            break;
        case 2:
            cout << "Inorder Traversal: ";
            bt.inorder(bt.root);
            cout << endl;
            break;
        case 3:
            cout << "Preorder Traversal: ";
            bt.preorder(bt.root);
            cout << endl;
            break;
        case 4:
            cout << "Postorder Traversal: ";
            bt.postorder(bt.root);
            cout << endl;
            break;
        case 5:
            cout << "Enter value to search: ";
            cin >> value;
            if (bt.search(bt.root, value))
                cout << "Value found!" << endl;
            else
                cout << "Value not found!" << endl;
            break;
        case 6:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }
    return 0;
}
