#include <iostream>
#include <map>
#include <string>

using namespace std;

void BuildCharCounters(const string& a, const string& b){
    map<char, int> a_map;
    map<char, int> b_map;

    for(const auto& temp : a){
        ++a_map[temp];
    }

    for(const auto& temp : b){
        ++b_map[temp];
    }

    if(a_map == b_map){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}


int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    string first, second;

    for(int i = 0; i < n; i++){
        cin>>first>>second;
        BuildCharCounters(first,second);
    }
    return 0;
}
