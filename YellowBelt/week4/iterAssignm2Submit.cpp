#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;




template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border){

    vector<T> temp;


    auto results = find_if(elements.begin(), elements.end(),
                          [border](const T& item) {
                              return item > border;
                          });
    if (results == elements.end()){
        return temp;
    }

    auto it = results;
    
    while( it != elements.end()){
        
        temp.push_back(*it);
        ++it;
    }

    return temp;
}
