#include <iostream>
#include <string>
#include <cmath>
#include <cstring> // For strlen function

using std::cin;
using std::cout;
using std::endl;

int palindrome()
{
    char *arr = new char[100];
    int i;
    int length = 0;
    int temp;
    bool found = true; // Using boolean for clarity
    
    cout << "Enter the word: ";
    cin >> arr;
    
    // Calculate string length correctly using strlen
    length = strlen(arr);
    temp = length - 1;
    
    // Check for palindrome
    for (i = 0; i < length/2; i++)
    {
        if (arr[i] != arr[temp])
        {
            found = false;
            break;
        }
        temp--;
    }
    
    if (found)
    {
        cout << "It is a Palindrome" << endl;
    }
    else
    {
        cout << "It is not a Palindrome" << endl;
    }
    
    // Free allocated memory
    delete[] arr;
    return 0;
}

int armstrong()
{
    int number;
    int digit;
    int sum = 0;
    int temp;
    int count = 0;
    
    cout << "Enter the number: ";
    cin >> number;
    
    temp = number;
    // Count the number of digits
    while (temp != 0)
    {
        temp = temp / 10;
        count++;
    }
    
    temp = number;
    // Calculate the sum of digits raised to the power of count
    while (temp != 0)
    {
        digit = temp % 10;
        temp = temp / 10;
        sum += pow(digit, count);
    }
    
    if (sum == number)
    {
        cout << "It is an Armstrong number" << endl;
    }
    else
    {
        cout << "It is not an Armstrong number" << endl;
    }
    
    return 0;
}

int perfect()
{
    int number;
    int sum = 0;
    
    cout << "Enter the number: ";
    cin >> number;
    
    // Find the sum of divisors
    for (int i = 1; i < number; i++)
    {
        if (number % i == 0)
        {
            sum += i;
        }
    }
    
    if (sum == number)
    {
        cout << "It is a perfect number" << endl;
    }
    else
    {
        cout << "It is not a perfect number" << endl;
    }
    
    return 0;
}

int main()
{
    int choice;
    bool exit = false;
    
    while (!exit)
    {
        cout << "\nEnter the choice" << endl;
        cout << "1. Palindrome" << endl;
        cout << "2. Armstrong" << endl;
        cout << "3. Perfect Number" << endl;
        cout << "4. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;
        
        switch (choice)
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
            exit = true;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }
    
    return 0;
}