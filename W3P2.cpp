#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;
s += "Hello";
{
    s += " world";
}
cout << s;

int value;
value += 15;
cout << value;
    return 0;
}
