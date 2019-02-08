#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <sstream>

using namespace std;


ostream& operator<<(ostream& out, const vector<int>& v){
    for (const auto i : v){
        out << i<<' ';
    }
    return out;

}



int main(){
    vector<int> v = {1,2,3};
    cout << v <<endl;



    return 0;
}