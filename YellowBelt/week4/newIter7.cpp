#include <algorithm>
#include <iostream>
#include <iterator>
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

    set<int> a = {1, 8, 3};
    set<int> b = {3, 6, 8};

    set<int> c;

    set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.end()));
    PrintRange(c.begin(), c.end());

    return 0;
}