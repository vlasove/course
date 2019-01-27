#include <iostream>
#include <vector>
using namespace std;

int Factorial(int n){
    if (n <= 0){
        return 1;
    }
    return Factorial(n-1)*n;
}

int main(int argc, char const *argv[])
{
    cout << Factorial(-3);
    return 0;
}
