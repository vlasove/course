#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
#include <map>
#include <set>
#include <vector>

using namespace std;


int gcd (int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd (b, a % b);
}

class Rational{
    public: 
    Rational(){
        current_numerator = 0;
        current_denominator = 1;
    };
    Rational(int numerator, int denominator){

        if(numerator == 0){
            current_numerator = 0;
            current_denominator = 1;
        }else if((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)  ){
            current_numerator = -abs(numerator/gcd(numerator, denominator));
            current_denominator = abs(denominator/gcd(numerator, denominator));
        }else if(numerator <0 && denominator < 0){
             current_numerator = abs(numerator/gcd(numerator, denominator));
            current_denominator = abs(denominator/gcd(numerator, denominator));

        }else{
            current_numerator = numerator/gcd(numerator, denominator);
            current_denominator = denominator/gcd(numerator, denominator);

        }
    }


    int Numerator() const{
        return current_numerator;
    }
    int Denominator() const{
        return current_denominator;
    }

    private:
    int current_numerator;
    int current_denominator;

};

Rational operator+(const Rational& lhs, const Rational& rhs){
    if(lhs.Denominator() == rhs.Denominator()){
        return Rational(lhs.Numerator()+rhs.Numerator(), lhs.Denominator());
    }else{
        return Rational(lhs.Numerator()*rhs.Denominator() + rhs.Numerator()*lhs.Denominator(), lhs.Denominator()*rhs.Denominator());
    }
}

Rational operator-(const Rational& lhs, const Rational& rhs){
    if(lhs.Denominator() == rhs.Denominator()){
        return Rational(lhs.Numerator()-rhs.Numerator(), lhs.Denominator());
    }else{
        return Rational(lhs.Numerator()*rhs.Denominator() - rhs.Numerator()*lhs.Denominator(), lhs.Denominator()*rhs.Denominator());
    }
}

Rational operator*(const Rational& lhs, const Rational& rhs){

    return Rational(lhs.Numerator()*rhs.Numerator(), lhs.Denominator()*rhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs){

    return Rational(lhs.Numerator()*rhs.Denominator(), lhs.Denominator()*rhs.Numerator());
}

bool operator==(const Rational& lhs, const Rational& rhs){
    if(lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator()){
        return true;
    }else{
        return false;
    }
}

ostream& operator<<(ostream& stream, const Rational& rational){
    stream<<rational.Numerator()<<'/'<<rational.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational& rational){
    if (stream.tellg() == -1) {
   return stream;
}
    int n,d;
    stream >>n;
    stream.ignore(1);
    stream>>d;
    //if()
    rational ={n,d};
    return stream;
}


bool operator<(const Rational& lhs, const Rational& rhs){
    return lhs.Numerator()*rhs.Denominator() < rhs.Numerator()*lhs.Denominator();
}


int main(int argc, char const *argv[])
{   
     {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }


    cout << "OK" << endl;
    return 0;
}
