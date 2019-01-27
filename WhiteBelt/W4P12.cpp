#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student{
    string name;
    string last_name;
    int day;
    int month;
    int year;
};

int main(int argc, char const *argv[])
{
    Student student({"lol", "kek", 1, 2,3});
    cout<<student.name<<endl;
    return 0;
}
