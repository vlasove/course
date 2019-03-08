#include <iostream>
#include <map>
#include <exception>

using namespace std;

template<class K, class V>
V& GetRefStrict(map<K,V>& m, const K& k)  {
    if (m.count(k) == 0){
        throw runtime_error("no");
    }else{
        return m[k];
    }
}
