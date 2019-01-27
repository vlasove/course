#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <locale>

using namespace std;

void PrintVector(const vector<string>& v){
    for(const auto& i : v){
        cout<<i<<" ";
    }
}

bool func(const string& str1, const string& str2){
    string dump1 = str1;
    string dump2 = str2;
    transform(dump1.begin(), dump1.end(), dump1.begin(), ::tolower);
    transform(dump2.begin(), dump2.end(), dump2.begin(), ::tolower);
    return dump1 < dump2;
}

int main(int argc, char const *argv[])
{   
    string temp;
    vector<string> bag;
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin>>temp;
        bag.push_back(temp);

    }
    sort(begin(bag), end(bag), func);

    PrintVector(bag);

    return 0;
}
