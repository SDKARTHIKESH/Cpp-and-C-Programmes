#include <iostream>
#include <vector>
#include <map>

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

	map<int, int> Frequency;

	for (int x : Numbers) {

		if (Frequency.find(x) != Frequency.end()) {

			Frequency[x]++;
			continue;

		}

		Frequency[x] = 1;

	}

	cout << "The Duplicate Elements in the Array are : " << "\n\n";

	for (auto x = Frequency.begin(); x != Frequency.end(); x++) {

		if (x->second > 1) {

			cout << x->first << "\n";

		}

	}

	return 0;

}