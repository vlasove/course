#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> PalindromFilter(vector<string> words, int minLength){
    vector<string> filter,temp ;
    for (auto w :words){
        if(w.size() >= minLength){
            temp.push_back(w);
        }
    }

    //Palindrom check
    for (auto word : temp){
            bool tester = true;
            for (int i = 0; i < (word.size() / 2); i++){
                if (word[i] != word[(word.size() - 1) - i]) {
                    tester  = false;
                }
            }

        if(tester == true){
            filter.push_back(word);
        }
    }

    return filter;

}


int main(int argc, char const *argv[])
{
    for(auto c :PalindromFilter({"weew", "bro","code"},4)){
        cout << c <<" ";
    }
    return 0;
}
