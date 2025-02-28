#include<stdio.h>
int main(){
int max=0;
int num1;
int num2;
int num3;
int num4;
printf("Enter the 1st number");
scanf("%d",&num1);
printf("Enter the 2st number");
scanf("%d",&num2);
printf("Enter the 3rd number");
scanf("%d",&num3);
printf("Enter the 4th number");
scanf("%d",&num4);
if (num1>max){
max=num1;}
if (num2>max){
max=num2;}
if (num3>max){
max=num3;}
if (num4>max){
max=num4;}
printf("The greatest number is %d\n",max);
return 0;}

