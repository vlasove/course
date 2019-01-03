#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    double N,A,B,X,Y;
    cin >> N >>A>>B>>X>>Y;
    if(N < 0 || A < 0 || B < 0){
        return 0;
    }

    if (N <= A) {
        cout << N;
    }else if (N > A && N <= B) {
        cout << N*(1-X/100)<<endl;
    }else{
        cout << N*(1 -Y/100)<<endl;
    }
    return 0;
}
