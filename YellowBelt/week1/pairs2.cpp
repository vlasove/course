#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <string>

using namespace std;

int main(){

    tuple<int, string, bool> t (7, "C++", false);

    auto kek = make_tuple("kek", "lol", false);
    cout << get<1>(kek)<<endl; 

    pair<int, string> p = {2, "John"};
    cout<<p.first << " "<<p.second<<endl;



    return 0;
}