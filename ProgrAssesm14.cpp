#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


void new_bus_func(map<string, vector<string>>& m, string b, int bus_c, vector<string> stop_vector){
    m[b] = stop_vector;
}

void all_busses_func(const map<string, vector<string>>& m){
    if(m.size() == 0){
        cout<<"No buses"<<endl;
    }else{
        for(const auto& item : m){
            cout<<"Bus "<<item.first<<":";
            for (const auto& j :item.second){
                cout<<" "<<j;
            } cout<<endl;
        }
        
    }
}

bool stop_check( const map<string, vector<string>>& m, string stp){
    for (const auto& item : m){
        for(const auto& j : item.second){
            if(j == stp){
                return true;
            }
        }
    }
    return false;

}

bool stop_in_bus_check(const vector<string>& stops, string stp){
    for(auto j : stops){
            if( j == stp){
                return true;
            }
    }
    return false;
}

void busses_for_stop_func( map<string, vector<string>>& m, const map<int, string>& c, string stp){
    if(c.size() ==0 || !stop_check(m,stp)){ 
        cout<<"No stop"<<endl;
    }else{
        //cout<<"Stop "<<stp<<":";
        for (auto k : c){
            for(auto j :m[k.second]){
                if(j == stp){
                    cout<<k.second<<" ";
                }

            }
        } cout<<endl;
        
    }
}




void stop_for_bus_func(map<string, vector<string>>& m, map<int, string>& c, string b){
    map<string, vector<string>> summary;
    if(m.count(b) == 0){
        m.erase(b);
        cout<<"No bus"<<endl;
    }else{

    
    map<int, string> stops_counter;
    int counter_s = 0;
    vector<string> stops = m[b];
    for (auto j : stops){
        for(auto i : c){
            if(stop_in_bus_check(m[i.second], j)){
                summary[j].push_back(i.second);
            }
        }
        stops_counter[counter_s] = j;
        counter_s++;

    }

    for(auto temp : stops_counter){
        if(summary[temp.second].size() == 1){
            cout<<"Stop "<<temp.second<<":"<<" no interchange"<<endl;
        }else{
            cout<<"Stop "<<temp.second<<":";
                for(auto w: summary[temp.second]){
                if(w == b){
                    continue;
                }
                cout<<" "<<w;
                }cout<<endl;
        }
    }
    }



   // for(auto item : summary){
   //     if(item.second.size() == 1){
   //         cout<<"Stop "<<item.first<<":"<<" no interchange"<<endl;
   //     }else{
   //         cout<<"Stop "<<item.first<<":";
    //        for(auto w: item.second){
    //            if(w == b){
    //                continue;
   //             }
   //             cout<<" "<<w;
   //         }cout<<endl;
   //     }
    //}

}



int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    map<string, vector<string>> bus_map;
    map <int, string> bus_counter;
    int bus_maker = 0;
    string command, bus;
    int stop_count;
    string stop;
    vector <string> bus_stops;

    for (int i =0; i < n; i++){
        cin>>command;
        if(command == "NEW_BUS"){
            cin>>bus>>stop_count;
            for (int j =0; j <stop_count; j++){
                cin>>stop;
                bus_stops.push_back(stop);
            }
            new_bus_func(bus_map, bus, stop_count, bus_stops);
            bus_stops.clear();
            bus_counter[bus_maker] = bus;
            bus_maker++;
        }
        if(command == "ALL_BUSES"){
            all_busses_func(bus_map);
        }

        if (command == "BUSES_FOR_STOP"){
            cin>>stop;
            busses_for_stop_func(bus_map, bus_counter, stop);
            
        }

        if(command == "STOPS_FOR_BUS"){
            cin>>bus;
            stop_for_bus_func(bus_map, bus_counter, bus);
        }

    }
    return 0;
}
