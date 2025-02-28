#include <stdio.h>

int main()
{
    int num;
    int times;
    int i;
    printf("Enter the number\n");
    scanf("%d", &num);
    printf("Enetr the number of times to multiply\n");
    scanf("%d",&times);
    for (i=0;i<=times;i++){
        int mul=num*i;
        printf("%d\n",mul);
    }
    return 0;
}