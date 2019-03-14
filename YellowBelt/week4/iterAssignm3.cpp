#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <string>


using namespace std;

template <class It>
void PrintRange(It range_begin,
                It range_end)
{
    for (auto it = range_begin; it != range_end; ++it)
    {
        cout << *it << endl;
    }
}

vector<string> SplitIntoWords(const string& s){
    vector<string> temp;
    auto startWord = s.begin();
    auto finishWord = find_if(s.begin(), s.end(),
                          [](const char &item) {
                              return item == ' ';
                          });
    while (true){
        temp.push_back({startWord,finishWord});
        if (finishWord == s.end()){
            break;
        }
        startWord = finishWord+1;
        finishWord = find_if(startWord, s.end(),
                          [](const char &item) {
                              return item == ' ';
                          });
        

    }
    return temp;

}



int main(){

    string s = "C Cpp Java Python";

    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
         cout << "/";
        }
    cout << *it;
    }
    cout << endl;



    
    

    return 0 ;

}