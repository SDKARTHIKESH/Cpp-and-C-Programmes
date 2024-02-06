#include <iostream>

using namespace std;

int main() {

	int Num1, Num2;
	char Operator;

	cout << "Enter the First Number : ";
	cin >> Num1;

	cout << "Enter the Second Number : ";
	cin >> Num2;

	cout << "\n";

	cout << "Enter the Operator (+, -, *, /, %) : ";
	cin >> Operator;

	cout << "\n";

	switch (Operator) {

	case '+':

		cout << "The Sum of " << Num1 << " and " << Num2 << " is : " << Num1 + Num2;
		break;

	case '-':

		cout << "The Difference of " << Num1 << " and " << Num2 << " is : " << Num1 - Num2;
		break;

	case '*':

		cout << "The Product of " << Num1 << " and " << Num2 << " is : " << Num1 * Num2;
		break;

	case '/':

		cout << "The Quotient when " << Num1 << " is divided by " << Num2 << " is : " << Num1 / Num2;
		break;

	case '%':

		cout << "The Remainder when " << Num1 << " is divided by " << Num2 << " is : " << Num1 % Num2;
		break;

	default : 

		cout << "Please Enter a Valid Operator !!";

	}

	cout << "\n";

	return 0;

}