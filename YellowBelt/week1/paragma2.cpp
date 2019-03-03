#include <iostream>
#include <limits>
#include <vector>

using namespace std;


void PrintAvg(){
    vector<int> t = {1,2,3,4};
    int sum =0;
    for (int x : t){
        sum+=x;
    }
    int avg = sum/t.size();
    cout << avg << endl;

}
int main(){
    //cout << numeric_limits<int>::max()+1 <<endl;
    //cout <<numeric_limits<int>::min() -1 <<endl;
    int x = -100;
    unsigned y = x;
    cout << x << " "<<y<<endl;

    int a = -1;
    unsigned b = 1;
    cout <<(a < b) <<endl;
    return 0;
}