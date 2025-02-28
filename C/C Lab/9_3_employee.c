#include <stdio.h>

// program to get n employee's data in the form of a structure and store them in an array to display them.

struct emp
{
    char name[30];
    int emp_id;
    int age;
    char sex;
    char position[30];
    int salary;
};

int main()
{
    int size;
    printf("Enter the number of employes\n");
    scanf("%d", &size);

    struct emp arr[size];
    // Getting inputs 
    for (int i = 0; i < size; i++)
    {
        printf("Employee %d\n\n",i+1);
        printf("Employee %d\n",i+1);
        printf("Enter the name: ");
        scanf(" %s",arr[i].name);

        printf("\nEnter the employee id: ");
        scanf("%d",&arr[i].emp_id);

        printf("\nEnter the age: ");
        scanf("%d",&arr[i].age);

        printf("\nEnter the sex: ");
        scanf(" %c",&arr[i].sex);

        printf("\nEnter the position: ");
        scanf(" %s",arr[i].position);

        printf("\nEnter the salary: ");
        scanf("%d",&arr[i].salary);
    }

    //displaying the structure
    for (int i = 0; i < size; i++)
    {
        printf("Name: %s\n",arr[i].name);

        printf("Emp id: %d\n",arr[i].emp_id);

        printf("Age: %d\n",arr[i].age);

        printf("Sex: %c\n",arr[i].sex);

        printf("Position: %s\n",arr[i].position);

        printf("Salary: %d\n",arr[i].salary);
    }
    return 0;
}
