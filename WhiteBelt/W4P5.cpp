#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream input("date.txt");
    string year, month, day;
    if(input.is_open()){
        getline(input, year,'-');
        getline(input, month,'-');
        getline(input, day,'-');

    }else{
        cout<<"Cannot Open this file!"<<endl;
    }

    cout<< year<<" "<<month<<" "<<day<<endl;
    return 0;
}
