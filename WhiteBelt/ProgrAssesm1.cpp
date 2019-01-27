#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> temp;
    string a,b,c;
    cin >> a >>b>>c;
    temp.push_back(a);
    temp.push_back(b);
    temp.push_back(c);
    sort(begin(temp), end(temp));
    cout << temp[0];
    return 0;
}
