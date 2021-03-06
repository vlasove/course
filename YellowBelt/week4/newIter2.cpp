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
    vector<string> langs = {
        "Python",
        "C#",
        "Java",
        "C",
        "C++"};
    PrintRange(langs.begin(), langs.end());

    auto it = remove_if(langs.begin(), langs.end(), 
                [](const string& lang){
                    return lang[0] == 'C';
                });

    cout << *it<<endl;

    langs.erase(it, langs.end());

    PrintRange(langs.begin(), langs.end());

    return 0;
}