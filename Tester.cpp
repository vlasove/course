#include <iostream>
#include <vector>
#include <map>
#include <string>


using namespace std;

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

    private:
        map<int, string> name;
        map<int, string> family;

};

int main(int argc, char const *argv[])
{
   
    return 0;
}
