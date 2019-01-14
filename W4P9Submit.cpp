#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <iomanip>

using namespace std;

void ConvertAndReadAll(const string& path){
    string line;
    ifstream input(path);
    if(input.is_open()){
        cout<<fixed<<setprecision(3);
        while(getline(input, line)){
            double lol = atof(line.c_str());
            cout<<lol<<endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    string path = "input.txt";
    ConvertAndReadAll(path);

    return 0;
}
