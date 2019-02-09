#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

void AddSynonyms(map<string, set<string>>& synonyms, const string& fw, const string& sw){
            synonyms[sw].insert(fw);
            synonyms[fw].insert(sw);

}

size_t GetSynonymsCount(map<string, set<string>>& synonyms, const string& fw){
    return synonyms[fw].size();
}

bool SynonymsCheck(map<string, set<string>>& synonyms, const string& fw, const string& sw){
     if(synonyms[fw].count(sw) == 1){
                return true;
            }else{
                return false;
            }

}

int main(){
    int q;
    cin >> q;

    map<string, set<string>> synonyms;
    for (int i =0; i < q; ++i){
        string operation_code;
        cin >> operation_code;

        if(operation_code == "ADD"){
            string first_word, second_word;
            cin >>first_word >> second_word;
            AddSynonyms(synonyms, first_word, second_word);
 


        }else if (operation_code =="COUNT"){
            string word;
            cin >> word;
            cout << GetSynonymsCount(synonyms, word)<<endl;
        } else if(operation_code == "CHECK"){
            string first_word, second_word;
            cin >>first_word >> second_word;
            if(SynonymsCheck(synonyms, first_word, second_word)){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
           
        }
    }



    return 0;
}