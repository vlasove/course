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

int main(int argc, char const *argv[])
{

    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;
    
    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;
    
    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;
    
    return 0;
}
