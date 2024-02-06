#include <iostream>

using namespace std;

double Spiral_Recursive(double Left, double Right, int N);

int main() {

	double Left, Right;
	int N;

	cout << "Enter the x-coordinate of the Left Point : ";
	cin >> Left;

	cout << "Enter the x-coordinate of the Right Point : ";
	cin >> Right;

	cout << "Enter the Number of Arms in the Spiral : ";
	cin >> N;

	cout << "\n";

	cout << "The Length of the " << N << " Arm of the Spiral is : " << Spiral_Recursive(Left, Right, N);

	return 0;

}

double Spiral_Recursive(double Left, double Right, int N){

	if (N == 0) {

		return Left;

	}

	if (N == 1) {

		return Right;

	}

	return (Spiral_Recursive(Left, Right, N - 1) + Spiral_Recursive(Left, Right, N - 2)) / 2;


	}