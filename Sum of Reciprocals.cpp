#include <iostream>
#include <cmath>

using namespace std;

double Sum_of_Reciprocals(int N);

int main() {

	int N;

	cout << "Enter the Value of N : ";
	cin >> N;

	cout << "\n";

	if (N < 1) {

		cout << "Please Enter a Positive Integer !!";

	}

	else {

		cout << "The Sum of Reciprocals of first " << N << " Natural Numbers is : " << Sum_of_Reciprocals(N);

	}

	cout << "\n";

	return 0;

}

double Sum_of_Reciprocals(int N) {

	if (N == 1) {

		return 1;

	}

	return pow(N, -1) + Sum_of_Reciprocals(N - 1);

}