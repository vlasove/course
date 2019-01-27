#include <iostream>
#include <iomanip>
#include <exception>
#include <sstream>

using namespace std;

struct Date{
    int year;
    int month;
    int day;
};


void SkipperPipper(stringstream& stream){
    if(stream.peek() !='/'){
        stringstream ss;
        ss << "expected /, but has :"<<char(stream.peek());
        throw runtime_error(ss.str());
    }
    stream.ignore(1);

}
Date ParseDate(const string& s){
    stringstream stream(s);
    Date date;
    stream>>date.year;
    SkipperPipper(stream);
    stream>>date.month;
    SkipperPipper(stream);
    stream>>date.day;

    return date;


}

int main(int argc, char const *argv[])
{
    string date_str = "2017a01/25";

    try {
        Date date = ParseDate(date_str);
        cout<<setw(2)<<setfill('0')<<date.day<<'.'<<setw(2)<<setfill('0')<<date.month<<'.'<<date.year<<endl;
    } catch (exception& ex){
        cout<<"exception happens"<<ex.what();
    }
    
    
    
    return 0;
}
