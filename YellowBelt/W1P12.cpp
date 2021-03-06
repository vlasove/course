#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <sstream>

using namespace std;



template <typename First, typename Second>
ostream& operator<<(ostream& out, const pair<First, Second>& p ){
    out<<p.first<<','<<p.second;
    return out;

}


template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v){
    for (const auto i : v){
        out << i<<' ';
    }
    return out;

}


template <typename Key, typename Value>
ostream& operator<<(ostream& out, const map<Key, Value>& m){
    for (const auto i : m){
        out << i<<' ';
    }
    return out;

}




int main(){
    vector<int> v = {1,2,3};
    cout << v <<endl;

    map<int, int> m = {{1,2}, {3,4}};
    cout << m<< endl;



    return 0;
}