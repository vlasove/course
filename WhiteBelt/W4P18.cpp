#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <exception>
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
        if(denominator == 0 ){
            throw invalid_argument("Invalid argument");
        }

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
    if( lhs.Denominator() == 0 || rhs.Numerator() == 0){
           
            throw domain_error("Division by zero");

    }

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
    string a,b;
    char operand;


    try{
        cin >> a >> operand >> b;
        stringstream ss1(a);
        Rational rat1;
        ss1>>rat1;

        stringstream ss2(b);
        Rational rat2;
        ss2>>rat2;

        if( operand == '+'){
            cout<<rat1 + rat2<<endl;
        }else if( operand == '-'){
            cout<<rat1 - rat2<<endl;
        }else if(operand == '*'){
            cout<<rat1*rat2<<endl;
        }else{
            try{
                cout<<rat1/rat2<<endl;

            }catch(domain_error& de){
                cout<<de.what()<<endl;
            }
        }

    } catch (invalid_argument& ia){
        cout<<ia.what()<<endl;
    }
    //cout<< rat1<<" and"<<operand<<"and "<<rat2<<endl;
    return 0;
}
