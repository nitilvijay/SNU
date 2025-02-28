#include<stdio.h>

int main(){
    printf("Enter the decimal value");
    int deci;
    scanf("%d",&deci);
    if (deci<16){
        printf("The number in binary is 101\n");
    }
    else{
        printf("Error");
    }
        if (deci<16){
        printf("The number in Hexadecimal is A\n");
    }
    else{
        printf("Error");
    }
        if (deci<16){
        printf("The number in Octal is 11\n");
    }
    else{
        printf("Error");
    }

    return 0;
}