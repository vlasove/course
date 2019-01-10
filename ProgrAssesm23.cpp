#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
      map[year][0] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
    map[year][1] = last_name;
  }
  string GetFullName(int year) {
    // получить имя и фамилию по состоянию на конец года year
    if(map.size() == 0){
        return "Incognito";
    }
    return (map[year][0]+" "+map[year][1]);
  }
private:
    map<int, vector<string>> bag;
};


int main(int argc, char const *argv[])
{
    
    return 0;
}
