#include <iostream>

using namespace std;

int main() {
	int Num1, Num2, Sum, Difference, Product;
	double Quotient;

	Num1 = Num2 = Sum = Difference = Product = 0;
	Quotient = 0.0;

	cout << "Enter the First Number : ";
	cin >> Num1;
	cout << "\n";

	cout << "Enter the Second Number : ";
	cin >> Num2;
	cout << "\n";

	Sum = Num1 + Num2;
	Difference = Num1 - Num2;
	Product = Num1 * Num2;
	Quotient = static_cast<double>(Num1) / static_cast<double>(Num2);

	cout << Num1 << " + " << Num2 << " = " << Sum << "\n";
	cout << Num1 << " - " << Num2 << " = " << Difference << "\n";
	cout << Num1 << " * " << Num2 << " = " << Product << "\n";
	cout << Num1 << " / " << Num2 << " = " << Quotient << "\n";

	return 0;
}