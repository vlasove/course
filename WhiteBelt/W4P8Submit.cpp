#include <iostream>
#include <fstream>
#include <string>


using namespace std;

void ReadAll(const string& path){

    string line;
    ifstream input(path);
    if(input.is_open()){
        while(getline(input, line)){
            cout<<line<<endl;
        }
    }
}

void ReadWriteAll(const string& path){
    string line;
    ifstream input(path);
    ofstream output("output.txt");
    if(input.is_open()){
        while(getline(input, line)){
            output<<line<<endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    string path = "input.txt";
    //ReadAll(path);
    ReadWriteAll(path);
    //ReadAll("output.txt");

    return 0;
}
