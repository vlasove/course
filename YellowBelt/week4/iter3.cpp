#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using LangIt = vector<string>::iterator;

struct Lang
{
    string name;
    int age;
};
template<class It>
void PrintRange(It range_begin,
                It range_end)
{
    for (auto it = range_begin; it != range_end; ++it)
    {
        cout << *it << endl;
    }
}

int main()
{

    vector<string> langs = {
        "Python",
        "C++",
        "Java",
        "C#"};

    PrintRange(langs.begin(), langs.end());
    PrintRange(langs[0].begin(), langs[0].end());

    auto result = find_if(langs.begin(), langs.end(),
                          [](const string &lang) {
                              return lang[0] == 'C';
                          });
    

    return 0;
}