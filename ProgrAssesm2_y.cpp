#include <iostream>
#include <vector>

using namespace std;

int main(){

    unsigned n;
    uint8_t r;
    cin >>n>>r;
    uint64_t sum = 0;


    for(unsigned i =0; i < n; i++){
        unsigned w,h,d;
        cin >> w>>h>>d;
        sum += w*h*d*r;
    }
    

    cout<<sum<<endl;





    return 0;
}