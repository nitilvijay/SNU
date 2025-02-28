#include <stdio.h>

// program to store student information in a array of structure
struct student
{
    char name[20];
    int roll;
    int mark;
};

int main()
{
    char term = 'y';
    int choice;
    int num_stu;
    
    printf("Enter the number of students\n");
    scanf("%d", &num_stu);      
    struct student arr[num_stu];

    while (term == 'y')
    {
        printf("Enter the choice\n1. Accept stu information\n2. Display stu information\n3. exit\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            for (int i = 0; i < num_stu; i++)
            {
                printf("Enter the name of the student\n");
                scanf("%s", arr[i].name);

                printf("Enter the roll number\n");
                scanf("%d", &arr[i].roll);

                printf("Enter the marks\n");
                scanf("%d", &arr[i].mark);
            }
        }

        else if (choice == 2)
        {
            for (int j = 0; j < num_stu; j++)
            {
                printf("Student %d\n3", j + 1);

                printf("Name: %s\n", arr[j].name);

                printf("Roll Number: %d\n", arr[j].roll);

                printf("Mark: %d\n", arr[j].mark);
            }
        }
        else
        {
            break;
        }
    }
    return 0;
}