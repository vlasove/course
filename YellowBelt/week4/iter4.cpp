#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LangIt = vector<string>::iterator;

struct Lang
{
    string name;
    int age;
};
template <class It>
void PrintRange(It range_begin,
                It range_end)
{
    for (auto it = range_begin; it != range_end; ++it)
    {
        cout << *it << endl;
    }
}

template <class It>
void PrintMapRange(It range_begin,
                It range_end)
{
    for (auto it = range_begin; it != range_end; ++it)
    {
        cout << it->first<<" "<<it->second << endl;
    }
}

int main()
{

    set<string> langs = {
        "Python",
        "C++",
        "Java",
        "C#"};

    PrintRange(langs.begin(), langs.end());
    //PrintRange(langs[0].begin(), langs[0].end());

    auto result = find_if(langs.begin(), langs.end(),
                          [](const string &lang) {
                              return lang[0] == 'C';
                          });

    auto it = langs.find("C++");
    PrintRange(langs.begin(), it);

    map<string, int> langs2 = {
        {"Python", 26},
        {"C++", 34},
        {"Java", 22},
        {"C#", 17}};

    PrintMapRange(langs2.begin(), langs2.end());

    return 0;
}