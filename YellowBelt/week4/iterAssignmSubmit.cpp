#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void PrintVectorPart(const vector<int> &numbers)
{
    auto result = find_if(numbers.begin(), numbers.end(),
                          [](const int lang) {
                              return lang < 0;
                          });
    while(result!= numbers.begin()){
        --result;
        cout<<*result<<" ";

    }
    
}