#include <stdio.h>

int main()
{
    FILE *fp;

    fp = fopen("sample.txt", "r");

    fseek(fp,0,SEEK_END);
    long pos=ftell(fp);

    printf("This is the size of the file: %ld\n",pos);
}