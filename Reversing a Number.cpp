#include <iostream>
#include <cmath>

using namespace std;

int main() {

	int Number, Reverse = 0, Counter = 0;

	cout << "Enter a Number to Reverse : ";
	cin >> Number;
	cout << "\n";

	while (Number != 0) {

		Reverse = Reverse * 10 + (Number % 10) ;

		Number /= 10;
		Counter++;

	}

	cout << "The Reversed Number is : " << Reverse;
	cout << "\n";

	return 0;

}