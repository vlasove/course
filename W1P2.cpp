#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main(){

    //cout<<numeric_limits<int>::max() + 1<<endl;
    unsigned int x = 2000000000;
    unsigned int y = 1000000000;
    cout <<(x+y)/2<<endl;

    unsigned int one = 119;
    int two = -120;

    if(one > two){
        cout<<"Oh fuck"<<endl;
    }else{
        cout<<"WAT"<<endl;
    }

    return 0;
}