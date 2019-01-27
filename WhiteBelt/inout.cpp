#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{   
    int x  = 5;
    string y = "hello";
    cout << x <<" "<<y<< "\n";

    vector<int> d = {1,3,5};
    //cout << d;


    int a,b;
    cin >> a >> b;
    cout << a+b;

    string name;
    cin >> name;
    cout << "Hello, "<<name<<"\n";
    return 0;
}
