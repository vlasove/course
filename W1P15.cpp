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
    Secodn s  = p1.second*p2.second;

    return make_pair(f,s);
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



    return 0;
}