#include <iostream>

using namespace std;

int Digits(int Number);

int main() {

	int Number;

	cout << "Enter the Number to Count the Number of Digits : ";
	cin >> Number;
	cout << "\n";

	cout << "The Number of Digits in " << Number << " is : " << Digits(Number);

	cout << "\n";

	return 0;

}

int Digits(int Number) {

	int Counter = 0;

	while (Number != 0) {

		Number /= 10;
		Counter++;

	
	}

	return Counter;

}