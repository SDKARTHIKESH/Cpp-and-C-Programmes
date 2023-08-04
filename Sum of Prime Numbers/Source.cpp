#include <iostream>
#include <thread>
#include <vector>
#include <mutex>


using namespace std;

void Threading(long long int Terms);

void Add(long long int Num1, long long int Num2);

unsigned long long int Sum = 2;

mutex Atomic;


int main() {

	unsigned long long int Terms;

	cout << "We are going to calculate the sum of Prime Numbers till the user-entered limit !!!" << "\n\n";

	cout << "Enter the Limit : ";
	cin >> Terms;
	cout << "\n";

	Threading(Terms);

	cout << "The Sum of Prime Numbers till " << Terms << " is : " << Sum << "\n";

	return 0;

}

void Threading(long long int Terms) {

    long double Var = Terms - 2;

    Var = Var / 12;

    vector<thread> Threads(12);


    for (int i = 0; i < 12; i++) {

        Threads[i] = thread(Add, static_cast<long long int>(i * Var + 3), static_cast<long long int>((i + 1) * Var + 3));

    }


    for (auto& Th : Threads) {

        Th.join();

    }

}
	



void Add(long long int Num1, long long int Num2) {

	unsigned long long int Total = 0;

	for (long long int x = Num1; x < Num2; x++) {

		if (x % 2 == 0) {

			continue;

		}

		else {

			bool Found = true;

			long long int Var = sqrt(x) + 1;

			for (long long int y = 3; y < Var; y += 2) {

				if (x % y == 0) {

					Found = false;
					break;

				}

			}

			if (Found) {

				Total = Total + x;

			}

		}

	}

	Atomic.lock();
	Sum = Sum + Total;
	Atomic.unlock();

}