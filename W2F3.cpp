#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void Sort(vector<int>& v) {
    sort(begin(v), end(v));

}

int main(int argc, char const *argv[])
{
    vector<int> a = {1,54,1,1,123,543,134,0,-2};
    Sort(a);
    for (auto c : a){
        cout << c<<" ";
    }
    return 0;
}
