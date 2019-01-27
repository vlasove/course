#include <iostream>
#include <vector>
#include <istream>
#include <string>
#include <sstream>


using namespace std;

struct Student{
    string name;
    string last_name;
    int day;
    int month;
    int year;
    void clear(){
        name = "";
        last_name = "";
        day = 0;
        month = 0;
        year = 0;
    }
};


vector<string> DevideFunc(string& s){
    vector<string> t;
    stringstream ss(s);
    string line;

    while(getline(ss, line, ' ')) {
        t.push_back(line);
    }

   
    return t;

}

int main(int argc, char const *argv[])
{
    int n;
    vector<Student> stud_vec;
    string temp;
    cin >> n;
    for(int i =0; i < n; i++){
            Student student;
            cin>> student.name>>student.last_name>>student.day>>student.month>>student.year;
            //cout<<student.name<<endl;
            stud_vec.push_back(student);
            
    }

    int k, num;
    string request;
    cin >> k;
    for(int j =0; j < k;j++){
        cin>>request>>num;
        if(request == "name" && num-1 >= 0 && num-1 < n){
            cout<<stud_vec[num-1].name<<" "<<stud_vec[num-1].last_name<<endl;
        }else if(request == "date"&& num-1 >= 0 && num-1 < n){
            cout<<stud_vec[num-1].day<<'.'<<stud_vec[num-1].month<<'.'<<stud_vec[num-1].year<<endl;
        }else{
            cout<<"bad request"<<endl;
        }
        

    }

    
    
    return 0;
}
