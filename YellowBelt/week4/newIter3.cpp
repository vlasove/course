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

    cout<<"Min finder: "<<endl;
    auto min = min_element(langs.begin(), langs.end());
    cout<<*min<<endl;

    cout<<"Max finder: "<<endl;
    auto max = max_element(langs.begin(), langs.end());
    cout<<*max<<endl;

    auto p = minmax_element(langs.begin(), langs.end());
    cout<<"Min is : "<< *p.first <<" and Max is :"<<*p.second<<endl;


    auto it = unique(langs.begin(), langs.end());

    PrintRange(langs.begin(), langs.end());
    langs.erase(it, langs.end());
    PrintRange(langs.begin(), langs.end());



    return 0;
}