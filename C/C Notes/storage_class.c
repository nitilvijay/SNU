#include <stdio.h>
int function()
{
    printf("h");
    static int count = 0;
    count++;
    return count;
}
int main()
{
    int a;
    for (int i = 0; i < count;i++)
    {
        a = function();
    }
    printf("%d\n", a);
}