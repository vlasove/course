#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

int main(){
    vector<int> t = {-8,-7,3};
    int sum = 0;
    for(const auto& item : t){
        sum+=item;
    }
    int avg = sum/t.size();
    cout<<"The average is equal to "<<avg<<endl;
    cout<<sizeof(long int)<<endl;
    cout<<numeric_limits<long int>::min() <<" "<<numeric_limits<long int>::max()<<endl;

    return 0;
}