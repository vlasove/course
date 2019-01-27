#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPalindrom(const string& s){
    for(int i =0; i < s.size()/2; i++){
        if(s[i] != s[s.size()-1-i]){
            return false;
        }
    }
    return true;
}

int PalindromCounter(const vector<string>& v){
    int c = 0;
    for(const auto& item : v){
        if(isPalindrom(item)){
            c++;

        }

    }
    return c;
}

int main(int argc, char const *argv[])
{
    int n;
    vector<string> temp;
    cin >> n;

    for (int i=1;i <=n; i++){

        temp.push_back(to_string(i));
    }

    cout <<PalindromCounter(temp)<<endl;
    return 0;
}
