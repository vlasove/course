#include <iostream>
#include <map>
#include <vector>

using namespace std;

template<typename K, typename V>
V& GetRefStrict(map<K,V>& m, const K& item){
    if(m.count(item) == 0 ){
        throw runtime_error("");
    }
    return m[item];
}
