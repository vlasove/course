#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int A,B;
    cin >> A>>B;
    for(int i = A; i <= B; i++){
        if(i %2 == 0){
            cout <<i<<" ";
        }
    }
    return 0;
}
