#include <iostream>
#include <tuple>

using namespace std;

struct Date{
    int year;
    string month;
    int day;
};

bool operator<(const Date& lhs, const Date& rhs){
    auto lhs_key = tie(lhs.year, lhs.month, lhs.day);
    auto rhs_key = tie(rhs.year, rhs.month, rhs.day);
    return lhs_key < rhs_key;
}


int main(){

    cout << (Date{2019, "May", 2} < Date{2029,"June", 2})<<endl;
    cout<<"Mega Lol"<<endl;
    return 0;
}