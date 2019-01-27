#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{

    map<string, int> dict = {{"a", 1} , {"b", 2} , {"c", 3}};
    int sum = 0;
    string conc ;
    for (auto i : dict){
        conc += i.first;
        sum += i.second;

    }
    cout << sum<<conc<<endl;
    return 0;
}
