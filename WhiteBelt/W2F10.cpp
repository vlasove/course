#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

void PrintSet(const set<string>& s){
    cout<<s.size()<<endl;
    for(auto x : s){
        cout<< x<<endl;
    }
}

int main(int argc, char const *argv[])
{
    set<string> is_famous;
    is_famous.insert("Stroustrup");
    is_famous.insert("Ritchie");
    is_famous.insert("Stroustrup");

    vector<string> months = {"January","February","March","April"};

    set<string> m(begin(months), end(months));
    PrintSet(m);



    //PrintSet(is_famous);

    return 0;
}
