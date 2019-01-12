#include <iostream>
#include <string>

using namespace std;

struct Specialization{
    string value;
    explicit Specialization(string new_spec){
        value = new_spec;
    }
};

struct Course{
    string value;
    explicit Course(string new_course){
        value = new_course;
    }
};

struct Week{
    string value;
    explicit Week(string new_week){
        value = new_week;
    }
};



struct LectureTitle {
    string specialization;
    string course;
    string week;

    LectureTitle(Specialization sp, Course co, Week we){
        specialization = sp.value;
        course = co.value;
        week = we.value;
    }
};
