#include <stdio.h>
int main()
{
    printf("Input the number of laptop bought");
    int quantity;
    scanf("%d", &quantity);
    int grs = 15000 + (quantity * (2 / 100)) + (quantity * 45000) * (2 / 100);
    printf ("The gross salary is %d\n",grs);
    return 0;
}
