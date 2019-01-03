#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int sum = 0;
    if (n >0) {
        while (n> 0){
            sum += n;
            --n;

        }
        cout << sum<<endl;

    }else{
        cout<<"Enter Positive Number"<<endl;
    }
    return 0;
}
