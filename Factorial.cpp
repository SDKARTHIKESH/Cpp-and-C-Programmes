#include <iostream>

using namespace std;

unsigned long long int Factorial(unsigned long long int Num);

int main() {

	unsigned long long int Num;

	cout << "We are going to Calculate the Factorial of the user-entered Number!!!\n\n";

	cout << "Enter the Number to Calculate the Factorial : ";
	cin >> Num;
	cout << "\n";

	cout << "The Factorial of " << Num << " is : " << Factorial(Num);

	return 0;

}

unsigned long long int Factorial(unsigned long long int Num) {

	if (Num > 1) {

		return Num * Factorial(Num - 1);

	}

}