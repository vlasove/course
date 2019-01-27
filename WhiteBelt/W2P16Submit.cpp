set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> unique;
    for(auto item : m){
        unique.insert(item.second);
    }

    return unique;


}