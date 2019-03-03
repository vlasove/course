#include <iostream>

using namespace std;

int main(){

    int n, r;
    uint64_t mass = 0 ;
    cin >> n >> r;

    for (int i =0; i < n; i++){
        int w,h,d;
        cin >> w>>h>>d;
        mass += static_cast<uint64_t>(w*h*d*r);
    }
    cout << mass<<endl;;



    return 0;
}