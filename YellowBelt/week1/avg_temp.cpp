#include <iostream>
#include <vector>

using namespace std;


int main(){

    int n;
    int64_t sum = 0;
    
    cin >> n;
    vector<int> v(n);
    for(int& temperature : v){
        cin >> temperature;
        sum+= temperature;
    }
    

    int avg = sum/n;

    vector<int> indexes;


    for(int i =0; i < static_cast<int>(v.size()); i++){
        if (v[i] > avg){
            indexes.push_back(i);
        }

    }
    cout <<indexes.size()<<endl;
    for(auto i : indexes){
        cout<<i<<" ";
    }
    cout<<endl;




    return 0;
}