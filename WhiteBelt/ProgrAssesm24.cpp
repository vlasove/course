#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>


using namespace std;
//vector<string> map_sizer = {"",""}

string FindNameByYear(const map<int, string>& names, int year) {
  string name;  // изначально имя неизвестно
  
  // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
  for (const auto& item : names) {
    // если очередной год не больше данного, обновляем имя
    if (item.first <= year) {
      name = item.second;
    } else {
      // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
      break;
    }
  }
  
  return name;
}

string Parser(const vector<string>& s){

    if(s.empty()){
        return "";
    }else{
        string total ="";
        for(int i =0; i < s.size(); i++){
            if(i == 0 ){
                total += s[i];
            }else{
                total+=(", "+s[i]);
                }
        }
            if(total.size() == 0 ){
                return "";
            }
            return " ("+total+")";
        }
}


string JoinName(const map<int, string>& m, int year ){
    //1 -- отобрать по году все доступные значения
    vector<string> tmp,new_tmp;
    for(const auto& item : m){
        if(item.first <year){
            tmp.push_back(item.second);
        }
    }

    //2 -- удалить парные дубли

    if(tmp.size() > 2){
        for(int i =0;i < (tmp.size()-1);i++){
            if(tmp[i] != tmp[i+1]){
                new_tmp.push_back(tmp[i]);
            }
        }
        tmp = new_tmp;
    }
    const string last_item = FindNameByYear(m,year);

    //cout<<"lAST"<<tmp.size();

    //3 - проверить, если последний равен посленему действительно - удалить
    if(tmp.size() !=0 && tmp[tmp.size()-1] == last_item){
        tmp.pop_back();
    }
    //4 --- развернуть для хронологии
    reverse(tmp.begin(), tmp.end());

    return Parser(tmp);
    //return "a";

}


class Person{
    public:
        Person(const string& first_name, const string& last_name, int year)     {
            BirthYear = year;
            ChangeFirstName(BirthYear, first_name);
            ChangeLastName(BirthYear, last_name);
        }


        void ChangeFirstName(int year, const string& first_name){
            if(BirthYear <= year){
                first_names[year] = first_name;
            }

        }

        void ChangeLastName(int year, const string& last_name){
            if(BirthYear <= year){
                last_names[year] = last_name;
            }
            
    
        }

    string GetFullNameWithHistory(int year) const {
    // получаем имя и фамилию по состоянию на год year
    const string first_name = FindNameByYear(first_names, year);
    const string last_name = FindNameByYear(last_names, year);
    
    // если и имя, и фамилия неизвестны
    if ((first_name.empty() && last_name.empty()) || BirthYear > year) {
      return "No person";
    }
    
    // если неизвестно только имя
    else if (first_name.empty()) {
      return last_name+JoinName(last_names,year) + " with unknown first name";
      
    // если неизвестна только фамилия
    } else if (last_name.empty()) {
      return first_name+ JoinName(first_names,year) + " with unknown last name";
      
    // если известны и имя, и фамилия
    } else {
      return first_name+JoinName(first_names,year) + " " + last_name + JoinName(last_names,year);
    }
  }



string GetFullName(int year) const {
    // получаем имя и фамилию по состоянию на год year
    const string first_name = FindNameByYear(first_names, year);
    const string last_name = FindNameByYear(last_names, year);
    
    // если и имя, и фамилия неизвестны
    if ((first_name.empty() && last_name.empty()) || BirthYear > year) {
      return "No person";
    
    // если неизвестно только имя
    }
    else if (first_name.empty()) {
      return last_name + " with unknown first name";
      
    // если неизвестна только фамилия
    } else if (last_name.empty()) {
      return first_name + " with unknown last name";
      
    // если известны и имя, и фамилия
    } else {
      return first_name + " " + last_name;
    }
  }



       // string GetFullName(int year){
        //    if(PreviousCheck(name, year) == "" && PreviousCheck(family, year) == ""){
        //        return "Incognito";
        //    }else if (PreviousCheck(name, year) == "" && PreviousCheck(family, year) != ""){
        //        return PreviousCheck(family, year)+" with unknown first name";
        //    }else if(PreviousCheck(name, year) != "" && PreviousCheck(family, year) ==""){
        //        return PreviousCheck(name, year)+" with unknown last name";
        //    }else{
        //        return PreviousCheck(name, year)+" "+PreviousCheck(family, year);
        //    }
        //}


    private:
        map<int, string> first_names;
        map<int, string> last_names;
        int BirthYear;
};



int main(int argc, char const *argv[])
{   
    Person person("Polina", "", 1960);
    //person.ChangeFirstName(1960, "Appolinaria");
    for (int year : {1959, 1960, 1961, 1962}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
    
    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1905, 1915,1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

        
    return 0;
}
