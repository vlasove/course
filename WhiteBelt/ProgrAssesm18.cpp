#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

void add_func(map<string, set<string>>& b, string w1, string w2){
    b[w1].insert(w2);
    b[w2].insert(w1);
}


void count_func(map<string, set<string>>& b, string w1){
    cout<<b[w1].size()<<endl;
}

void check_func(map<string, set<string>>& b, string w1, string w2){
    if(b[w1].count(w2) == 0){
        cout<<"NO"<<endl;
    }else{
        int syn = 0;
        for(auto j : b[w1]){
            if(j == w2){
                syn++;
            }
        }
        if(syn != 0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    string command,word1,word2;
    map<string, set<string>> bag;
    int n;
    cin >>n;
    for(int i = 0; i < n; i++){
        cin>>command;
        if(command == "ADD"){
            cin >>word1>>word2;
            add_func(bag, word1, word2);

        }
        if(command =="COUNT"){
            cin>>word1;
            count_func(bag, word1);
        }
        if(command == "CHECK"){
            cin>>word1>>word2;
            check_func(bag, word1,word2);
        }

    }
    return 0;
}
