#include <iostream>
#include <cmath>

using namespace std;

bool If_Prime(int Number);

int main()
{
    int Num;

    cout << "Enter the Limit : ";
    cin >> Num;
    cout << "\n";


    if (Num < 2) {

        cout << "Enter a Vaild Positive Integer !!";

    }

    else {

        cout << "The List of Prime Numbers till " << Num << " are : " << "\n\n";

        if (Num == 2) {

            cout << "2" << "\n";

        }

        else {

            cout << "2" << "\n";

            for (int x = 3; x < Num + 1; x += 2) {

                if (If_Prime(x)) {

                    cout << x << "\n";

                }

            }

        }
    }

    return 0;

}


bool If_Prime(int Number) {

    bool Found = true;

    if (Number % 2 != 0) {

        int Var = sqrt(Number) + 1;

        for (long long int y = 3; y < Var; y += 2) {

            if (Number % y == 0) {

                return false;

            }

        }

    }

    else {

        return false;

    }

    return true;

}