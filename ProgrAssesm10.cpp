#include <iostream>
#include <vector>
#include <string>
//#include <map>
using namespace std;


void worry_counter(const vector<string>& v){
    string test = "WORRY";
    int counter = 0;
    for (auto j : v){
        if (j == test){
            counter++;
        }
    }
    cout << counter << endl;

}

void come_func(vector<string>& v, int ppl){
    string sample = "QUIET";
    if (ppl >= 0 ){
        for(int i = 0; i < ppl; i++){
            v.push_back(sample);
        }

    }else{
        v.resize(v.size()+ppl);
    }
}


void worry_marker(vector<string>& v, int pos){
    string sample = "WORRY";
    v[pos] = sample;
}


void quiet_marker(vector<string>& v, int pos){
    string sample = "QUIET";
    v[pos] = sample;
}


int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    //vector<string> commands(n);
    vector<string> que;
    int c = 0;
    while (c < n){
        int num;
        string command;

        cin >> command;;

        if(command =="WORRY"){
            cin>>num;
            worry_marker(que, num);
        }

        if(command == "QUIET"){
            cin>>num;
            quiet_marker(que, num);
        }

        if(command == "COME"){
            cin>>num;
            come_func(que,num);
        }

        if (command == "WORRY_COUNT"){
            worry_counter(que);

        }

        c++;
    }

    

    return 0;
}
