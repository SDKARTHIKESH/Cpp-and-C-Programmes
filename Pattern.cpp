#include <iostream>

using namespace std;

int main() {

	int Number;

	cout << "Enter the Number of Lines : ";
	cin >> Number;
	cout << "\n";

	cout << "The Pattern is : " << "\n\n";

	for (int x = 0; x < Number + 1; x++) {

		for (int y = 0; y < x; y++) {

			cout << "* ";

		}

		cout << "\n";

	}

	return 0;

}