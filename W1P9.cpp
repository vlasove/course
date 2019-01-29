#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <map>
#include <set>



using namespace std;

class Cities{
    public:
        tuple<bool, string> FindCountry(const string& city) const {
            if(city_to_country.count(city) ==1){
                return make_tuple(true, city_to_country.at(city));
            }else if (ambig_cities.count(city) == 1){
                return make_tuple(false, "Ambiguous");
            }else{
                return make_tuple(false, "Not Exists");
            }

        }

    private:
        map<string, string> city_to_country;
        set<string> ambig_cities;
};

int main(){

    Cities cities;
    bool success;
    string message;
    tie(success, message) = cities.FindCountry("Moscow");
    auto t = cities.FindCountry("Moscow");
    cout << get<0>(t)<< get<1>(t)<<endl;

    cout <<success << " in "<< message<<endl;


    return 0;
}