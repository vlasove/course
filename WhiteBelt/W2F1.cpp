#include <iostream>
#include <vector>
#include <string>
using namespace std;


int Sum(int x, int y) {
    return x+y;
}

bool Contains(vector<string> words, string word) {
    for (auto s : words){
        if (s == word){
            return true;
        };
    }
    return false;
}
int main(int argc, char const *argv[])
{
    //int x,y;
    //cin >>x>>y;
    cout << Contains({"air","fire","fog"}, "fog");

    return 0;
}
