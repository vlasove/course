#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{   
    int x = 4;
    int y = 5;

    if (x == y) {
        cout << "Equal";
    } else {
        cout << " Not Equal";
    }
    
    /*Это*/
    int n = 5;
    int sum = 0;
    for (int i = 1; i <= n; i++){
        sum+= i;
    }
    cout << sum;


    int sum2 = 0;
    int j = 1;
    while (j <= n) {
        sum2 +=j;
        j+=1;

    }
    cout << sum2;
    return 0;
}
