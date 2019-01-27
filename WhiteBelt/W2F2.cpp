#include <iostream>
#include <vector>
#include <string>
using namespace std;


void PrintWords(vector<string> words){
    for (auto word :words) {
        cout <<word<<" ";
    }
}

int main(int argc, char const *argv[])
{
    PrintWords({"air","fire","fog"});
    return 0;
}
