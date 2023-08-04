#include <iostream>
#include "Header.h"

using namespace std;

int main() {

	unsigned long long int Terms;

	cout << "We are going to calculate the sum of Prime Numbers till the user-entered limit !!!" << "\n\n";

	cout << "Enter the Limit : ";
	cin >> Terms;
	cout << "\n\n";

	Summation Dup(Terms, 'p');

	cout << "The Sum of Prime Numbers till " << Terms << " is : " << Dup.Solution() << "\n";

	return 0;

}