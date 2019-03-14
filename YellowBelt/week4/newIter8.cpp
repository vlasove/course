#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <iterator>

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

    vector<string> c_langs;

    copy_if(langs.begin(), langs.end(), back_inserter(c_langs),
                [](const string& lang){
                    return lang[0] == 'C';
                });

    PrintRange(c_langs.begin(), c_langs.end());



    return 0;
}