#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

void Print(const vector<string>& names, const vector<double>& values){
    for(const auto& i : names){
        cout<<setw(10)<< i<< " ";
    }

    cout<<endl;
    cout<<fixed<<setprecision(2);
    //cout<<setw(10);

    for(const auto& j : values){
        cout<<setw(10)<< j<< " ";
    }

}

int main(int argc, char const *argv[])
{
    vector<string> names = {"a", "b","c"};
    vector<double> values = {5, 0.01, 0.000005};
    cout<<setfill('.');
    cout<<left;
    Print(names, values);



    return 0;
}
