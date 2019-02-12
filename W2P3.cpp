#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <exception>
#include <sstream>

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
template <class Q>
ostream& operator << (ostream& os, const set<Q>& s){
    os<<"{";
    bool first = true;
    for(const auto& elem :s){
        if(!first){
            os<<",";
        }
        first = false;
        os<<elem;
    }
    return os<<" }";

}

template<class K, class V>
ostream& operator<< (ostream& os, const map<K,V>& m){
    os <<"{";
    bool first = true;
    for(const auto& kv :m){
        if(!first){
            os<<", ";
        }
        first = false;
        os<<kv.first <<": "<<kv.second;
    }
    return os<<"}";
}










template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint){
    if(t != u){
        ostringstream os;
        os <<"Asserion failed : "<< t << " != "<<u<<" Hint : "<<hint;;
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint){
    AssertEqual(b,true, hint);
}

void TestAddSynonyms(){

    {
        Synonyms synonyms;
        AddSynonyms(synonyms, "a","b");
        const Synonyms expected = {
            {"a",{"b"}},
            {"b",{"a"}}
            };
        AssertEqual(synonyms , expected, "expected assert");

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
    
}

void TestCount(){
    {
        Synonyms synonyms;
        AssertEqual(GetSynonymsCount(synonyms, "a") , 0u, "empty");
    }
    {
         Synonyms synonyms ={
            {"a", {"b","c"}},
            {"b",{"a","c"}},
            {"c", {"b","a"}}
        };
        AssertEqual(GetSynonymsCount(synonyms, "a"), 2u, "a");
        AssertEqual(GetSynonymsCount(synonyms, "b"), 2u, "b");
        AssertEqual(GetSynonymsCount(synonyms, "d"), 0u, "c");
    }

    
}

void TestSynonymsCheck(){
    {
        Synonyms synonyms;
        Assert(!SynonymsCheck(synonyms, "a","b"), "lol");
        Assert(!SynonymsCheck(synonyms, "b","a"), "kek");
    }

    
}

class TestRunner{
public:
    template<class TestFunc>
    void RunTest(TestFunc func, const string& test_name){
        try{
            func();
            cerr<<test_name<<" OK!"<<endl;
        } catch(runtime_error& r){
            ++fail_count;
            cerr<<test_name<<" Failed: "<<r.what()<<endl;
        }

    }
    ~TestRunner(){
        if(fail_count >0){
            cerr<<fail_count<<" tests failed. Terminate";
            exit(1);
        }
    }
private:
int fail_count = 0;
};



void TestAll(){
    TestRunner tr;
    tr.RunTest(TestCount, "TestCount");
    tr.RunTest(TestSynonymsCheck, "TestSynonymsCheck");
    tr.RunTest(TestAddSynonyms, "TestAddSynonyms");

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