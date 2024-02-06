#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int Num;

    cout << "Enter the Number to check whether it's Prime or not : ";
    cin >> Num;
    cout << "\n";

    if (Num < 1) {

        cout << "Enter a Vaild Positive Integer !!";

    }

    else if (Num==1){

        cout << "1 is Neither Prime nor Composite";

    }

    else if (Num == 2) {

        cout << "2 is a Prime Number";

    }

    else {

        bool Found = true;

        if (Num % 2 != 0) {

            int Var = sqrt(Num) + 1;

            for (long long int y = 3; y < Var; y += 2) {

                if (Num % y == 0) {

                    Found = false;
                    break;

                }

            }

        }

        else {

            Found = false;

        }

        if (Found) {

            cout << Num << " is a Prime Number";

        }

        else {

            cout << Num << " is not a Prime Number";

        }

    }

    cout << "\n";

    return 0;

}