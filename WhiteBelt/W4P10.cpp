#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{   
    int a,b;
    string line;
    ifstream input("input.txt");
    if(input.is_open()){
        //cout<<"Ok!"<<endl;
        input >>a>>b;
        while(getline(input,line)){
            cout<<line;
        }
      
    }else{
        cout<<"Cannot read this file"<<endl;
    }
    return 0;
}
