#include <iostream>
#include <map>
#include <string>

using namespace std;

void PrintMap(const map<int, string>& n){
    cout<<n.size()<<endl;
    for(auto item :n){
        cout<< item.first <<":"<<item.second<<endl;
    }
}

void PrintReversedMap(const map<string, int>& n){
    cout<<n.size()<<endl;
    for(auto item :n){
        cout<< item.first <<":"<<item.second<<endl;
    }
}

map<string, int> BuildReverseMap(const map<int, string>& m){
    map<string, int> n;
    for (auto item: m){
        n[item.second] = item.first;
    }
    return n;
}

int main(int argc, char const *argv[])
{
    map<int, string> events;
    events[1950] = "Bjarne birth";
    events[1941] = "Rithcie's birth";
    events[1970] = "UNIX epoch start";
    PrintMap(events);
    events.erase(1970);
    PrintMap(events);


    //map<string,int> non_events = BuildReverseMap(events);
    PrintReversedMap(BuildReverseMap(events));
    return 0;
}
