#include <iostream>
#include <vector>

using namespace std;

int main(){


    vector<int> x = {1,4,5};
    for(size_t k = x.size(); k>0; k--){
        int i = k-1;
        cout<<x[i]<<endl;
    }
    return 0;
}