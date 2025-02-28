#include<stdio.h>
int main(){
int num;
printf("Enter the number");
scanf("%d",&num);
if (num%2==0){
if (num%3==0){
printf("Divisible by both");}
else {
printf("divisible by 2");}
}
else if (num%3==0){
if (num%2==0){
printf("Divisible by both");}
else {
printf("divisible by 3");}
}
return 0;}
