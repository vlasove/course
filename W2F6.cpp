#include <iostream>
#include <vector>
#include <string>
using namespace std;

void PrintVector(const vector<int>& vec){
    cout<<"=================Personal List of Days==================="<<endl;
    for (auto temp : vec){
        cout<<temp<<endl;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> days_in_months = {31,28,31,30,31};
    PrintVector(days_in_months);
    if (true){
        days_in_months[1] +=1;
    }
    PrintVector(days_in_months);
    cout<<"\n"<<days_in_months.size()<<endl;
    days_in_months.resize(1);
    cout<<"\n"<<days_in_months.size()<<endl;
    days_in_months.clear();
    cout<<"\n"<<days_in_months.size()<<endl;
    
    return 0;
}
