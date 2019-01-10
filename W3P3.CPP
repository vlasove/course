#include <iostream>

using namespace std;

struct Lecture{
    string title;
    string author;
    int duration;
};

int main(int argc, char const *argv[])
{
    Lecture lecture1, lecture2;
    lecture1.title = "OOP";
    lecture1.author = "Gnadon";
    lecture1.duration = 666;
    lecture2 = {"OOP2", "gANDON",777};

    return 0;
}
