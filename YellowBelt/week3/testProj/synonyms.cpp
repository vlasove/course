#include <iostream>
#include <exception>
#include "body.h"
#include "tests.h"

using namespace std;

int main()
{

    TestAll();

    int q;
    cin >> q;

    Synonyms synonyms;

    for (int i = 0; i < q; i++)
    {
        string command;
        cin >> command;
        if (command == "ADD")
        {
            string word1, word2;
            cin >> word1 >> word2;
            AddSynonyms(synonyms, word1, word2);
        }
        else if (command == "COUNT")
        {
            string word;
            cin >> word;
            cout << GetSynonymsCount(synonyms, word) << endl;
        }
        else
        {
            string word1, word2;
            cin >> word1 >> word2;
            if (AreSynonyms(synonyms, word1, word2))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}