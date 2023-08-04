#include <iostream>
#include <thread>
#include <vector>


using namespace std;

void Threading(long long int Terms);

void Add(long long int Num1, long long int Num2);

unsigned long long int Sum = 0;


int main() {

	long long int Terms;

	cout << "We are going to calculate the sum of Natural Numbers till the user-entered limit !!!" << "\n\n";

	cout << "Enter the Limit : ";
	cin >> Terms;
	cout << "\n\n";

	Threading(Terms);

	cout << "The Sum of Natural Numbers till " << Terms << " is : " << Sum;

	return 0;

}

void Threading(long long int Terms) {

	vector<thread> Threads(12);

	long double Var = Terms+1;

	Var = Var / 12;


	for (int i = 0; i < 12; i++) {

		Threads[i] = thread(Add, static_cast<long long int>(i * Var), static_cast<long long int>((i + 1) * Var));

	}

	for (auto& Th : Threads) {

		Th.join();

	}

}

void Add(long long int Num1, long long int Num2) {

	for (long long int i = Num1; i < Num2; i ++) {

		Sum += i;

	}

}