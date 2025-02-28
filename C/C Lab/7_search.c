#include <stdio.h>
#include <string.h>

// Call by value
char* value(int arr[], int length, int num) {
    for (int i = 0; i < length; i++) {
        if (arr[i] == num) {
            return "True";
        }
    }
    return "False";
}

// Call by Reference
void reference(int arr[], int length, int num, char found[]) {
    for (int i = 0; i < length; i++) {
        if (arr[i] == num) {
            strcpy(found, "True");
            return;
        }
    }
    strcpy(found, "False");
}

int main() {
    int num, count = 0;
    char found[6];
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &count);
    
    int arr[count];
    for (int i = 0; i < count; i++) {
        arr[i] = i + 1;
    }
    
    printf("Enter the number to find in the array: ");
    scanf("%d", &num);

    // Call by value
    printf("Call by value result: %s\n", value(arr, count, num));

    // Call by reference
    reference(arr, count, num, found);
    printf("Call by reference result: %s\n", found);

    return 0;
}
