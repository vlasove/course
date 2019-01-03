#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string a = "aasdaskmsalkdjaskl;dksa";
    for (int i =0; i <a.size(); ++i) {
        if(a[i]  == 'a'){
            cout << i << endl;
        }

    }
    return 0;
}
