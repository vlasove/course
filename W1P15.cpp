#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <sstream>

using namespace std;


template <typename T>
vector<T> operator*(const vector<T>& v1, const vector<T>& v2){
    vector<T> empty;
    for(int i = 0; i < v1.size(); i++){
        empty.push_back(v1[i]*v2[i]);
    }

    return empty;
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



template<typename T>
T Sqr(T x){
    return x*x;
}



int main(){

    // Пример вызова функции
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
    cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
    {4, {2, 2}},
    {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
    cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }

    vector<map<int, vector<double>>> it = { { {2, { 3, 4,5,6.8 }}}, { {5, {6, 7,0.01}} } };
    Sqr(it);


    return 0;
}