#include <iostream>
#include <vector>
#include <utility>
#include <sstream>

using namespace std;



template<class F, class S>
pair<F,S> operator * (const pair<F,S>& lhs, const pair<F,S>& rhs){
    F f = lhs.first*rhs.first;
    S s = rhs.second*lhs.second;

    return make_pair(f,s);

}

template<class F, class S>
ostream& operator << (ostream& os, const pair<F,S>& p1){
    os<<p1.first<<" "<<p1.second;
    return os;
}



template<class T>
T Sqr(T x){
    return x*x;
}

int main(){
    auto p = make_pair(1, 2.3);
    cout << Sqr(p)<<endl;

    cout <<Sqr(5.2)<<endl;

    return 0;
}