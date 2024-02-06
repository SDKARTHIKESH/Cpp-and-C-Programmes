#include <iostream>

using namespace std;

int gcd(int Num1, int Num2);

int main() {

    int Number1, Number2;

    cout << "Enter the First Number : ";
    cin >> Number1; 
    
    cout << "Enter the Second Number : ";
    cin >> Number2;

    int Output;

    if (Number1 > Number2) {

        Output = gcd(Number1, Number2);

    }
    else {

        Output = gcd(Number2, Number1);

    }

    cout << "\n";
    cout << "The GCD of " << Number1 << " and " << Number2 << " is : " << Output;
    cout << "\n";

    return 0;

}

int gcd(int Num1, int Num2) {


    if (Num2 == 0) {

        return Num1;

    }

    return gcd(Num2, Num1 % Num2);

}
