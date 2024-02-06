#include <iostream>
#include <cmath>

using namespace std;

int Sum_of_Squares(int N);

int main() {

	int N;

	cout << "Enter the Value of N : ";
	cin >> N;

	cout << "\n";

	if (N < 1) {

		cout << "Please Enter a Positive Integer !!";

	}

	else {

		cout << "The Sum of Sqaures of first " << N << " Natural Numbers is : " << Sum_of_Squares(N);

	}

	cout << "\n";

	return 0;

}

int Sum_of_Squares(int N) {

	if (N == 1) {

		return 1;

	}

	return pow(N, 2) + Sum_of_Squares(N - 1);

}