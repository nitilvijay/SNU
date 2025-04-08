#include <iostream>
#include <stack>
#include <cctype> // For isalpha(), isdigit()
#include <string>

using namespace std;

class ExpressionTree
{
private:
    // Define a tree node structure
    struct Node
    {
        char value;
        Node *left;
        Node *right;

        Node(char val) : value(val), left(nullptr), right(nullptr) {}
    };


public:

    Node *root;
    // Constructor
    ExpressionTree() : root(nullptr) {}

    // Public function to build the expression tree from a postfix string
    void buildFromPostfix(const string &postfix)
    {
        // Use a stack to hold tree nodes
        stack<Node *> st;

        for (char ch : postfix)
        {
            // If it's an operand (letter or digit), create a new node and push
            if (isalpha(ch))
            {
                Node *newNode = new Node(ch);
                st.push(newNode);
            }
            // If it's an operator, pop two nodes, make them children, push back
            else if (isdigit(ch))
            {
                // Pop two nodes
                if (st.size() < 2)
                {
                    cerr << "Invalid postfix expression!" << endl;
                    return;
                }
                Node *rightNode = st.top();
                st.pop();
                Node *leftNode = st.top();
                st.pop();

                // Create a new node for the operator
                Node *newNode = new Node(ch);
                newNode->left = leftNode;
                newNode->right = rightNode;

                // Push the operator node back onto the stack
                st.push(newNode);
            }
            // Ignore any whitespace or invalid characters
        }

        // After processing all characters, the stack should have exactly one node
        if (st.size() == 1)
        {
            root = st.top();
            st.pop();
        }
        else
        {
            cerr << "Invalid postfix expression or mismatch in operands/operators!" << endl;
            root = nullptr;
        }
    }

    void inorder(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }

        inorder(root->left);
        cout << root->value << endl;
        inorder(root->right);
    }

    void preorder(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        
        cout << root->value << endl;
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }

        postorder(root->left);
        postorder(root->right);
        cout << root->value << endl;
    }
};

int main()
{
    ExpressionTree et;
    string postfix;

    int choice;
    while (true)
    {
        cout << "\n---- MENU ----\n"
             << "1. Postfix Expression\n"
             << "2. Construct Expression Tree\n"
             << "3. Preorder\n"
             << "4. Inorder\n"
             << "5. Postorder\n"
             << "6. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter a valid postfix expression (single-char operands): ";
            cin >> postfix;
            break;

        case 2:
            et.buildFromPostfix(postfix);
            cout << "Expression tree constructed.\n";
            break;

        case 3:
            cout << "Preorder Traversal: ";
            et.preorder(et.root);
            break;

        case 4:
            cout << "Inorder Traversal: ";
            et.inorder(et.root);
            break;

        case 5:
            cout << "Postorder Traversal: ";
            et.postorder(et.root);
            break;

        case 6:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}