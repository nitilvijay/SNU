#include <iostream>
#include <string>
#include <cmath>

using std::cin;
using std::cout;

int palindrome()
{
    char *arr = new char[100];
    int *i = new int;
    int *length = new int;
    int *temp = new int;
    int *found = new int;

    cout << "Enter the word\n";
    cin >> arr;

    for (*i = 0; arr[(*i)] != '\n'; (*i)++)
    {
        (*length)++;
    }

    *temp = (*length) - 1;

    for (*i = 0; (*i) < (*length); (*i)++)
    {
        if (arr[(*i)] == arr[(*temp)])
        {
            *found = 1;
        }
        else
        {
            *found = 0;
        }
        (*temp)--;
    }

    if (*found == 1)
    {
        cout << "It is a Palindrome\n";
    }
}

int armstrong()
{
    int *number = new int;
    int *digit = new int;
    int *sum = new int;
    int *temp = new int;
    int *count = new int;

    cout << "Enter the number";
    cin >> *number;

    *temp = *number;

    while ((*temp) != 0)
    {
        *temp = (*temp) / 10;
        (*count)++;
    }

    *temp = *number;
    *sum = 0;

    while ((*temp) != 0)
    {
        *digit = (*temp) % 10;
        *temp = (*temp) / 10;

        *sum += pow((*digit), *count);
    }

    if (*sum == *number)
    {
        cout << "It is a armstrong number\n";
    }
    else
    {
        cout << "It is not a armstrong number\n";
    }
}

int perfect()
{
    int *number = new int;
    int *i = new int;
    int *sum = new int;

    cout << "Enter the number\n";
    cin >> *number;

    for (*i = 1; (*i) < (*number); (*i)++)
    {
        if ((*number) % (*i) == 0)
        {
            *sum += (*i);
        }
    }

    if (*sum == *number)
    {
        cout << "It is a perfect number\n";
    }
    else
    {
        cout << "It ain't a perfect number\n";
    }
}

int main()
{
    int *choice = new int;

    int *exit = new int(0);

    while ((*exit) == 0)
    {
        cout << "Enter the choice\n1. Palindrome\n2. Armstrong\n3. Perfect NUmber\n4. Exit\n";

        cin >> *choice;

        switch (*choice)
        {
        case 1:
            palindrome();
            break;
        case 2:
            armstrong();
            break;
        case 3:
            perfect();
            break;
        case 4:
            *exit = 1;
            break;
        }
    }
}