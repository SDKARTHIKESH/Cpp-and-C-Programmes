#include <iostream>
#include <string>

using namespace std;

void Swap(int& Num1, int& Num2);

int main() {

	int Number1, Number2;

	cout << "We are going to Swap 2 Numbers !!!" << "\n\n";

	cout << "Enter the Value of the First Number : ";
	cin >> Number1;
	cout << "\n";

	cout << "Enter the Value of the Second Number : ";
	cin >> Number2;
	cout << "\n\n";

	cout << "Number-1 : " << Number1 << "\n";
	cout << "Number-2 : " << Number2 << "\n\n";

	Swap(Number1, Number2);

	cout << "After Swapping :" << "\n\n";

	cout << "Number-1 : " << Number1 << "\n";
	cout << "Number-2 : " << Number2 << "\n\n";

	return 0;
}

void Swap(int& Num1, int& Num2) {

	int Dup = Num1;
	Num1 = Num2;
	Num2 = Dup;


}