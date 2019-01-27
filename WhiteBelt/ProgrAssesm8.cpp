#include <iostream>
#include <vector>
using namespace std;



int main()
{
    int num;
    vector<int> temp;

    cin>>num;

    while(num >0){
        temp.push_back(num%2);
        num/=2;
    }
    for(int j = temp.size()-1; j >=0; j--){
        cout <<temp[j];
    } 
    return 0;
    
}