#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,5,3,4,5,6,7};
    int count1 = 0;

    //string s = "abcdefg";
    for (auto c :nums){
        if (c == 5) {
            count1 += 1;
        }
    }

    cout <<" 5 in nums is "<<count1;



    int count2 = count(begin(nums), end(nums),5);
    cout <<"There are "<< count2 << "fives\n";

    sort(begin(nums), end(nums));
    for (auto x : nums) {
        cout << x <<"\n";
    }
    return 0;
}
