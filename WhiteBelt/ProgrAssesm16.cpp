#include <iostream>
#include <set>
#include <string>


using namespace std;

int main(int argc, char const *argv[])
{   
    set<string> unique;
    string word;
    int n;
    cin >> n;
    for(int i = 0; i< n; i++){
        cin>>word;
        unique.insert(word);
    }

    cout<<unique.size()<<endl;
    return 0;
}
