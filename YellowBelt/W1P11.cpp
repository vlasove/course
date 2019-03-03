#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <sstream>

using namespace std;


template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v){
    for(auto x : v){
        out << x << " ";
    }
    return out;
}

int main(){
    vector<int> x ={1,2,3};
    cout << x << endl;


    return 0;
}