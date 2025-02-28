#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string list = ")}]";

    string s;
    int len = s.length();

    cout << "Enter the character\n";
    cin >> s;

    stack<char> stk;

    for (int i = 0; i<len; i++)
    {
        if (list.find(s[i])!= string::npos)
        {
            stk.push(s[i]);
        }
    }

    for (int i = 0; i<len; i++)
    {
        if (list.find(s[i]) == string::npos)
        {
            if (stk.pop()!= s[i])
            {
                cout << "Flase\n"; 
            }
        }
    }
        
}