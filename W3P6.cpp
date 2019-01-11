#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Route{
    public:

        string GetSource() {return source;}
        string GetDestination() {return destination;}
        int GetLength() {return length;}


        void SetSource(const string& new_source){
            source = new_source;
            UpdateLength();
        }

        void SetDestination(const string& new_destination){
            destination = new_destination;
            UpdateLength();
        }

    private:

        void UpdateLength(){
            length = destination.length() - source.length();
        }

    string source;
    string destination;
    int length;
};



int main(int argc, char const *argv[])
{
    
    return 0;
}
