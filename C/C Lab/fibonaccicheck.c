#include<stdio.h>

//Program to check if a number is fibonacci number or not

int main(){
    int input,i,num1,num2,fib;
    printf("enter the number to check\n");
    scanf("%d",&input);
    num1=0;
    num2=1;
    fib=num1+num2;
    while (fib<=input){
        if (fib==input){
            printf("The number is a fibonacci number\n");
            i=1;
            break;
        }
        else {
            i=0;                                             // Check whether 5(n)^2 +4 or 5(n)^2-4 is a pergfect square    
        }
        num1=num2;
        num2=fib;
        fib=num1+num2;
    }
    if (i==0){
        printf("The number is not a fibonacci\n");
    }
}

