#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

void stops_checker(map<vector<string>, int>& m, int& c, vector<string> s){
    if(m[s] == 0){
        m[s] = c;
        cout<<"New bus "<<c<<endl;
        c++;
    }else{
        cout<<"Already exists for "<<m[s]<<endl;
    }


}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int stops_counter, num_checker;
    num_checker = 1;
    vector<string> stops;
    string stop;
    map<vector<string>, int> checker;

    for (int i = 0; i < n; i++){
        cin>>stops_counter;
        for(int j = 0; j < stops_counter; j++){
            cin>>stop;
            stops.push_back(stop);
            
        }
        stops_checker(checker, num_checker, stops);
        stops.clear();

    }
    return 0;
}
