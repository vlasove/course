bool operator==(const Region& lhs, const Region& rhs){
    if(lhs.std_name == rhs.std_name && lhs.parent_std_name == rhs.parent_std_name && lhs.population == rhs.population && lhs.names == rhs.names){
        //TODO add map equality
        return true;
    }
    return false;
}


int maxAt(vector<int64_t>& vector_name) {
    int64_t max = -10000;
    for (auto val : vector_name) {
         if (max < val) max = val;
    }
    return max;
}

int FindMaxRepetitionCount(const vector<Region>& regions){
    vector<int64_t> repeats;

    if (regions.size() == 0){
        return 0;
    }

    for(int64_t i =0; i < static_cast<int64_t>(regions.size()); i++){
        int64_t temp = 0;
        for(int64_t j = 0; j < static_cast<int64_t>(regions.size()); j++){
            if(regions[i] == regions[j]){
                ++temp;

            }
        }
        repeats.push_back(temp);
    }
    int64_t m = maxAt(repeats);
    if(m == 0){
        return 1;
    }else{
        return m;
    }
    
}