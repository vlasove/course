#include <iostream>
#include <map>
#include <vector>
#include <map>

using namespace std;

struct Point{
    int i;
    int j;
};

int FindLast(const map<int,Point>& m){
    int temp;




    return temp;
}

int main(int argc, char const *argv[])
{
    
    int n, doubles;
    map<int, Point> m;
    cin>>n;
    cin >> doubles;
    for(int i =0; i < doubles; i++){
        int a,b;
        cin >>a>>b;
        Point p = {a,b};
        m[i] = p;

    }

    cout<<FindLast(m)<<endl;
    return 0;
}
