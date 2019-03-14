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

    partition(langs.begin(), langs.end(), 
            [](const string& lang){
                return lang[0] == 'C';
            });

    PrintRange(langs.begin(), langs.end());


    //copy_if

    vector<string> c_langs(langs.size());
    auto it = copy_if(langs.begin(), langs.end(), c_langs.begin(),
            [](const string& lang){
                return lang[0] == 'C';
            });
    PrintRange(c_langs.begin(), it);

    return 0;
}