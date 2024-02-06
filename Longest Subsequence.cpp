#include <iostream>

using namespace std;

int main()
{
    int Length = 1, Max_Length = 0, Num, Prev = 0;

    cout << "Enter the Subsequence : ";
    cin >> Num;
    cout << "\n";

    while (Prev != -1) {

        cin >> Num;

        if (Num > Prev and Num != -1) {

            Length++;

        }

        else {

            if (Length > Max_Length) {

                Max_Length = Length;

            }

            Length = 1;

        }

        Prev = Num;

    }

    cout << "The Maximum Length of Increasing Subsequence is : " << Max_Length;
    cout << "\n";

    return 0;
}