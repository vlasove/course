#include <iostream>
using namespace std;

void UpdateIfGreater(int& first, int& second){
    if(first > second){
        second = first;
        cout << second;
    }
}


int main(int argc, char const *argv[])
{
    int a = 4;
    int b = 2 ;
    UpdateIfGreater(a,b);
    return 0;
}
