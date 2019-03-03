#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main(){

    vector<int> t = {1,2,3,4};
    int sum =0;
    for (int x : t){
        sum+=x;
    }
    int avg = sum/t.size();
    cout << avg << endl;

    int x = 2'000'000'000;
    cout << x <<" "<<x*2<<endl;

    cout <<sizeof(int)<<endl;
    cout<<numeric_limits<int>::min()<< " "<<numeric_limits<int>::max()<<endl;


    return 0;
}