#include <iostream>
#include <cmath>

using namespace std;

int main() {

	const double Pi = 2 * acos(0.0);
	double Radius;

	cout << "Enter the Radius of the Circle : ";
	cin >> Radius;
	cout << "\n";

	double Area = Pi * Radius * Radius;

	cout << "The Area of the Circle with Radius " << Radius << " is : " << Area;
	cout << "\n";

	return 0;

}