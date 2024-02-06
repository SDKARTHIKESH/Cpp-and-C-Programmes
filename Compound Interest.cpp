#include <iostream>
#include <cmath>

using namespace std;

double Compound_Interest(double Principle, double Rate, double Time, int n);

int main() {

	char Option;
	double Amount, Principle, Rate, Time;

	cout << "Is the Interest Compounded Annually (A), Half-Yearly (H) or Quaterly (Q) : ";
	cin >> Option;
	cout << "\n";

	cout << "Enter the Principle Amount (in Rupees) : ";
	cin >> Principle;

	cout << "Enter the Rate of Interest (in Percent) : ";
	cin >> Rate;

	cout << "Enter the Time Period (in Years) : ";
	cin >> Time;

	cout << "\n";

	switch (Option) {

	case 'A':

		Amount = Compound_Interest(Principle, Rate, Time, 1);
		break;

	case 'H':

		Amount = Compound_Interest(Principle, Rate, Time, 2);
		break;

	case 'Q':

		Amount = Compound_Interest(Principle, Rate, Time, 4);
		break;

	default:

		cout << "You Have Entered a Invalid Choice !!";
		exit(0);

	}

	cout << "The Total Amount is : Rs. " << Amount;
	cout << "\n";

}

double Compound_Interest(double Principle, double Rate, double Time, int n) {


	return Principle * pow((1 + (Rate / (n * 100))), n*Time);

}