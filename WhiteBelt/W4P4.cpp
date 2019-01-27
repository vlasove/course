#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream input("hello.txt");
    string line;
    if(input.is_open()){
        while(getline(input, line)){
            cout<<line<<endl;
        }

    }else{
        cout<<"Cannot open this file"<<endl;
    }

 
    

    
    return 0;
}
