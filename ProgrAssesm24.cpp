#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <algorithm>


using namespace std;
//vector<string> map_sizer = {"",""}


class Person{
    public:
        void ChangeFirstName(int year, const string& first_name){
            name[year] = first_name;
        }

        void ChangeLastName(int year, const string& last_name){
            family[year] = last_name;
    
        }

        string PreviousCheck(map<int, string>& m, int year){
            if(m.count(year)>0){
                return m[year];
            }else{
                vector<int> pack;
                //pack.clear();

                for (const auto& item : m){
                    if(item.first < year){
                        pack.push_back(item.first);
                    } 
                }
                if(pack.empty()){
                    return "";
                }else{
                    //int keyser = pack.end();
                    return m[pack[pack.size()-1]];
                }
            }
        }

        string GetFullName(int year){
            if(PreviousCheck(name, year) == "" && PreviousCheck(family, year) == ""){
                return "Incognito";
            }else if (PreviousCheck(name, year) == "" && PreviousCheck(family, year) != ""){
                return PreviousCheck(family, year)+" with unknown first name";
            }else if(PreviousCheck(name, year) != "" && PreviousCheck(family, year) ==""){
                return PreviousCheck(name, year)+" with unknown last name";
            }else{
                return PreviousCheck(name, year)+" "+PreviousCheck(family, year);
            }
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
                if(total.empty()){
                    return "";
                }

                return " ("+total+")";

                }

        }

        string GetFullNameWithHistory(int year){

            string name_history, tnh;
            string family_history;

            for(const auto& item : name){
                if(item.first < year){
                    name_history.push_back(item.second);
                }
            }
            for(const auto& item : family){
                if(item.first < year){
                    family_history.push_back(item.second);
                }
            }

            if(name_history.size() == 1 && name_history.back() == PreviousCheck(name,year)){
                name_history.clear();
            }
            if(name_history.size() > 1){
                tnh.push_back(name_history[0]);
                for(int i = 1; i < name_history.size(); i ++){
                    if(name_history[i-1] == name_history[i]){
                        continue;
                    }else{
                        tnh.push_back(name_history[i]);
                    }
                }

                if(tnh[tnh.size()-1] == PreviousCheck(name, year)){
                    tnh.pop_back();
                }

                reverse(tnh.begin(), tnh.end());
                name_history = tnh;
            }
           
            return name_history;




        }


    private:
        map<int, string> name;
        map<int, string> family;
};



int main(int argc, char const *argv[])
{   
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;
  
  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;
  
  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;
 
    
    return 0;
}
