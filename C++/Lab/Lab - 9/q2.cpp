#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements" << endl;
    cin >> n;

    vector<int> arr(n);
    vector<int> temp(n);

    cout << "Enter the numbers" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    temp = arr;
    sort(arr.begin(), arr.end(), greater<int>());

    int max1 = arr[0];
    int max2 = arr[1];

    for (int &i : temp)
    {
        if (i != max1)
        {
            i = i - max1;
        }
        else
        {
            i = i-max2;
        }
    }

    for (int i: temp)
    {
        cout << i << " ";
    }
    cout << endl;
}