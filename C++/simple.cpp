#include <iostream>
class room
{
    int len, bre, hei; // Here the data members are private by default

public:
    room()
    {
        len = 1;
        bre = 1;
        hei = 1;
    }
    void sethei(int);       // this is a function prototype, the defenition is given later
    int gethei()            // The "::" operator is not needed here when we define functoin here
    {
        return hei;
    }                 
};                    

void room::sethei(int temp) // "::" this is scope resolution operation, it is telling that the
{                           // func is called in room
    hei = temp;
}

int main()
{
    class room obj;
    obj.sethei(2);
    printf("%d", obj.gethei());
    return 0;
}