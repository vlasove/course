#include <iostream>
#include <vector>
#include <numeric>
using namespace std;


int main(int argc, char const *argv[])
{

    //Vector Input
    int n;
    cin >> n;

    vector<int> v(n);
    for (int& w : v){
        cin>>w;
    }
    //Statistical Params
    int sum = std::accumulate(std::begin(v), std::end(v), 0.0);
    int m =  sum / v.size();


    //if conditions
    int c = 0;
    int index = 0;
    vector<int> positions;
    for (auto j : v){
        
        if(j > m){
            c++;
            positions.push_back(index);
        }
        index++;

    }



    //Vector Pre-Output
    cout<<c<<endl;
    for (auto i : positions){
        cout << i <<" ";
    }
    return 0;
}
