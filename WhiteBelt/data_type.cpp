#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Person{
    string name;
    string surname;
    int age;


};



int main(int argc, char const *argv[])
{

    vector<Person> staff;
    staff.push_back({"Ivan","Ivanov",25});
    staff.push_back({"Petr","Petrovv",32});

    cout <<staff[0].name;

    int x = -5;
    double pi = 3.14;
    bool logical_value = true;
    char symbol = 'z';
    string hw = "Hello World!";
    vector<int> nums = {1,2,3,4,5};
    map<string,int> name_to_value;
    name_to_value["one"] = 1;
    name_to_value["two"] = 2;

    cout<<"two is "<<name_to_value["two"];


    cout << nums.size();
    cout << "Alles ok!";
    cout << hw;

    return 0;
}
