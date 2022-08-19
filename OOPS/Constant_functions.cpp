// const object can only access const functions to avoid any changes
#include <bits/stdc++.h>

using namespace std;

class Fraction{
private:
	int numerator;
	int denominator;

public:
	Fraction(int numerator, int denominator){
		this->numerator = numerator;
		this->denominator = denominator;
	}

	const int getNumerator(){
		return numerator;
	}
	const int getDenominator(){
		return denominator;
	}

	void setNumerator(int n){
		numerator = n;
	}

	void setDenominator(int d){
		denominator = d;
	}

	void const print(){
		cout<<numerator<<" / "<<denominator<<endl;
	}

	void simplify(){
		int gcd = 1;
		int j = min(this->numerator,this->denominator);
		for(int i=1;i<=j;i++){
			if(this->numerator%i==0 && this->denominator%i==0)
				gcd = i;
		}
		this->numerator/=gcd;
		this->denominator/=gcd;
	}

	void add(Fraction &f2){
		int lcm = denominator * f2.denominator;
		int x = lcm/this->denominator;
		int y = lcm/f2.denominator;

		int num = x*numerator + (y*f2.numerator);

		numerator = num;
		denominator = lcm;
		
		simplify();
	}

	void multiply(Fraction f2){
		numerator *= f2.numerator;
		denominator *= f2.denominator;
		simplify();
	}
};


int main(){
	Fraction f1(10,2);
	Fraction f2(15,4);

	Fraction const f3(14,3);

	f1.add(f2);

	f1.print();
	f2.print();
}