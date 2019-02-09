#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cassert>

using namespace std;
using Synonyms = map<string, set<string>>;

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

void TestAddSynonyms(){

    {
        Synonyms synonyms;
        AddSynonyms(synonyms, "a","b");
        const Synonyms expected = {
            {"a",{"b"}},
            {"b",{"a"}}
            };
        assert(synonyms == expected);

    }

    {
        Synonyms synonyms = {
            {"a", {"b"}},
            {"b",{"a","c"}},
            {"c", {"b"}}
        };
        AddSynonyms(synonyms, "a","c");
        const Synonyms expected ={
            {"a", {"b","c"}},
            {"b",{"a","c"}},
            {"c", {"b","a"}}
        };
        assert(synonyms == expected);
    }
    cout<<"AddSynonymsTest is OK!"<<endl;
}

void TestCount(){
    {
        Synonyms synonyms;
        assert(GetSynonymsCount(synonyms, "a") == 0);
    }
    {
         Synonyms synonyms ={
            {"a", {"b","c"}},
            {"b",{"a","c"}},
            {"c", {"b","a"}}
        };
        assert(GetSynonymsCount(synonyms, "a") == 2);
        assert(GetSynonymsCount(synonyms, "b") == 2);
        assert(GetSynonymsCount(synonyms, "d") == 0);
    }

    cout<<"GetSynonymsCountTest is OK!"<<endl; 
}

void TestSynonymsCheck(){
    {
        Synonyms synonyms;
        assert(!SynonymsCheck(synonyms, "a","b"));
        assert(!SynonymsCheck(synonyms, "b","a"));
    }

    cout<<"SynonymsCheckTest is OK!"<<endl;
}


void TestAll(){
    TestCount();
    TestSynonymsCheck();
    TestAddSynonyms();

}


int main(){
    TestAll();

    return 0;
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