#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


void PrintVector(const vector<int>& v, string title){

    for(auto item : v){
        cout<<item<<" ";
    }
    cout<<title<<endl;

}

int main(int argc, char const *argv[])
{
    vector<int> v = {1,4,3,2,123,-1,2,4,1,4,32,4,13,0};
    sort(begin(v), end(v));
    PrintVector(v,"sorted");
    int thr;
    cin>> thr;

    cout<<count_if(begin(v), end(v), [thr](int i) {return i > thr;});

    return 0;
}
