//program to print the command line arg
#include <stdio.h>

int main(int argc, char * argv[])
{
    FILE*fp;
    fp=fopen(argv[1],"w");
    fprintf(fp,"%s","Hello world\n");
    fclose(fp);
    return 0;
}