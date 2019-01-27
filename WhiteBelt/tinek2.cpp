#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    string temp;
    cin >> temp;

    map<char, int> m;

    for (int j = 0; j <temp.size(); j++){
        ++m[temp[j]];
      
    }

    for(auto item: m){
        if(item.second > 1){
            cout<<item.first;
        }
    }
    cout<<endl;
    return 0;
}
