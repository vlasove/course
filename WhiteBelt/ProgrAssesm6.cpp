#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    string temp;
    cin >> temp;
    char t = 'f';
    int counter = 0;
    vector<int> test;
    for (int i =0; i < temp.size(); i++){
        if(t == temp[i]){
            counter += 1;
            test.push_back(i);

        }
    }
    //cout << counter;
    if (counter == 0){
        int a = -2;
        cout << a;
    } else if (counter == 1){
        int b = -1;
        cout << b;
    }else{
        cout<<test[1];
    }
    return 0;
}
