#include <iostream>
#include <vector>
#include <sstream>
#include <map>
using namespace std;



template<class Collection>
string Join(const Collection& c, char d){
    stringstream ss;
    bool first = true;
    for (const auto& item : c){
        if (!first){
            ss << d;
        }
        first = false;
        ss << item;

    }
    return ss.str();
}


template <class F, class S>
ostream& operator << (ostream& os, const pair<F,S>& p){
    os <<'('<< p.first<<":"<<p.second<<')';
    return os;
}

template<class T>
ostream& operator << (ostream& os, const vector<T>& v){
    return os << '['<<Join(v, ',')<<']';
}

template<class Key, class Value>
ostream& operator <<(ostream& os, const map<Key, Value>& m){
    return os<<'{'<<Join(m, ',')<<'}';
    
}

int main(){

    vector<int> vi = {1,2,3};
    vector<double> vd = {1.2, 2.3, 3.4};
    cout<< vi << "\n"<<vd<<endl;
    map<int, int> m = {{1,2}, {3,4}};
    cout << m<<endl;

    vector<vector<int>> vv = {{1,2,3,4}, {2,3,4,3,2}};
    cout<<vv<<endl;
    return 0;
}