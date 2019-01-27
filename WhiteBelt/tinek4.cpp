#include <iostream>

using namespace std;

 
struct point {
    double x, y;
};
 

bool PtInPolygon(const point& p, const point* d, int n){
    double r;
    --n;
    for(int i = 0; i < n; ++i) {
        r = (p.x - d[i].x)*(d[i].y - d[i + 1].y) - 
            (p.y - d[i].y)*(d[i].x - d[i + 1].x);
        if(r < 0)
            return false;
    }
    r = (p.x - d[n].x)*(d[n].y - d[0].y) - 
        (p.y - d[n].y)*(d[n].x - d[0].x);
    return (r >= 0);
}
 
int main(void){
    int n;
    cin>>n;
    point d[n];
    for (int i = 0; i < n; i++){
        double a,b;
        cin>>a>>b;
        d[i] = {a,b};

    }

    double a1,b1;
    cin>>a1>>b1;
    point p = { a1, b1 };
 
    if(PtInPolygon(p, d, n))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}