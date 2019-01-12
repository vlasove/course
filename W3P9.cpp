#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ComputeDistance(const string& source,const string& destination){
    return source.length() - destination.length();
}

class Route{
    public: 
        string GetSource() const{
            return source;
        }

        string GetDestination() const {
            return destination;
        }

        int GetLength() const {
            return length;
        }

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
            length = ComputeDistance(source, destination);
        }
        string source, destination;
        int length;

};

void PrintRoute(const Route& route){
    cout<<route.GetSource()<<" - "<< route.GetDestination()<<endl;
}

int main(int argc, char const *argv[])
{   
    Route route;
    route.SetDestination("Moscow");
    route.SetSource("Saint-Petersburger");
    PrintRoute(route);
    
    return 0;
}
