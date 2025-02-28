#include <stdio.h>
#include<string.h>

int main()
{
    printf("Enter data unit");
    char unit[4];
    scanf("%s",unit);
    printf("%s",unit);
    int data;
    printf("enter the amount of data");
    scanf("%d",&data);
    int conv,byte,bit;
    if (strcmp(unit, "KBps") == 1){
        printf("inside");
        conv=data*23;
        byte=data*210;
        bit=data*23*210;
        printf("Kbps=%d",conv);
        printf("Bps=%d",byte);
        printf("bps=%d",bit);
    }
        /*if (unit=="MBps"){
        conv=data*8;
        byte=data*210;
        bit=data*23*210;
        printf("Kbps=%d",conv);
        printf("Bps=%d",byte);
        printf("bps=%d",bit);
    }
        if (unit=="GBps"){
        conv=data*23;
        byte=data*210;
        bit=data*23*210;
        printf("Kbps=%d",conv);
        printf("Bps=%d",byte);
        printf("bps=%d",bit);
    }*/
   return 0;
}