#include <iostream>

using namespace std;

int main(){

    int Num1, Num2, Max, Var;

    cout << "Enter the First Number : ";
    cin >> Num1;
    
    cout << "Enter the Second Number : ";
    cin >> Num2;

    cout << "\n";

    Max = (Num1 > Num2) ? Num1 : Num2;
    Var = Max;

    while (1) {

        if (Max % Num1 == 0 and Max % Num2 == 0) {

            cout << "The LCM of " << Num1 << " and " << Num2 << " is : " << Max;
            break;

        }

        Max += Var;

    }

    cout << "\n";

    return 0;
}