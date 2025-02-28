#include<stdio.h>


// int main(){
//     int i,num,inc;
//     printf("Enter the number to check\n");
//     scanf("%d",&num);
//     i=10;
//     inc=1;
//     while(1){
//         if (num<i){
//             printf("%d \n",inc);
//             break;
//         }
//         inc+=1;
//         i*=10;
//     }
//     return 0;
// }

int main(){
    int num,inc;
    printf("Enter the number to check\n");
    scanf("%d",&num);
    inc=0;
    while(num!=0){
        num=num/10;
        inc+=1;

    }  
    printf("%d\n",inc);  
}