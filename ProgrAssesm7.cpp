#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a,b;
    cin >>a>>b;
    int minimal_num;
    if(a == 0 || b == 0){
        return 0;
    }
    if (a >= b){
        minimal_num = b;
    }else{
        minimal_num = a;
    }

    for (int i = minimal_num; i > 0; i--){
        if(a%i ==0 && b%i ==0){
            cout<<i;
            break;
        }
    }

    return 0;
}
