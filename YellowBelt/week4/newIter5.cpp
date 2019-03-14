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
        "C#",
        "C#",
        "Java",
        "C",
        "C++"};
    PrintRange(langs.begin(), langs.end());

    sort(langs.begin(), langs.end());
    PrintRange(langs.begin(), langs.end());
    sort(langs.rbegin(), langs.rend());
    PrintRange(langs.begin(), langs.end());


    auto it = find_if(langs.rbegin(), langs.rend(),
                    [](const string& lang){
                        return lang[0] == 'C';
                    });
    cout << *it<<endl;


    return 0;
}