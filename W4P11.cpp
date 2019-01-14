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
    int n;
    int day, month, year;
    string name, last_name;
    vector<Student> stud_vec;
    cin >> n;
    for(int i =0; i <n; i++){
        Student student;
        cin>>name>>last_name>>day>>month>>year;
        cin
        student.name = name;
        student.last_name = last_name;
        student.day = day;
        student.month = month;
        student.year = year;
        stud_vec.push_back(student);
    }

    int counter;
    int value;
    string request;
    cin >> counter;
    for(int j = 0; j<counter; j++){
        cin>> request;
        if(request != "name" || request != "date"){
            cout<<"bad request"<<endl;
        }else{
            cin>>value;
            if(request == "name"){
                cout<<stud_vec[value-1].name<<" "<<stud_vec[value-1].last_name<<endl;
            }
            if(request == "date"){
                cout<<stud_vec[value-1].day<<'.'<<stud_vec[value-1].month<<'.'<<stud_vec[value-1].year<<endl;
            }
        }
    }
    
    return 0;
}
