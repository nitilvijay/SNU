#include <iostream>

class shape
{
    int len, bre, hei;

public:
    shape()
    {
        len = 1;
        bre = 1;
        hei = 1;
    }

    void setlength(int);
    void setbreadth(int);
    void setheight(int);

    int getlength()
    {
        return len;
    }

    int getbreadth()
    {
        return bre;
    }

    int getheight()
    {
        return hei;
    }
};

void shape::setlength(int length)
{
    len = length;
}

void shape::setbreadth(int breadth)
{
    bre = breadth;
}

void shape::setheight(int height)
{
    hei = height;
}

int main()
{
    class shape s;

    int length;
    int breadth;
    int height;

    int area;
    int volume;

    int exit = 1;
    int choice;

    while (exit == 1)
    {
        std::cout << "Enter the choice\n"
                  << "1. Square\n2. Rectangle\n3. Cube\n4. Cuboid\n5. exit\n";

        std::cin >> choice;
        switch (choice)
        {
        case 1:

            std::cout << "Enter the Length\n";
            std::cin >> length;

            s.setlength(length);

            std::cout << "Enter the Breadth\n";
            std::cin >> breadth;

            s.setbreadth(breadth);

            area = (s.getlength()) * (s.getbreadth());

            std::cout << "The area of Square is" << area << '\n';

            break;

        case 2:

            std::cout << "Enter the Length\n";
            std::cin >> length;

            s.setlength(length);

            std::cout << "Enter the Breadth\n";
            std::cin >> breadth;

            s.setbreadth(breadth);

            area = (s.getlength()) * (s.getbreadth());

            std::cout << "The area of Rectangle is" << area << '\n';

            break;

        case 3:

            std::cout << "Enter the Length\n";
            std::cin >> length;

            s.setlength(length);

            std::cout << "Enter the Breadth\n";
            std::cin >> breadth;

            s.setbreadth(breadth);

            std::cout << "Enter the Height\n";
            std::cin >> height;

            volume = (s.getlength()) * (s.getbreadth()) * (s.getheight());

            std::cout << "The volume of the cube is" << volume << '\n';

            break;

        case 4:

            std::cout << "Enter the Length\n";
            std::cin >> length;

            s.setlength(length);

            std::cout << "Enter the Breadth\n";
            std::cin >> breadth;

            s.setbreadth(breadth);

            std::cout << "Enter the Height\n";
            std::cin >> height;

            volume = (s.getlength()) * (s.getbreadth()) * (s.getheight());

            std::cout << "The volume of the cuboid is" << volume << '\n';

            break;

        case 5:
            exit = 0;
        }
    }
}