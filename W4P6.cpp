#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void ReadAll(const string& path){
    string line;
        ifstream input(path);
        if(input.is_open()){
            getline(input,line);
            cout<<line;
        }

}

int main(int argc, char const *argv[])
{
    string path = "output.txt";
    string line;
    ofstream output(path);
    output<<"hello"<<endl;
    ReadAll(path);
    return 0;
}
