#include <iostream>
using namespace std;

class ComplexNumbers {
private:
    int real;
    int imaginary;
public:
    ComplexNumbers(int real,int imaginary){
        this->real = real;
        this->imaginary = imaginary;
    }

    void plus(ComplexNumbers c){
        this->real += c.real;
        this->imaginary += c.imaginary;
    }
    void multiply(ComplexNumbers c2){
        int tr = this->real;
            int ti = this->imaginary;
            
        this->real = tr*c2.real-ti*c2.imaginary;
        this->imaginary = tr*c2.imaginary+ti*c2.real;
    }

    void print(){
        cout<<real<<" + i"<<imaginary<<endl;
    }
};

int main() {
    int real1, imaginary1, real2, imaginary2;
    
    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;
    
    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);
    
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }   
}