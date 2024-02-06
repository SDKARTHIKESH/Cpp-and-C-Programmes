#include <iostream>

using namespace std;

int main() {

	int Number;

	cout << "Enter the Number to check whether it's Positive or Negative : ";
	cin >> Number;

	cout << "\n";

	if (Number > 0) {

		cout << Number << " is a Positive Number";

	}

	else if (Number < 0) {

		cout << Number << " is a Negative Number";

	}

	else {

		cout << Number << " is neither Positive nor Negative Number";

	}

	cout << "\n";

	return 0;

}