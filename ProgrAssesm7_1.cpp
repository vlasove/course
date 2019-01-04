#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int A,B;
    cin >> A>> B;
    if(A == 0 || B == 0){
        return 0;
    }
    while (A!=0 && B!=0){
        if (A>B) {
            A%=B;
            } else {
                B%=A;
                }
    }
    cout<< A+B;
    return 0;
}
