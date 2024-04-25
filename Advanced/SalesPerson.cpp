#include <iostream>
#include <string>

using namespace std;

class SalesPerson{

    friend class Salary;

    int Eno;
    string Name, Designation;
    int Salescount, Bonus;

    public:

    void readData();
    void printData();
    void calcBonus();

};

class Salary{

    float Basic, HRA, DA, PF, Gross;

    public:

    void readSalary();
    void printSalary();
    void calcSalary(SalesPerson &SP);

};

int main(){

    SalesPerson SP;
    Salary S;

    SP.readData();
    SP.calcBonus();

    S.readSalary();
    S.calcSalary(SP);

    SP.printData();
    S.printSalary();
    
    return 0;

}

void SalesPerson::readData(){

    cin >> this->Eno >> this->Name >> this->Designation >> this->Salescount;

    return;

}

void SalesPerson::printData(){

    cout << "Eno: " << this->Eno << "\n";
    cout << "Name: " << this->Name << "\n";
    cout << "Designation: " << this->Designation << "\n";
    cout << "Salescount: " << this->Salescount << "\n";
    cout << "Bonus: " << this->Bonus << "\n";

    return;

}

void SalesPerson::calcBonus(){

    if(this->Salescount < 100) this->Bonus = 1000;
    else if(this->Salescount > 100 and this->Salescount < 500) this->Bonus = 5000;
    else this->Bonus = 10000;

    return;

}

void Salary::readSalary(){

    cin >> this->Basic;

    return;

}

void Salary::printSalary(){

    cout << "Basic: " << this->Basic << "\n";
    cout << "HRA: " << this->HRA << "\n";
    cout << "DA: " << this->DA << "\n";
    cout << "PF: " << this->PF << "\n";
    cout << "Gross: " << this->Gross << "\n";

    return;

}

void Salary::calcSalary(SalesPerson &SP){

    this->HRA = Basic * 0.15;
    this->DA = Basic * 0.25;
    this->PF = Basic * 0.05;
    
    this->Gross = this->Basic + this->HRA + this->DA + SP.Bonus - this->PF;

    return;

}