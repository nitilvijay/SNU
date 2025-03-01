#include <iostream>
#include "stck_sll.h"
#include <string>
#include <cmath>

using namespace std;

int precedence(char op)
{
    if (op == '^')
        return 3; // Highest precedence
    if (op == '*' || op == '/')
        return 2; // Multiplication/Division
    if (op == '+' || op == '-')
        return 1; // Addition/Subtraction
    return 0;
}

string get_infix()
{
    string op;
    cout << "Enter the string" << endl;
    cin >> op;
    return op;
}

string convert_infix(string op)
{
    string exp;
    stack s;

    for (int i = 0; i < op.length(); i++)
    {
        if (isdigit(op[i]))
        {
            exp = exp + op[i];
        }
        else
        {
            int pre = precedence(op[i]);

            if (s.peek() == '^' && op[i] == '^')
            {
                s.push(op[i]);
            }
            else
            {

                while (precedence(s.peek()) >= pre && s.peek() != 'N')
                {
                    exp += s.pop();
                }
                s.push(op[i]);
            }
        }
    }
    while (s.peek() != 'N')
    {
        exp += s.pop();
    }
    return exp;
}

int eval_postfix(string conv)
{
    stack s;
    string exp;
    int value, a, b;

    for (int i = 0; i < conv.length(); i++)
    {
        if (isdigit(conv[i]))
        {
            s.push(conv[i]);
        }
        else
        {
            b = s.pop();

            a = s.pop();

            if (conv[i] == '+')
            {
                s.push((a - '0') + (b - '0'));
            }
            else if (conv[i] == '-')
            {
                s.push((a - '0') - (b - '0'));
            }
            else if (conv[i] == '*')
            {
                s.push((a - '0') * (b - '0'));
            }
            else if (conv[i] == '/')
            {
                s.push((a - '0') / (b - '0'));
            }
            else if (conv[i] == '^')
            {
                s.push(pow((a - '0'), (b - '0')));

            }
        }
    }
    return s.peek();
}

int main()
{
    int exit = 0, choice;
    string op, conv;
    int val;

    while (exit == 0)
    {
        cout << "1. Get Infix\n2. Convert Infix\n3. Evaluate Postfix\n4. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            op = get_infix();
            cout << op << endl;
            break;
        case 2:
            conv = convert_infix(op);
            cout << conv << endl;
            break;
        case 3:
            val = eval_postfix(conv);
            cout << val << endl;
            break;
        case 4:
            exit = 1;
            break;
        }
    }
}