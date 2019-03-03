#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <sstream>

using namespace std;




template<typename T> T Sqr(T x);
template <typename First, typename Second> pair<First, Second> operator*(const pair<First, Second>& p1, const pair<First, Second>& p2);
template <typename lhs, typename rhs> map<lhs, rhs> operator*(const map<lhs, rhs>& m1, const map<lhs, rhs>& m2);
template <typename K> vector<K> operator*(const vector<K>& v1, const vector<K>& v2);


template<typename T>
T Sqr(T x){
    return x*x;
}





template <typename First, typename Second>
pair<First, Second> operator*(const pair<First, Second>& p1, const pair<First, Second>& p2){
    First f= p1.first * p2.first;
    Second s  = p1.second*p2.second;

    return make_pair(f,s);
}


template <typename lhs, typename rhs>
map<lhs, rhs> operator*(const map<lhs, rhs>& m1, const map<lhs, rhs>& m2){
    map<lhs,rhs> total;
    for (auto i : m1){
        total[i.first] = i.second*i.second;
    }

    return total;

}

template <typename K>
vector<K> operator*(const vector<K>& v1, const vector<K>& v2){
    vector<K> empty;
    for(int i = 0; i < v1.size(); i++){
        empty.push_back(v1[i]*v2[i]);
    }

    return empty;
}





