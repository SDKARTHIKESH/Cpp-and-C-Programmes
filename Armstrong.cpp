#include <iostream>
#include <cmath>

using namespace std;

int Length(int Number);

int main() {

	int Number, Sum = 0, Var;

	cout << "Enter the Number to Check whether it's Armstrong : ";
	cin >> Number;
	cout << "\n";

	Var = Number;

	int Len = Length(Var);

	while (Var!=0) {

		Sum += pow(Var % 10, Len);
		Var /= 10;

	}

	if (Number == Sum) {

		cout << Number << " is a Armstrong Number";

	}

	else {

		cout << Number << " is not a Armstrong Number";

	}

	cout << "\n";

	return 0;

}


int Length(int Number) {

	int Counter = 0;

	while (Number != 0) {

		Number /= 10;
		Counter++;

	}

	return Counter;

}