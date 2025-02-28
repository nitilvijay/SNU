#include<stdio.h>
int main(){
int num;
printf("Enter the number");
scanf("%d",&num);
if (num%2==0||num%3==0){
printf("The number is divisible by 2 and 3");}
else {
printf("Not divisible");}
return 0;
}
