#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

template <class It>
void PrintRange(It range_begin,
                It range_end)
{
    for (auto it = range_begin; it != range_end; ++it)
    {
        cout << *it << ", ";
    }
    cout<<endl;
}

int main(){
    vector<string> langs = {
        "Python",
        "Java",
        "C#",
        "C",
        "C++"
    };
    PrintRange(langs.begin(), langs.end());

    //find element
    auto it = find(langs.begin(), langs.end(), "C#");

    //and delete it
    langs.erase(it, langs.end());
    PrintRange(langs.begin(), langs.end());

    //inserting C++
    langs.insert(langs.begin(), "C++");
    PrintRange(langs.begin(), langs.end());
    //inserting C++
    langs.insert(langs.end(), "C++");
    PrintRange(langs.begin(), langs.end());

    




    return 0;
}