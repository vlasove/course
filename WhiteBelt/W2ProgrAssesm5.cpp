#include <iostream>
#include <vector>
#include <string>
using namespace std;


void MoveString(vector<string>& source, vector<string>& destination) {

    for(auto word : source){
        destination.push_back(word);
    }
    source.clear();



}

int main(int argc, char const *argv[])
{
    vector<string> a = {"a", "b", "c"};
    vector<string> b = {"z"};

    MoveString(a,b);
    for (auto i : a){
        cout << i;
    }

    for (auto j : b){
        cout << j;
    }
    return 0;
}
