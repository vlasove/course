#include <iostream>


using namespace std;

int NumOfTry(const int& a, const int& b){
    int temp;
    int dif = b - a;
    if(dif == 0){
        temp = 0;
    } else {
        if(dif%4 != 0)
    }

    return temp;

}

int main(int argc, char const *argv[])
{
    int a,b;
    cin >> a >>b;

    cout<<NumOfTry(a,b)<<endl;
    return 0;
}
