#include <iostream>
#include <cmath>

using namespace std;

class Point{

	private:
	int x, y;

	public:

	Point(int x, int y);

	void Set(int x, int y);
	void Get();
	double Distance_From_Origin();
	double Distance_Btw_Points(Point P);

};

Point::Point(int x, int y){

		this->x=x;
		this->y=y;

		return;

	}

void Point::Set(int x, int y){

	this->x=x;
	this->y=y;

	return;

}

void Point::Get(){

	printf("(%d, %d)\n", this->x, this->y);

	return;

}

double Point::Distance_From_Origin(){

	return sqrtf64(pow(x, 2) + pow(y, 2));

}

double Point::Distance_Btw_Points(Point P){

    return sqrtf64(pow((x-P.x), 2) + pow((y-P.y), 2));

}