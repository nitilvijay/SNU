#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for Employee
struct Employee {
    char name[50];
    int empID;
    int age;
    char sex;
    char position[50];
    float salary;
};

// Function to add employee details
void addEmployee(FILE *file) {
    struct Employee emp;
    
    printf("Enter Employee Name: ");
    getchar();  // To consume the newline character left by previous input
    fgets(emp.name, 50, stdin);
    emp.name[strcspn(emp.name, "\n")] = 0;  // Remove the newline character
    
    printf("Enter Employee ID: ");
    scanf("%d", &emp.empID);
    
    printf("Enter Age: ");
    scanf("%d", &emp.age);
    
    printf("Enter Sex (M/F): ");
    getchar();  // To consume the newline
    scanf("%c", &emp.sex);
    
    printf("Enter Position: ");
    getchar();  // To consume the newline
    fgets(emp.position, 50, stdin);
    emp.position[strcspn(emp.position, "\n")] = 0;  // Remove the newline character
    
    printf("Enter Salary: ");
    scanf("%f", &emp.salary);
    
    // Write the employee data to the file
    fwrite(&emp, sizeof(struct Employee), 1, file);
    printf("Employee details added successfully.\n");
}

// Function to display all employee details
void displayEmployees(FILE *file) {
    struct Employee emp;
    rewind(file);  // Move to the beginning of the file
    
    printf("\nEmployee Details:\n");
    while (fread(&emp, sizeof(struct Employee), 1, file)) {
        printf("\nName: %s\n", emp.name);
        printf("Employee ID: %d\n", emp.empID);
        printf("Age: %d\n", emp.age);
        printf("Sex: %c\n", emp.sex);
        printf("Position: %s\n", emp.position);
        printf("Salary: %.2f\n", emp.salary);
    }
}

// Function to search for an employee by ID
void searchEmployee(FILE *file) {
    int id, found = 0;
    struct Employee emp;
    
    printf("Enter Employee ID to search: ");
    scanf("%d", &id);
    
    rewind(file);  // Move to the beginning of the file
    while (fread(&emp, sizeof(struct Employee), 1, file)) {
        if (emp.empID == id) {
            printf("\nEmployee Found:\n");
            printf("Name: %s\n", emp.name);
            printf("Employee ID: %d\n", emp.empID);
            printf("Age: %d\n", emp.age);
            printf("Sex: %c\n", emp.sex);
            printf("Position: %s\n", emp.position);
            printf("Salary: %.2f\n", emp.salary);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
}

int main() {
    FILE *file;
    int choice;
    
    // Open file in read-write mode, create if not exists
    file = fopen("employee_data.dat", "rb+");
    if (file == NULL) {
        file = fopen("employee_data.dat", "wb+");
        if (file == NULL) {
            printf("Unable to open file.\n");
            return 1;
        }
    }
    
    do {
        // Display the menu
        printf("\nMenu:\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addEmployee(file);
                break;
            case 2:
                displayEmployees(file);
                break;
            case 3:
                searchEmployee(file);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    
    fclose(file);  // Close the file before exiting
    return 0;
}
