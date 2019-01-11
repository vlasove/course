#include <map>
#include <vector>

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



    private:
        map<int, string> name;
        map<int, string> family;
};
