#include<stdio.h>
int main(){
int mark;
printf("enter the obtained mark");
scanf("%d",&mark);
if (mark>=90){
printf("O");}
else if (mark>=80&&mark<90){
printf("A+");}
else if (mark>=70&&mark<80){
printf("A");}
else if (mark>=60&&mark<70){
printf("B+");}
else if (mark>=50&&mark<60){
printf("B");}
else if (mark>=40&&mark<50){
printf("P");}
else {
printf("RA");}
return 0;
}
