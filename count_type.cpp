#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,5,3,4,5,6,7};
    string s = "abcdefg";
    for (auto c :nums){
        cout << c << ",";
    }
    return 0;
}
