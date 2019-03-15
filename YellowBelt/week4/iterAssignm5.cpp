#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

using namespace std;

template <class It>
void PrintRange(It range_begin,
                It range_end)
{
    for (auto it = range_begin; it != range_end; ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}


vector<int> vecCreation(int num){
    vector<int> temp;
    for(int i =1 ; i <= num; i++){
        temp.push_back(i);

    }
    return temp;
}

void permutOut(vector<int> v){
    sort(v.rbegin(), v.rend());

    do{
        PrintRange(v.begin(), v.end());

    }while(prev_permutation(v.begin(), v.end()));
}

int main(){
    int temp;
    cin >> temp;
    vector<int> t = vecCreation(temp);
    permutOut(t);
    

    return 0;
}