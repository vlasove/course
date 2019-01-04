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