#include <iostream>
#include <string>
#include <vector>

using namespace std;

void add_func(vector<vector<string>>& month, int date, string issue){
    month[date-1].push_back(issue);
}


void PrintVector(const vector<string>& date){
    cout<< date.size();
    for (auto s : date){
        cout<<" "<<s;

    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >>n;
    cout<<"Work";
    vector<vector<string>> m;
    cout<<"Work";
    add_func(m, 3,"Salary");
    cout<<"Work";
    PrintVector(m[2]);
    cout<<"Alles";

    return 0;
}
