#include <iostream>
#include <string>
#include <algorithm>



using namespace std;


class ReversibleString{
    public:
        ReversibleString(){}
        ReversibleString(const string& s){
            str = s;
        }

        string ToString() const {
            return str;
        }
        void Reverse(){
            reverse(str.begin(), str.end());
        }


    private:
        string str;
};