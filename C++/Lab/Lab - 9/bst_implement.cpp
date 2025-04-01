#include <iostream>

using namespace std;

class binary_search_tree
{
    struct node
    {
        node *left;
        node *right;
        int value;
    };

public:
    node *root;
    binary_search_tree()
    {
        root = nullptr;
    }

    void insert(int value)
    {
        node *newnode = new node;
        newnode->left = newnode->right = nullptr;
        newnode->value = value;

        if (root == nullptr)
        {
            root = newnode;
            return;
        }

        node *temp = root;

        while (temp != nullptr)
        {
            if (temp->value > value)
            {
                if (temp->left == nullptr)
                {
                    temp->left = newnode;
                    return;
                }

                temp = temp->left;
            }
            else
            {
                if (temp->right == nullptr)
                {
                    temp->right = newnode;
                    return;
                }

                temp = temp->right;
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
        cout << root->value << endl;
        inorder(root->right);
    }

    void preorder(node *root)
    {
        if (root == nullptr)
        {
            return;
        }

        cout << root->value << endl;
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
        cout << root->value << endl;
    }

    void search(int value)
    {
        if (root == nullptr)
        {
            cout << "Empty" << endl;
            return;
        }

        node *temp = root;

        while (temp != nullptr)
        {
            if (temp->value == value)
            {
                cout << "The value is found" << endl;
                return;
            }
            else if (value < temp->value)
            {
                temp = temp->left;
            }
            else if (value > temp->value)
            {
                temp = temp->right;
            }
        }
        if (temp == nullptr)
        {
            cout << "The value is not found" << endl;
            return;
        }
    }
};

int main()
{
    binary_search_tree bst;
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
            bst.insert(value); // Inserting into the tree
            break;
        case 2:
            cout << "Inorder Traversal: " << endl;
            bst.inorder(bst.root);
            cout << endl;
            break;
        case 3:
            cout << "Preorder Traversal: " << endl;
            bst.preorder(bst.root);
            cout << endl;
            break;
        case 4:
            cout << "Postorder Traversal: " << endl;
            bst.postorder(bst.root);
            cout << endl;
            break;
        case 5:
            cout << "Enter value to search: ";
            cin >> value;
            bst.search(value);
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
