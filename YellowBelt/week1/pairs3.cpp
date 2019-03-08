#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <string>
#include <map>
#include <set>

using namespace std;

class Cities{
    public:
        tuple<bool, string> FindCountry(const string& city) const{
            if(city_to_country.count(city) == 1){
                return make_tuple(true, city_to_country.at(city));
            }else if (ambigious_country.count(city) == 1){
                return make_tuple(false, "Ambigious");
            }else{
                return make_tuple(false, "Not exist");
            }

        }


    private:
        map<string, string> city_to_country;
        set<string> ambigious_country;


};

int main(){

    Cities cities;
    bool success;
    string message;
    tie(success, message) = cities.FindCountry("Volgograd");
    cout << success << " and " <<message<<endl;


    return 0;
}