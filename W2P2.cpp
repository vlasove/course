#include <iostream>
#include <cassert>

using namespace std;

template<typename T>
T Sum(T a, T b){
     return a + b;
}

void TestSum(){
    assert(Sum(2,3) == 5);
    assert(Sum(-2,-3) == -5);
    assert(Sum(5,0) == 5);
    assert(Sum(1.1, 2.5) == 3.6);

}

int main(){
    TestSum();


    return 0;
}