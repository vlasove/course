#include <iostream>
#include <vector>
#include <string>
using namespace std;

void PrintVector(const vector<string>& vec){
    cout<<"=================Personal List of Members==================="<<endl;
    for (auto temp : vec){
        cout<<temp<<endl;
    }
}

int main(int argc, char const *argv[])
{
    int n ;
    cout<<"Please, Enter the number: ";
    cin >>n;
    vector<string> v(n);
    for(string& personal: v){
        cin >> personal;
    }

    PrintVector(v);
    return 0;
}
