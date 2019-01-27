#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> unique;
    for(auto item : m){
        unique.insert(item.second);
    }

    return unique;


}

int main(int argc, char const *argv[])
{
    
    set<string> values = BuildMapValuesSet({
    {1, "odd"},
    {2, "even"},
    {3, "odd"},
    {4, "even"},
    {5, "odd"}
                                        });

    for (const string& value : values) {
    cout << value << endl;
}
    return 0;
}
