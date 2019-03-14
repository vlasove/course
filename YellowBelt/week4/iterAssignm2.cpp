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

int main()
{

    for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
            cout << x << " ";
    }
    cout << endl;
        
    string to_find = "Python";
    cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;

    return 0;
}