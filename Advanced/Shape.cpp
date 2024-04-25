#include <iostream>

using namespace std;

class Shape{

    float radius;

    public:

    Shape();

    void circleArea(float r, float pi = 3.14);
    void sphereArea(float r, float pi = 3.14);
    void hemisphereArea(float r, float pi = 3.14);

};

int main(){

    Shape S;

    float r;
    cin >> r;

    S.circleArea(r);
    S.sphereArea(r);
    S.hemisphereArea(r);

    return 0;

}

Shape::Shape(){

    this->radius = 0;

    return;

}

void Shape::circleArea(float r, float pi){

    float Area = pi * r * r;
    cout << "Area of the Circle: " << Area << "\n";

    return;

}

void Shape::sphereArea(float r, float pi){

    float Area = 4 * pi * r * r;
    cout << "Area of the Sphere: " << Area << "\n";

    return;

}

void Shape::hemisphereArea(float r, float pi){

    float Area = 3 * pi * r * r;
    cout << "Area of the Hemisphere: " << "\n";

    return; 

}