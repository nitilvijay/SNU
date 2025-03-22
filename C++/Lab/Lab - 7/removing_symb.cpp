#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    stack<int> stk;

    string str = "";

    cout << "Enter the string" << endl;
    cin >> str;

    for (int i = 0; i< str.length(); i++)
    {
        if (str[i]!='+')
        {
            stk.push(str[i]);
        }
        if (str[i]=='+' and (not stk.empty()))
        {
            stk.pop();
        }
    }
    str = "";
    while((not stk.empty()))
    {
        str+=(stk.top());
        stk.pop();
    }

    reverse(str.begin(), str.end());

    cout << str << endl;

    return 0;
}
