#include <stdio.h>

int main()
{
    int seat;
    printf("Enter the seat Number");
    scanf("%d", &seat);
    if (seat % 8 == 1 || seat % 8 == 4)
    {
        printf("The designated seat is Lower");
    }
    if (seat % 8 == 2 || seat % 8 == 5)
    {
        printf("The designated seat is Middle");
    }
    if (seat % 8 == 3 || seat % 8 == 6)
    {
        printf("The designated seat is Upper");
    }
    if (seat % 8 == 7)
    {
        printf("The designated seat is Side Lower");
    }
    if (seat % 8 == 0)
    {
        printf("The designated seat is Side Upper");
    }
    return 0;
}