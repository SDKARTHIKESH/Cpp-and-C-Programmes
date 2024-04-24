#include <iostream>
#include <string>

using namespace std;

class Vehicle{

    protected:

    string Regno, Region;

    public:

    Vehicle();

    void ReadVehicle();
    void printVehicle();

};

class FourWheeler : public Vehicle{

    protected:

    string Type;

    public:

    FourWheeler();

    void ReadData();
    void printData();

};

class Car : public FourWheeler{

    protected:

    string Name, Manufacturer;

    public:
    
    Car();

    void readCar();
    void printCar();

};

int main(){

    Car C;

    C.readCar();
    C.printCar();

    return 0;

}

Vehicle::Vehicle(){

    cout << "Constructor in Super Class of all" << "\n";

    return;

}

void Vehicle::ReadVehicle(){

    cin >> this->Regno >> this->Region;

    return;

}

void Vehicle::printVehicle(){

    cout << "Regno: " << this->Regno << "\n";
    cout << "Region: " << this->Region << "\n";

    return;

}

FourWheeler::FourWheeler() : Vehicle(){

    cout << "Constructor in Four Wheeler class" << "\n";

    return;

}

void FourWheeler::ReadData(){

    ReadVehicle();

    cin >> this->Type;

    return;

}

void FourWheeler::printData(){

    printVehicle();

    cout << "Type: " << this->Type << "\n";

    return;

}

Car::Car() : FourWheeler(){

    cout << "Constructor in Car Class" << "\n";

    return;

}

void Car::readCar(){

    ReadData();

    cin >> this->Name >> this->Manufacturer;

    return;

}

void Car::printCar(){

    printData();

    cout << "Name: " << this->Name << "\n";
    cout << "Manufacturer: " << this->Manufacturer << "\n";

    return;

}