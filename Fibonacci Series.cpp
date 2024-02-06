#include <iostream>

using namespace std;

int main() {

	int Num1 = 1, Num2 = 1, Number, Temp;

	cout << "Enter the Number of Terms : ";
	cin >> Number;

	cout << "\n\n";

	if (Number < 1) {

		cout << "Please Enter a Valid Number of Terms !!!";

	}

	else {

		cout << "The Fibonacci Series till " << Number << " terms is : " << "\n\n";

		for (int i = 0; i < Number; i++) {

			cout << Num1 << "\n";

			Temp = Num1;
			Num1 = Num2;
			Num2 += Temp;

		}

	}

	return 0;
}