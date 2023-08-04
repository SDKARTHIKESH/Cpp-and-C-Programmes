#pragma once

#ifndef Header_H
#define Header_H

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>


using namespace std;


/*class Prime_Numbers {

public:

	Prime_Numbers(long long int Terms);
	unsigned long long int Solution();
	

private:

	long double Var;
	unsigned long long int Total = 0;
	unsigned long long int Sum = 2;
	mutex Atomic;

	void Add(long long int Num1, long long int Num2);

};


Prime_Numbers::Prime_Numbers(long long int Terms) {

	Var = Terms - 2;

	Var = Var / 12;

	vector<thread> Threads(12);


	for (int i = 0; i < 12; i++) {

		Threads[i] = thread(Add, static_cast<long long int>(i * Var + 3), static_cast<long long int>((i + 1) * Var + 3));

	}


	for (auto& Th : Threads) {

		Th.join();

	}

}


void Prime_Numbers::Add(long long int Num1, long long int Num2) {

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

unsigned long long int Prime_Numbers::Solution() {

	return Sum;

}*/

class Threading {

public:

	Threading(long long int Terms, auto Obj);
	unsigned long long int Solution();


private:

	long double Var;

};


Threading::Threading(long long int Terms,  Obj) {


	Var = Terms - 2;

	Var = Var / 12;

	vector<thread> Threads(12);


	for (int i = 0; i < 12; i++) {

		Threads[i] = thread(Obj.Add, static_cast<long long int>(i * Var + 3), static_cast<long long int>((i + 1) * Var + 3));

	}

	for (auto& Th : Threads) {

		Th.join();

	}

}

unsigned long long int Threading::Solution() {

	return Obj.Solution();

}



class Prime_Numbers {

private:

	unsigned long long int Total = 0;
	unsigned long long int Sum = 2;
	mutex Atomic;

	void Add(long long int Num1, long long int Num2);
	unsigned long long int Solution();

};


void Prime_Numbers::Add(long long int Num1, long long int Num2) {

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

unsigned long long int Prime_Numbers::Solution() {

	return Sum;

}



class Natural_Numbers : public Prime_Numbers{

	

};


/*class Summation {

public:

	Summation(long long int Terms, char Option);
	unsigned long long int Solution();
	


private:

	long double Var;
	unsigned long long int Total = 0;
	unsigned long long int Sum = 2;
	mutex Atomic;

	void Add1(long long int Num1, long long int Num2);
	void Add2(long long int Num1, long long int Num2);
	void Add3(long long int Num1, long long int Num2);

	void (Summation::*Ptr)(long long int, long long int);

};


Summation::Summation(long long int Terms, char Option) {

	if (Option == 'P' or Option == 'p') {

		Ptr = &Summation::Add1;

	}

	else if (Option == 'N' or Option == 'n') {

		Ptr = &Summation::Add2;
		Sum = 3;

	}

	else if (Option == 'E' or Option == 'e') {

		Ptr = &Summation::Add3;

	}

	Var = Terms - 2;

	Var = Var / 12;

	vector<thread> Threads(12);


	for (int i = 0; i < 12; i++) {

		Threads[i] = thread(Ptr, static_cast<long long int>(i * Var + 3), static_cast<long long int>((i + 1) * Var + 3));

	}


	for (auto& Th : Threads) {

		Th.join();

	}

}


void Summation::Add1(long long int Num1, long long int Num2) {

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


void Summation::Add2(long long int Num1, long long int Num2) {

	for (long long int i = Num1; i < Num2; i++) {

		Total += i;

	}

	Atomic.lock();
	Sum = Sum + Total;
	Atomic.unlock();

}


void Summation::Add3(long long int Num1, long long int Num2) {

	for (long long int i = Num1; i < Num2; i+=2) {

		Total += i;

	}

	Atomic.lock();
	Sum = Sum + Total;
	Atomic.unlock();

}


unsigned long long int Summation::Solution() {

	return Sum;

}*/




#endif