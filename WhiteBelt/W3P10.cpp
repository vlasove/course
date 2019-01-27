#include <iostream>
#include <string>

using namespace std;

class Route{
    public:
        Route() {}
        Route(const string& new_source, const string& new_destination){
            source = new_source;
            destination = new_destination;
            UpdateLength();
        }

    private:
    void UpdateLength(){
        length = source.length() - destination.length();
    }
    string source, destination;
    int length;


};

int main(int argc, char const *argv[])
{
    
    return 0;
}
