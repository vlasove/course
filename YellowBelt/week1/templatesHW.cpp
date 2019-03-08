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

int main() {

//    vector<vector<int>> kek = {{1,2},{3,4}};
//    cout << kek<<endl;
//    cout <<Sqr(kek)<<endl;
//    auto p = make_pair(12,45);
//    cout << p <<endl;
//    cout<<Sqr(p)<<endl;
//    map<int, int> m = {{1,2}, {3,4}, {4,6}};
//    cout <<m<<endl;
//    cout<<Sqr(m)<<endl;

//    cout<<"Func test!!!!"<<endl;

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



    return 0;
}