#include <iostream>

using namespace std;

int Sum_of_Naturals(int N);

int main() {

	int N;

	cout << "Enter the Value of N : ";
	cin >> N;

	cout << "\n";

	if (N < 1) {

		cout << "Please Enter a Positive Integer !!";

	}

	else {

		cout << "The Sum of first " << N << " Natural Numbers is : " << Sum_of_Naturals(N);

	}

	cout << "\n";

	return 0;

}

int Sum_of_Naturals(int N) {

	if (N == 1) {

		return 1;

	}

	return N + Sum_of_Naturals(N - 1);

}