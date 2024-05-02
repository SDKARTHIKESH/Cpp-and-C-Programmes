#include <iostream>

using namespace std;

class Matrix{

	int** Mat;
	int Length;

	public:

	Matrix(int Len);
	~Matrix();

	void Read();
	void Print();

	Matrix operator+(Matrix &M);
	Matrix operator-(Matrix &M);
	Matrix operator*(Matrix &M);

};

int main(){

	int Len;
	cin >> Len;

	Matrix M1(Len), M2(Len);

	M1.Read();
	M2.Read();

	M1.Print();
	M2.Print();

	Matrix Sum = M1 + M2;
	Matrix Difference = M1 - M2;
	Matrix Product = M1 * M2;

	cout << "Sum : " << "\n";
	Sum.Print();

	cout << "Difference : " << "\n";
	Difference.Print();

	cout << "Product : " << "\n";
	Product.Print();
	
	return 0;

}

Matrix::Matrix(int Len){
	
	Length = Len;
	Mat = new int*[Length];

	for(int x = 0; x < Length; x++) *(Mat + x) = new int[Length];

	return;

}

Matrix::~Matrix(){

	for(int x = 0; x < Length; x++) delete Mat[x];

	delete Mat;

}

void Matrix::Read(){

	for(int x = 0; x < Length; x++){

		for(int y = 0; y < Length; y++){

			cin >> *(*(Mat + x) + y);

		}
		
	}

	return;

}

void Matrix::Print(){

	for(int x = 0; x < Length; x++){

		for(int y = 0; y < Length; y++){

			cout << *(*(Mat + x) + y) << " ";

		}

		cout << "\n";

	}

	cout << "\n";

	return;

}

Matrix Matrix::operator+(Matrix &M){


	Matrix Temp(Length);

	for(int x = 0; x < Length; x++){

		for(int y = 0; y < Length; y++){

			*(*(Temp.Mat + x) + y) = *(*(Mat + x) + y) + *(*(M.Mat + x) + y);

		}

	}

	return Temp;

}

Matrix Matrix::operator-(Matrix &M){

	Matrix Temp(Length);

	for(int x = 0; x < Length; x++){

		for(int y = 0; y < Length; y++){

			*(*(Temp.Mat + x) + y) = *(*(Mat + x) + y) - *(*(M.Mat + x) + y);

		}

	}

	return Temp;

}

Matrix Matrix::operator*(Matrix &M){

	Matrix Temp(Length);

	for(int x = 0; x < Length; x++){

		for(int y = 0; y < Length; y++){

			for(int z = 0; z < Length; z++){

				*(*(Temp.Mat + x) + y) += *(*(Mat + x) + z) * *(*(M.Mat + z) + y);

			}

		}

	}

	return Temp;

}