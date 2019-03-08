#pragma once

#include <map>
#include <set>
#include <string>

using namespace std;

using Synonyms = map<string, set<string>>;

//Synonyms functions block:
void AddSynonyms(Synonyms &synonyms, const string &word1, const string &word2)
{
    synonyms[word1].insert(word2);
    synonyms[word2].insert(word1);
}

size_t GetSynonymsCount(Synonyms &synonyms, const string &word1)
{
    return synonyms[word1].size();
}

bool AreSynonyms(Synonyms &synonyms, const string &word1, const string &word2)
{
    if (synonyms[word1].count(word2) > 0)
    {
        return true;
    }
    return false;
}
