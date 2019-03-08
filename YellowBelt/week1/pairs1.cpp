#include <iostream>
#include <vector>
#include <tuple>


using namespace std;

struct Date{
    int year;
    int month;
    int day;
};


//bool operator<(const Date& lhs, const Date& rhs){
 //   if (lhs.year!= rhs.year){
 //       return lhs.year < rhs.year;
 //   }
 //   if (lhs.month != rhs.month){
 //       return lhs.mongth < rhs.month;
 //   }
 //   return lhs.day<rhs.day;
//}


bool operator < (const Date& lhs, const Date& rhs){
    return tie(lhs.year, lhs.month, lhs.day) < tie(rhs.year, rhs.month, rhs.day);
}


int main(){

    cout <<(Date{2017, 8, 12} < Date{2017, 1,26})<<endl;



    return 0;
}