#include<stdio.h>

int main() {
    int i,num,fact;
    printf("Enter the factorial number\n");
    scanf("%d",&num);
    for (i=1;i<=num;i++){
        printf("%d",i);
        fact=fact*i;
    }
    printf("The factorial value is %d\n",fact);
    return 0;
}