#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <sstream>

using namespace std;

template <typename Collection>
string Join(const Collection& c, char d){
    stringstream ss;
    bool first = true;
    for(const auto& i : c){
        if(!first){
            ss << d;
        }
        first = false;
        ss << i;
    }
    return ss.str();
}



template <typename First, typename Second>
ostream& operator<<(ostream& out, const pair<First, Second>& p ){
    out<<'('<<p.first<<':'<<p.second<<')';
    return out;

}


template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v){

    return out<<'['<<Join(v, ',')<<']';
}


template <typename Key, typename Value>
ostream& operator<<(ostream& out, const map<Key, Value>& m){

    return out <<'{'<< Join(m, ',')<<'}';
}




int main(){
    vector<int> v = {1,2,3};
    cout << v <<endl;

    map<int, int> m = {{1,2}, {3,4}};
    cout << m<< endl;

    vector<vector<int>> ve = {{1,23,3}, {4,57,7}, {12,44,33}};
    cout<< ve << endl;



    return 0;
}