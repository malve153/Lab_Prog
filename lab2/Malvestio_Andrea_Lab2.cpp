//Malvestio Andrea Mat:2032464
#include <iostream>

class Rational{
public: 
    class Invalid{};
	Rational();
	Rational(  int num);
	Rational( int num, int den);
	
	int numer() { return this->numerator; }
	int denom() { return this->denominator; }
	Rational& operator=(Rational b);
	Rational operator+(Rational b);
	Rational operator+(int b);
	Rational operator-(Rational b);
	Rational operator*(Rational b);
	Rational operator/(Rational b);
	bool operator==(Rational b);
	bool operator>(Rational b);
	bool operator<(Rational b);
	double to_double();
	friend std::ostream& operator<<(std::ostream& os,const Rational& b);
	
private: 
	int numerator;
	int denominator;
    bool is_valid();
    int mcd(int n, int d);
};

//-----------------------------------------------------------------------------
//COSTRUTTORI

Rational::Rational()
	: numerator{0}, denominator{1}
	{
	}
	
Rational::Rational(int num)
	: numerator{num}, denominator{1}
	{
	}
	
Rational::Rational(int num, int den)
	: numerator{num}, denominator{den}
	{
        if(!is_valid()) throw Invalid();
	}

//-----------------------------------------------------------------------------	
//function per verificare se i dati sono validi
bool Rational::is_valid(){
    if(this->denominator == 0)  return false;
    else return true;
}

//function per calcolare il mcd fra numeratore e denominatore
int Rational::mcd(int n, int d){
    int x=abs(n);
    int y=abs(d);
    while (y > 0) {
        int r = x % y;
        x = y;
        y = r;
    }
    return x;
}

//-----------------------------------------------------------------------------
//DEFINIZIONE HELPER FUNCTIONS

//overloading operatori	
Rational& Rational::operator=(Rational b){
	this->numerator = b.numer();
	this->denominator = b.denom();
	return *this;
}

Rational Rational::operator+(Rational b){
	int d=this->denominator;
	int n;
	while(d%b.denom()!=0){
		d+=this->denominator;
	}
	n=(d/this->denominator)*this->numerator + (d/b.denom())*b.numer() ;
	if(mcd(n,d)> abs(n) || mcd(n,d)> abs(d))
	    return Rational(n,d);
    else
        return Rational(n/mcd(n,d),d/mcd(n,d));
}

Rational Rational::operator+(int b){
	int n = (this->numerator) + (b * this->denominator);
    int d = this->denominator;
    if(mcd(n,d)> abs(n) || mcd(n,d)> abs(d))
	    return Rational(n,d);
    else
        return Rational(n/mcd(n,d),d/mcd(n,d));
}

Rational Rational::operator-(Rational b){
	int d=this->denominator;
	while(d%b.denom()!=0){
		d+=this->denominator;
	}
	int n=(d/this->denominator)*this->numerator - (d/b.denom())*b.numer() ;
    if(mcd(n,d)> abs(n) || mcd(n,d)> abs(d))
	    return Rational(n,d);
    else
        return Rational(n/mcd(n,d),d/mcd(n,d));
}

Rational Rational::operator*(Rational b){
    int n = this->numerator * b.numer();
    int d = this->denominator * b.denom();
	if(mcd(n,d)> abs(n) || mcd(n,d)> abs(d))
	    return Rational(n,d);
    else
        return Rational(n/mcd(n,d),d/mcd(n,d));
}

Rational Rational::operator/(Rational b){
    int n = this->numerator * b.denom(); 
    int d = this->denominator * b.numer();
    if(mcd(n,d)> abs(n) || mcd(n,d)> abs(d))
	    return Rational(n,d);
    else
        return Rational(n/mcd(n,d),d/mcd(n,d));
}

bool Rational::operator==(Rational b){
	if(this->numerator == b.numer() && this->denominator == b.denom())
		return true;
	else return false;
}

bool Rational::operator>(Rational b){
	if( this->to_double() >= b.to_double())
		return true;
	else return false;
}

bool Rational::operator<(Rational b){
	if( this->to_double() <= b.to_double())
		return true;
	else return false;
}

std::ostream& operator<<(std::ostream& os,const Rational& b){
	os << "numeratore: " << b.numerator<< "\n" << "denominatore: " << b.denominator << "\n";
    return os;
}

//function che ritorna il valore approssimato del numero razionale
double Rational::to_double(){
	return ((double)this->numerator)/((double)this->denominator);
}