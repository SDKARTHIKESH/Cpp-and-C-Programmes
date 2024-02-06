#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {

	vector<int> Numbers;
	int Length;

	cout << "Enter the Number of Elements in the Sorted Array : ";
	cin >> Length;

	cout << "Enter the Elements of the Sorted Array : ";

	for (int x = 0; x < Length; x++) {

		int Num;
		cin >> Num;

		Numbers.push_back(Num);

	}

	cout << "\n";
	
	vector<int> New_Numbers;
	int New_Num;

	cout << "Enter the Number to Insert in the Array : ";
	cin >> New_Num;

	cout << "\n";

	bool Done = false;

	for (int x : Numbers) {

		if (New_Num < x) {

			New_Numbers.push_back(New_Num);
			New_Numbers.push_back(x);

			Done = true;

			continue;

		}

		New_Numbers.push_back(x);

	}

	if (not Done) {

		New_Numbers.push_back(New_Num);

	}

	cout << "The Updated Array is : " << "\n\n";

	for (int x : New_Numbers) {

		cout << x << "\n";

	}

	return 0;

}