#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>

using namespace std;

void bag_compounder(map< set<string>, int>& b, set<string> s, int& ch){
    int temp = 0;
    if(b.size() == 0){
        b[s] = ch;
        cout<<"New bus "<<ch<<endl;
        ch++;
    }else{
        for(const auto& j : b){
            if(j.first == s){
                temp++;
            }
        }

        if(temp !=0){
            cout<<"Already exists for "<< b[s]<<endl;
        }else{
            cout<<"New bus "<<ch<<endl;
            b[s] = ch;
            ch++;
        }
    }


}

int main(int argc, char const *argv[])
{
    int n, counter;
    int checker = 1;
    set<string> stops;
    string word;
    map<set<string>, int> bag;
    cin >>n;

    for(int i = 0; i<n; i++){
        cin >> counter;
        for(int j = 0; j < counter; j++){
            cin >> word;
            stops.insert(word);
        }
            bag_compounder(bag, stops,checker);
            stops.clear();
    }
    return 0;
}
