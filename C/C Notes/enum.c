#include <stdio.h>

typedef enum month
{
    char*one="happy",
    two,
    three
} month;
int main()
{
    enum month mm=one;
    printf("%p\n",mm);
}