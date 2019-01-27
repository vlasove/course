#include <iostream>
#include <vector>
#include <string>
#include <string>

using namespace std;

struct Lecture{
    string title;
    string author;
    int duration;
};

void PrintLecture(const Lecture& lect){
    cout << "Title "<< lect.title<<endl;
    cout<< "Author "<<lect.author<<endl;
    cout<<"Duration "<<lect.duration<<endl;
}

void PrintCourse(const vector<Lecture>& lect){
    for(const auto& item : lect){
        PrintLecture(item);
    }
}

int main(int argc, char const *argv[])
{
    Lecture Abs, Bcd;
    Abs.title = "C++";
    Abs.author = "Shiskoff";
    Abs.duration = 500;
    Bcd = {"OOP","Anton", 400};
    vector<Lecture> a = {Abs, Bcd};

    PrintCourse(a);   
    return 0;
}



