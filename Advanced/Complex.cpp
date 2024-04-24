#include <iostream>

using namespace std;

class Complex{

    int Real, Imaginary;

    public:

    Complex();
    Complex(Complex &C);

    void operator+(Complex &C);
    Complex operator-(Complex &C);

    void readData();
    void printData();

};

int main(){

    Complex C1, C2, C3;

    C1.readData();
    C2.readData();

    C1.printData();
    C2.printData();

    C1+C2;
    cout << "Sum : ";
    C1.printData();

    C3 = C1 - C2;
    cout << "Difference : ";
    C3.printData();

    return 0;

}

Complex::Complex(){

    this->Real = 0;
    this->Imaginary = 0;

    return;

}

Complex::Complex(Complex &C){

    this->Real = C.Real;
    this->Imaginary = C.Imaginary;

    return;

}

void Complex::operator+(Complex &C){

    this->Real += C.Real;
    this->Imaginary += C.Imaginary;

    return;

}

Complex Complex::operator-(Complex &C){

    Complex Temp;

    Temp.Real = this->Real - C.Real;
    Temp.Imaginary = this->Imaginary - C.Imaginary;

    return Temp;

}

void Complex::readData(){

    cin >> this->Real >> this->Imaginary;

    return;

}

void Complex::printData(){

    cout << this->Real << "+" << this->Imaginary << "i" << "\n";

    return;

}