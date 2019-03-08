#include <iostream>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <exception>

using namespace std;

using Synonyms = map<string, set<string>>;

// operator << reloading for map and set
template<class Key, class Value>
ostream& operator <<(ostream& os, const map<Key, Value>& m){
    os <<"{";
    bool first = true;
    for (const auto& item : m){
        if (!first){
            os << ", ";
        }
        first = false;
        os << item.first<<": "<<item.second;
    }
    return os<<'}';  
}

template<class T>
ostream& operator <<(ostream& os, const set<T>& s){
    os <<"{";
    bool first = true;
    for (const auto& item : s){
        if (!first){
            os << ", ";
        }
        first = false;
        os << s;
    }
    return os<<'}';  
}


//Synonyms functions block:
void AddSynonyms (Synonyms& synonyms, const string& word1, const string& word2){
    synonyms[word1].insert(word2);
    synonyms[word2].insert(word1);
}

size_t GetSynonymsCount(Synonyms& synonyms, const string& word1){
    return synonyms[word1].size();
}

bool AreSynonyms(Synonyms& synonyms, const string& word1, const string& word2){
    if( synonyms[word1].count(word2) > 0){
                return true;
    }
    return false;

}

//Template For testing framework:
template <class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint){
    if (t != u){
        ostringstream ss;
        ss<<"Assertion failed: "<< t << " != "<<u<<". Hint: "<<hint;
        throw runtime_error(ss.str());

    }
}

void Assert(bool b, const string& hint){
    AssertEqual(b, true, hint);
}

//Testing functions:
void TestAddSynonyms(){
    {
        Synonyms empty;
        AddSynonyms(empty, "a","b");
        const Synonyms expected = {
            {"a", {"b"}},
            {"b", {"a"}}

        };
        AssertEqual(empty , expected, "First empty test for TestAddSynonyms");
    }
    {
        Synonyms synonyms = {
            {"a", {"b"}},
            {"b", {"a","c"}},
            {"c", {"b"}}

        };

        AddSynonyms(synonyms, "a","c");
        const Synonyms expected = {
            {"a", {"b","c"}},
            {"b", {"a","c"}},
            {"c", {"b","a"}}

        };
        AssertEqual(synonyms, expected, "First NON-empty test for TestAddSynonyms");
    }
}

void TestGetSynonymsCount(){
    {
        Synonyms empty;
        AssertEqual(GetSynonymsCount(empty, "a"),0u,"Empty test TestGetSynonymsCount");
    }
    {
        Synonyms synonyms = {
            {"a", {"b"}},
            {"b", {"a","c"}},
            {"c", {"b"}}

        };
        AssertEqual(GetSynonymsCount(synonyms,"b")  ,2u, "First non- empty test TestGetSynonymsCount");
        AssertEqual(GetSynonymsCount(synonyms,"a")  ,1u,"Second non- empty test TestGetSynonymsCount");
        AssertEqual(GetSynonymsCount(synonyms,"z")  ,0u,"Third non- empty test TestGetSynonymsCount");
    }
}

void TestAreSynonyms(){
    {
        Synonyms empty;
        Assert(!AreSynonyms(empty, "a","b"), "First empty test for TestAreSynonyms");
        Assert(!AreSynonyms(empty, "b","a"), "Second empty test for TestAreSynonyms");

    }
    {
        Synonyms synonyms = {
            {"a", {"b"}},
            {"b", {"a","c"}},
            {"c", {"b"}}

        };
        Assert(AreSynonyms(synonyms, "a","b"), "First NON-empty test for TestAreSynonyms");
        Assert(AreSynonyms(synonyms, "b","c"), "Second NON-empty test for TestAreSynonyms");
        Assert(!AreSynonyms(synonyms, "c","a"), "Third NON-empty test for TestAreSynonyms");

    }
}


//Template for exceptions:
class TestRunner{
    public:
    template<class TestFunc>
    void RunTest(TestFunc func, const string& testName){
        try{
            func();
            cerr<<testName<<" OK!"<<endl;
        } catch(runtime_error& e){
            fail_count++;
            cerr <<testName<<" failed: "<<e.what()<<endl;
        }
    }
    ~TestRunner(){
        if(fail_count >0){
            cerr<<fail_count<<" tests failed. Terminate"<<endl;
            exit(1);
        }
    }
    private:
    int fail_count = 0;
    
};

//All test started here:

void TestAll(){
    TestRunner tr;
    tr.RunTest(TestAddSynonyms,"TestAddSynonyms");
    tr.RunTest(TestGetSynonymsCount,"TestGetSynonymsCount");
    tr.RunTest(TestAreSynonyms,"TestAreSynonyms");

}




int main(){

    TestAll();

    int q;
    cin >> q;

    Synonyms synonyms;

    for (int i=0; i < q; i++){
        string command;
        cin >> command;
        if (command == "ADD"){
            string word1, word2;
            cin >> word1>>word2;
            AddSynonyms(synonyms, word1, word2);

        } else if (command == "COUNT"){
            string word;
            cin >> word;
            cout << GetSynonymsCount(synonyms,word)<<endl;
        } else{
            string word1, word2;
            cin >> word1 >> word2;
            if( AreSynonyms(synonyms, word1, word2)){
                cout << "YES"<<endl;
            }else{
                cout << "NO"<<endl;
            }
        }
    }

    return 0;
}