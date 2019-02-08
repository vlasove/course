#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <sstream>

using namespace std;

template <typename T>
T Max(const T& a, const T& b){
    if(a < b){
        return b;
    }
    return a;
}


int main(){
    cout<<Max<double>(2,3)<<endl;

    return 0;
}