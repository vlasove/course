#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{

    int x =5;
    x = 6;
    x+= 4;
    cout << x;

    const string s = "Hello";
    string t = s;
    t += ", world";
    cout << t;
    
    return 0;
}
