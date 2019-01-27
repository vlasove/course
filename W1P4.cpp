#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> x = {4,5};
    for (size_t i =0 ; i < x.size(); i++){
        cout<<i<<" "<<x[i]<<endl;
    }

    for(int i = 0; i < static_cast<int>(x.size()); i++){
        cout<<i<<" "<<x[i]<<endl;
    }
    return 0;
}