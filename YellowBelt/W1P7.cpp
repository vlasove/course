#include <iostream>
#include <vector>


using namespace std;

struct Date{
    int day;
    int month;
    int year;
};

bool operator<(const Date& lhs, const Date& rhs){
    return vector<int>{lhs.year, lhs.month, lhs.day}<
            vector<int>{rhs.year, rhs.month, rhs.day};
}

int main(){
    cout<< (Date{1,12,2015} < Date{1,12,2020})<<endl;

    return 0;
}