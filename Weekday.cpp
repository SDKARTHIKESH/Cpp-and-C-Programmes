#include <iostream>

using namespace std;

int main() {

	int Number;

	cout << "Enter the Number to Find the corresponding Weekday (1-7) : ";
	cin >> Number;
	cout << "\n";

	switch (Number) {

	case 1:

		cout << "The Day is Monday!";
		break;

	case 2:

		cout << "The Day is Tuesday!";
		break;

	case 3:

		cout << "The Day is Wednesday!";
		break;

	case 4:

		cout << "The Day is Thursday!";
		break;

	case 5:

		cout << "The Day is Friday!";
		break;

	case 6:

		cout << "The Day is Saturday!";
		break;

	case 7:

		cout << "The Day is Sunday!";
		break;

	default:

		cout << "Please Enter a Valid Number !!";

	}

	cout << "\n";

	return 0;

	

}