#include <iostream>

using namespace std;

int main() {

	unsigned long long int Num1, Num2, Num3, Number, Temp1, Temp2;

	cout << "We are going to print the Tribonacci Series !!" << "\n\n";

	cout << "Enter the Number of Terms : ";
	cin >> Number;
	cout << "\n\n";

	if (Number < 1) {

		cout << "Please Enter a Valid Number of Terms !!!";

	}

	else {

		cout << "Enter the First Number : ";
		cin >> Num1;
		cout << "\n";

		cout << "Enter the Second Number : ";
		cin >> Num2;
		cout << "\n";

		cout << "Enter the Third Number : ";
		cin >> Num3;
		cout << "\n\n";

		for (int i = 0; i < Number; i++) {

			cout << Num1 << "\n";

			Temp1 = Num1;
			Temp2 = Num2;
			Num1 = Num2;
			Num2 = Num3;
			Num3 += Temp1 + Temp2;

		}

	}

	return 0;
}