#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void PrintMap(const map<string, int>& n){
    cout<<n.size()<<endl;
    for(auto item :n){
        cout<< item.first <<":"<<item.second<<endl;
    }
}

int main(int argc, char const *argv[])
{
    map<string, int> m  = {{"one",1}, {"two", 2}, {"three",3}};
    PrintMap(m);
  //  for(const auto& [key,value] :m){
  //      cout << key<<":"<<value<<endl;
  //  }

    vector<string> words = {"one","two","three"};
    map<string, int> counters;
    for (const auto& word :words){
         ++counters[word];  
    }
    PrintMap(counters);


    map<char, vector<string>> c;
    for (const auto& s : words){
        c[s[0]].push_back(s);
    }

    for(const auto& a : c){
        cout << a.first<<endl;
        for (const auto& wo : a.second){
            cout<<wo<<" ";
        }
    }




    map<int, string> m = {{1, "odd"}, {2, "even"}, {1, "one"}};
    m[2] = "two";
    m.erase(1);
    m[3] = "three";
    m.erase(4);
    m[5] = "five";
    cout << m.size();

    return 0;
}
