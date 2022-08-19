//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
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

    void add(Fraction const &f2){
        int lcm = denominator * f2.denominator;
        int x = lcm/this->denominator;
        int y = lcm/f2.denominator;

        int num = x*numerator + (y*f2.numerator);

        numerator = num;
        denominator = lcm;
        
        simplify();
    }

    void multiply(Fraction const &f2){
        numerator *= f2.numerator;
        denominator *= f2.denominator;
        simplify();
    }


    // Operator Overload
    // they are not changing in current object instead in new object that's why can be marked as constant

    // Addition
    const Fraction operator+ (Fraction const &f2){
        int lcm = denominator * f2.denominator;
        int x = lcm/this->denominator;
        int y = lcm/f2.denominator;

        int num = x*numerator + (y*f2.numerator);

        // numerator = num;
        // denominator = lcm;
            
        Fraction fNew(num,lcm);

        fNew.simplify();
        return fNew;
    }

    // Multiplication
    const Fraction operator* (Fraction const &f2){
        int n = numerator * f2.numerator;
        int d = denominator * f2.denominator;

        Fraction fNew(n,d);
        fNew.simplify();
        return fNew;
    }

    // Equal Comparison operator
    const bool operator== (Fraction const &f2){
        return(numerator==f2.numerator && denominator == f2.denominator);
    }

    // Pre-increment
    // we wouldn't be able to assign value with void
    // void operator++ (){
    //     numerator+=denominator;
    //     simplify();
    // }

    // to avoid copying and doing changes in same object while nesting
    
    Fraction& operator++ (){
        numerator+=denominator;
        simplify();
        return *this;
        // this return address
        // *this will return content
    }

    
//    Post increment
    Fraction operator++(int){
        Fraction fNew(numerator,denominator);
        numerator+=denominator;
        simplify();
        fNew.simplify();
        return fNew;
    }
//    Nesting is not allowed on post increment operator
    
    
//    += operator
//    & to avoid creating a copy of object
    Fraction& operator+=(Fraction const &f2){
        int lcm = denominator * f2.denominator;
        int x = lcm/this->denominator;
        int y = lcm/f2.denominator;

        int num = x*numerator + (y*f2.numerator);

        numerator = num;
        denominator = lcm;
        
        simplify();
        
//        for nesting purpose
        return* this;
    }
};


int main(){
    Fraction f1(10,2);
    Fraction f2(15,4);

    Fraction f3 = f1+f2;
    Fraction f4 = f1*f2;

    f1.print();
    // pre-increment
    // Fraction f5 = ++f1;
    // f1.print();
    // f5.print();
    // f2.print();
    // f3.print();
    // f4.print();

    // cout<<(f1==f1)<<endl;

    Fraction f6 = ++(++f1);
    f1.print();
    f6.print();
    
    Fraction f7 = f1++;
    f7.print();
    f1.print();
    
    (f1+=f2)+=f2;
    f1.print();

}
