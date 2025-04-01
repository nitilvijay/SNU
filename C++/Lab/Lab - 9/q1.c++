#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int k,q;

    cout << "Enter k and q" << endl;
    cin >> k >> q;

    vector<int> a(k);
    vector<int> n(q);

    cout << "Enter the values of a" << endl;
    for (int i = 0; i<k; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(),a.end());

    cout << "Enter the values of n" << endl;

    for (int i = 0; i<q; i++)
    {
        cin >> n[i];
    }

    for (int i = 0; i<q; i++)
    {
        if (n[i]>=a[0])
        {
            n[i] = a[0]-1;
        }
    }

    for (int i = 0; i<q; i++)
    {
        cout << n[i] << " ";
    }
    cout << endl;
}