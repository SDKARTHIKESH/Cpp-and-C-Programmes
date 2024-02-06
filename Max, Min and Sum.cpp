#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> Numbers;
	int Length;

	cout << "Enter the Number of Elements in the Array : ";
	cin >> Length;

	cout << "Enter the Elements of the Array : ";

	for (int x = 0; x < Length; x++) {

		int Num;
		cin >> Num;

		Numbers.push_back(Num);

	}

	cout << "\n";

	int Max = Numbers[0], Min = Numbers[0], Sum = 0;

	for (int x : Numbers) {

		if (x < Min) {

			Min = x;

		}

		else if (x > Max) {

			Max = x;

		}

		Sum += x;

	}

	cout << "The Maximum Element of the Array is : " << Max << "\n";
	cout << "The Minimum Element of the Array is : " << Min << "\n";
	cout << "The Sum of all the Elements of the Array is : " << Sum << "\n";

	return 0;

}