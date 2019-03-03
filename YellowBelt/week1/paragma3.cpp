#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> temp = {24,82,12,-10,500,-1000};
    int sum = 0;

    for(int x : temp){
        sum += x;
    }

    int avg = sum / static_cast<int>(temp.size());
    cout << avg<<endl;



    return 0;
}