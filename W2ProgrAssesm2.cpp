#include <iostream>
#include <string>
using namespace std;

bool IsPalindrom(string word){
    
    bool tester = true;
    for (int i = 0; i < (word.size() / 2); i++)
    {
        if (word[i] != word[(word.size() - 1) - i]) {
            tester  = false;
        }
    }

    return tester;

}
    

int main(int argc, char const *argv[])
{
    cout<<IsPalindrom("abas");
    return 0;
}
