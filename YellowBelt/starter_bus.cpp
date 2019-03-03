#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
  string typeRequest;
  is >> typeRequest;
  map<string, QueryType> wrap = {
    {"NEW_BUS", QueryType::NewBus},
    {"BUSES_FOR_STOP", QueryType::BusesForStop},
    {"STOPS_FOR_BUS", QueryType::StopsForBus},
    {"ALL_BUSES", QueryType::AllBuses}
  };

  q.type = wrap[typeRequest];
  is.ignore(1);
  switch(q.type){
    case QueryType::NewBus:

      is>>q.bus;
      //q.bus = bus_name;
      is.ignore(1);
      int n;
      is>>n;
      for(int i =0; i < n; ++i){
        is.ignore(1);
        string stop;
        is >>stop;
        //q.stop = stop_name;
        q.stops.push_back(stop);
      }

      case QueryType::BusesForStop:
        is>>q.stop;
        break;

      case QueryType::StopsForBus:
        is>>q.bus;
        break;

      case QueryType::AllBuses:
        break;
  };
  // Реализуйте эту функцию
  return is;
}

struct BusesForStopResponse {
  vector<string> buses;
  // Наполните полями эту структуру
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  if(r.buses.size() == 0){
    os<<"No stop";
  }else{
    for(const string& bus: r.buses){
      os<<bus<<" ";
    }
  }
  // Реализуйте эту функцию
  return os;
}

struct StopsForBusResponse {
  vector<string> stops;
  map<string, vector<string>> bus4stop;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  // Реализуйте эту функцию
  if(r.bus4stop.size() == 0){
    os<<"No bus";
  }else{
    for(const string& stop : r.stops){
      os<<"Stop "<<stop<<":";
      if(r.bus4stop.count(stop) == 0){
        os << " no interchange";
      }else{
        for (auto& bus: r.bus4stop.at(stop)){
          os<<" "<<bus;
        }
      }
    }
  }
 
  
  return os;
}

struct AllBusesResponse {
  // Наполните полями эту структуру
  map<string, vector<string>> stop4bus;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  if(r.stop4bus.size() == 0){
    os<<"No buses";
  }else{
    for(const auto& item : r.stop4bus){
      os<<"Bus "<<item.first<<":";
      for(const string& stop : item.second){
        os<<" "<<stop;
      }
      os<<endl;
    }
  }
  // Реализуйте эту функцию
  return os;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
    // Реализуйте этот метод
    for(const auto& q : stops){
      stops2buses[q].push_back(bus);
      buses2stop[bus].push_back(q);
    }
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
    // Реализуйте этот метод
    BusesForStopResponse result;
    if(stops2buses.count(stop) >0){
      result.buses = stops2buses.at(stop);
    }
    return result;
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
    // Реализуйте этот метод
    StopsForBusResponse result;
    if(buses2stop.count(bus) > 0){
      for(auto& stop : buses2stop.at(bus)){
        result.stops.push_back(stop);
        for(auto& bus_n: GetBusesForStop(stop).buses){
          if(bus_n != bus){
            cout<<"WOW"<<endl;
            result.bus4stop[stop].push_back(bus);
          }

        }
      }
    }
    return result;
  }

  AllBusesResponse GetAllBuses() const {
    // Реализуйте этот метод
    AllBusesResponse result;
    result.stop4bus = buses2stop;
    return result;

  }
private:
  map<string, vector<string>> stops2buses;
  map<string, vector<string>> buses2stop;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
