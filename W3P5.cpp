#include <iostream>
#include <vector>
#include <string>


using namespace std;

struct LectureTitle{
    string specialization;
    string course;
    string week;
};

struct DetailedLecture{
    LectureTitle title;
    int duration;
};

int main(int argc, char const *argv[])
{
    LectureTitle lt = {"C++", "White belt", "OOP"};
    DetailedLecture lecture1 = {lt, 500};
    DetailedLecture lecture2 = {{"C++","Yellow belt","OOP2"}, 5400};

    cout<<lecture1.title.course<<endl;
    cout<<lecture2.title.course<<endl;
    

    return 0;
}
