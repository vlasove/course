
bool operator==(const Region& lhs, const Region& rhs){
    if(lhs.std_name == rhs.std_name && lhs.parent_std_name == rhs.parent_std_name && lhs.population == rhs.population && lhs.names == rhs.names){
        //TODO add map equality
        return true;
    }
    return false;
}


int maxAt(vector<int>& vector_name) {
    int max = INT_MIN;
    for (auto val : vector_name) {
         if (max < val) max = val;
    }
    return max;
}

int FindMaxRepetitionCount(const vector<Region>& regions){
    vector<int> repeats;

    for(int i =0; i < regions.size(); i++){
        int temp = 0;
        for(int j = 0; j < regions.size(); j++){
            if(regions[i] == regions[j]){
                ++temp;

            }
        }
        repeats.push_back(temp);
    }
    int m = maxAt(repeats);
    if(m == 0){
        return 1;
    }else{
        return m;
    }
    
}