
#include <iostream>

using std::cin;
using std::cout;

#define SIZE 5

class List {
    int arr[SIZE];
    int count;

public:
    List() {
        count = 0;
    }

    void insert_beginning(int);
    void insert_end(int);
    void insert_position(int, int);
    void delete_beginning();
    void delete_end();
    void delete_position(int);
    void search(int);
    void rotate(int);
    void display();
};

// Insert at the beginning
void List::insert_beginning(int value) {
    if (count == SIZE) {
        cout << "The list is full\n";
        return;
    }

    for (int i = count; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    count++;
}

// Insert at the end
void List::insert_end(int value) {
    if (count == SIZE) {
        cout << "The list is full\n";
        return;
    }
    arr[count++] = value;
}

// Insert at a given position
void List::insert_position(int value, int position) {
    if (count == SIZE || position < 1 || position > count + 1) {
        cout << "Invalid position or list is full\n";
        return;
    }

    for (int i = count; i >= position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position - 1] = value;
    count++;
}

// Delete from the beginning
void List::delete_beginning() {
    if (count == 0) {
        cout << "The list is empty\n";
        return;
    }

    for (int i = 0; i < count - 1; i++) {
        arr[i] = arr[i + 1];
    }
    count--;
}

// Delete from the end
void List::delete_end() {
    if (count == 0) {
        cout << "The list is empty\n";
        return;
    }
    count--;
}

// Delete at a given position
void List::delete_position(int position) {
    if (count == 0 || position < 1 || position > count) {
        cout << "Invalid position or list is empty\n";
        return;
    }

    for (int i = position - 1; i < count - 1; i++) {
        arr[i] = arr[i + 1];
    }
    count--;
}

// Search for an element
void List::search(int value) {
    if (count == 0) {
        cout << "The list is empty\n";
        return;
    }
    
    for (int i = 0; i < count; i++) {
        if (arr[i] == value) {
            cout << "Value found at position " << i + 1 << "\n";
            return;
        }
    }
    cout << "Value not found\n";
}

// Rotate the list right by k times using O(1) space
void List::rotate(int k) {
    if (count == 0) {
        cout << "The list is empty\n";
        return;
    }

    k = k % count;  // Handle cases where k > count
    if (k == 0) return;

    // Reverse the entire array
    for (int i = 0, j = count - 1; i < j; i++, j--) {
        std::swap(arr[i], arr[j]);
    }

    // Reverse the first k elements
    for (int i = 0, j = k - 1; i < j; i++, j--) {
        std::swap(arr[i], arr[j]);
    }

    // Reverse the remaining elements
    for (int i = k, j = count - 1; i < j; i++, j--) {
        std::swap(arr[i], arr[j]);
    }
}

// void List::rotate(int k) {
//     if (count == 0) {
//         cout << "The list is empty\n";
//         return;
//     }

//     k = k % count;  // Handle cases where k > count
//     if (k == 0) return;

//     for (int i = 0; i < k; i++) {
//         int lastElement = arr[count - 1];  // Store the last element
//         delete_end();                      // Remove the last element
//         insert_beginning(lastElement);     // Insert it at the beginning
//     }
// }


// Display the list
void List::display() {
    if (count == 0) {
        cout << "The list is empty\n";
        return;
    }

    cout << "List: ";
    for (int i = 0; i < count; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    List l;
    int exit = 1;

    while (exit) {
        int choice, value, position, k;

        cout << "\nEnter choice:\n"
             << "1. Insert Beginning\n2. Insert End\n3. Insert Position\n"
             << "4. Delete Beginning\n5. Delete End\n6. Delete Position\n"
             << "7. Search\n8. Rotate\n9. Display\n10. Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            l.insert_beginning(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            l.insert_end(value);
            break;

        case 3:
            cout << "Enter value and position: ";
            cin >> value >> position;
            l.insert_position(value, position);
            break;

        case 4:
            l.delete_beginning();
            break;

        case 5:
            l.delete_end();
            break;

        case 6:
            cout << "Enter position: ";
            cin >> position;
            l.delete_position(position);
            break;

        case 7:
            cout << "Enter value to search: ";
            cin >> value;
            l.search(value);
            break;

        case 8:
            cout << "Enter number of rotations: ";
            cin >> k;
            l.rotate(k);
            break;

        case 9:
            l.display();
            break;

        case 10:
            exit = 0;
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
