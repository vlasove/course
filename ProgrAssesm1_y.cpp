#include <iostream>
#include <vector>


using namespace std;

int main(){
    int64_t n;
    int64_t c = 0;
    vector<int64_t> v;
    int64_t sum=0;
    cin >> n;
    for(int64_t i = 0; i < n; i++){
        int64_t temp;
        cin >> temp;
        sum += temp;
        v.push_back(temp);
    }

    int64_t avg = sum / static_cast<int64_t>(v.size());
    vector<int64_t> ans;

    for(int64_t j = 0; j < n; j++){
        if(v[j] > avg){
            c++;
            ans.push_back(j);
        }
    }
    cout<<c<<endl;
    for(int64_t p = 0; p < static_cast<int64_t>(ans.size()); p++){
        cout<<ans[p]<<" ";

    }
    cout<<endl;

    


  


    return 0;
}