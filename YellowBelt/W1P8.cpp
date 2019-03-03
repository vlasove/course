#include <iostream>
#include <vector>
#include <tuple>
#include <utility>

using namespace std;

int main(){

    tuple<int, string, bool> t(7, "C++", true);

    auto q = make_tuple(8, "Rust", false);

    cout<<get<0>(q)<<get<1>(q)<<get<2>(q)<<endl;

    pair<int, string> p(10, "Python");

    cout<<p.first <<" and "<<p.second<<endl;




    return 0;
}