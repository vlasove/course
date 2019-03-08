#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <sstream>

using namespace std;

template<class V> vector<V> operator *(const vector<V>& lhs, const vector<V>& rhs);
template<class F, class S> pair<F,S> operator * (const pair<F,S>& lhs, const pair<F,S>& rhs);
template<class F, class S> map<F,S> operator*(const map<F,S>& lhs, const map<F,S>& rhs);



template<class V>
vector<V> operator *(const vector<V>& lhs, const vector<V>& rhs){
    vector<V> temp;
    for(int i =0; i < lhs.size(); i++){
        temp.push_back(lhs[i]*rhs[i]);

    }
    return temp;
}

template<class F, class S>
pair<F,S> operator * (const pair<F,S>& lhs, const pair<F,S>& rhs){
    F f = lhs.first*rhs.first;
    S s = rhs.second*lhs.second;

    return make_pair(f,s);

}

template<class F, class S>
map<F,S> operator*(const map<F,S>& lhs, const map<F,S>& rhs){
    map<F,S> m;
    for(const auto& items : lhs){
        m[items.first] = items.second*items.second;

    }
    return m;
}



template <class T>
T Sqr(T x){
    return x*x;
}