#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <utility>

using namespace std;


template<typename First, typename Second>
pair<First, Second> operator*(const pair<First, Second>& p1, const pair<First,Second>& p2){
    First f =p1.first*p2.first;
    Second g = p1.second* p2.second;

    return make_pair(f,g);
}

template<typename T>
T Sqr(T x){
    return x*x;
}

int main(){

    auto p =  make_pair(2,3);

    cout<<Sqr(2.5)+Sqr(3) << endl;
    auto res = Sqr(p);

    cout << res.first << " "<<res.second<<endl;
    


    return 0;
}