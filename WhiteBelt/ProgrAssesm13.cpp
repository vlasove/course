#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

void change_capital_func(map<string, string>& m, string cntry, string cptls){
    if(m.count(cntry)==0){
        m[cntry] = cptls;
        cout<<"Introduce new country "<<cntry<<" with capital "<<m[cntry]<<endl;
    }
    else if(m[cntry] == cptls){
        cout<<"Country "<<cntry<<" hasn't changed its capital"<<endl;
    }
    else if(m.count(cntry) !=0 && m[cntry] != cptls){
        cout<<"Country "<<cntry<<" has changed its capital from "<<m[cntry]<<" to "<<cptls<<endl;
        m[cntry] = cptls;
    }
}


void rename_func(map<string, string>& m, string old_country, string new_country){
    if(old_country == new_country || m.count(old_country) == 0 || m.count(new_country) >0){
        cout <<"Incorrect rename, skip"<<endl;
    }else{
        cout<<"Country "<<old_country<<" with capital "<<m[old_country]<<" has been renamed to "<<new_country<<endl;
        m[new_country] = m[old_country];
        m.erase(old_country);
    }
}


void about_func(map<string, string>& m, string cntry){
    if(m.count(cntry) == 0){
        cout<<"Country "<<cntry<<" doesn't exist"<<endl;
    }else{
        cout<<"Country "<<cntry<<" has capital "<<m[cntry]<<endl;
    }
}


void dump_func(const map<string, string>& m){
    if(m.size() ==0){
        cout<<"There are no countries in the world"<<endl;
    }else{
        for(const auto& t : m){
            cout<<t.first<<"/"<<t.second<<" ";
        }
        cout<<endl;
    }
}

int main(int argc, char const *argv[])
{
    map<string, string> capitals_map;
    int n;
    cin >> n;
    string country, capital, command, country_help;;

    for (int i= 0; i < n; i++){
        cin >> command;
        if(command == "CHANGE_CAPITAL"){
            cin >> country >> capital;
            change_capital_func(capitals_map, country, capital);
        }
        if(command == "RENAME"){
            cin >>country>>country_help;
            rename_func(capitals_map, country, country_help);

        }
        if(command =="ABOUT"){
            cin >> country;
            about_func(capitals_map,country);
        }
        if(command == "DUMP"){
            dump_func(capitals_map);
        }

        
    }
    return 0;
}
