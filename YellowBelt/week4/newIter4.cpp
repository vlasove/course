#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

template <class It>
void PrintRange(It range_begin,
                It range_end)
{
    for (auto it = range_begin; it != range_end; ++it)
    {
        cout << *it << ", ";
    }
    cout << endl;
}

int main()
{
    set<string> langs = {
        "Python",
        "C#",
        "C#",
        "C#",
        "Java",
        "C",
        "C++"};
    PrintRange(langs.begin(), langs.end());

    cout << all_of(langs.begin(), langs.end(),
                   [](const string &lang) {
                       return lang[0] >= 'A' && lang[0] <= 'Z';
                   });
    PrintRange(langs.begin(), langs.end());

    return 0;
}