#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PrintVector(const vector<int>& v){
    for(const auto& i : v){
        cout<<i<<" ";
    }
}

bool func(int i, int j ){
    return abs(i) < abs(j);
}

int main(int argc, char const *argv[])
{   
    vector<int> bag;
    int n, temp;
    cin >> n;
    for(int i =0; i< n; i++){
        cin >> temp;
        bag.push_back(temp);


    }
    sort(begin(bag), end(bag), func);
    PrintVector(bag);

    return 0;
}

