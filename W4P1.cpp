#include <iostream>
#include <string>

using namespace std;

struct Day{
    int value;
    explicit Day(int new_value){
        value = new_value;
    }
};

struct Month{
    int value;
    explicit Month(int new_month){
        value = new_month;
    }
};

struct Year{
    int value;
    explicit Year(int new_year){
        value = new_year;
    }
};

struct Date{
    int day;
    int month;
    int year;

    Date(Day new_day, Month new_month, Year new_year){
        day = new_day.value;
        month = new_month.value;
        year = new_year.value;
    }
};

void PrintDate(const Date& d){
    cout <<"Day: "<<d.day<<" Month:"<<d.month<<" Year:"<<d.year<<endl;
}

int main(int argc, char const *argv[])
{
    Date date = {Day{1},Month{1},Year{2017}};
    PrintDate(date);
    return 0;
}
