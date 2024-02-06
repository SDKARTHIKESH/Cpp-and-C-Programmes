#include <iostream>

using namespace std;

int main() {

    int Number;

    cout << "Enter the Number to Check whether the Number is Even or Odd : ";
    cin >> Number;
    cout << "\n";

    if (Number < 0) {

        cout << "Please Enter a Positive Number !!";

    }

    else {

        if (Number % 2) {

            cout << Number << " is a Odd Number";

        }

        else {

            cout << Number << " is a Even Number";

        }

    }

    cout << "\n";

    return 0;

}