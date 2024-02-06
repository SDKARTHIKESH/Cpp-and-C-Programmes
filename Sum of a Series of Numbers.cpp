#include <iostream>

using namespace std;

int main() {

	int Number;
	int Sum = 0;

	cout << "Enter the Series of Numbers : ";
	cin >> Number;

	while (Number != -1) {

		Sum += Number;

		cin >> Number;

	}

	cout << "\n";
	cout << "The Sum of the Entered Sequence is : " << Sum;
	cout << "\n";

	return 0;

}