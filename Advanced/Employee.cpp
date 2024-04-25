#include <iostream>
#include <string>

using namespace std;

class Person{

    protected:

    string Name;
    int ID;

    public:

    virtual void getData();
    virtual void putData();
    virtual void calcTax();

};

class GovtEmp : public Person{

    int AnnualSalary;

    public:

    void getData();
    void putData();
    void calcTax();

};

class PrivateEmp : public Person{

    int Wages, DaysWorked;

    public:

    void getData();
    void putData();
    void calcTax();

};

int main(){

    Person* P;

    GovtEmp GE;
    P = &GE;

    P->getData();
    P->putData();
    P->calcTax();

    PrivateEmp PE;
    P = &PE;

    P->getData();
    P->putData();
    P->calcTax();

    return 0;

}

void Person::getData(){

    cin >> this->Name >> this->ID;

    return;

}

void Person::putData(){

    cout << "Name: " << this->Name << "\n";
    cout << "ID: " << this->ID << "\n";

    return;

}

void Person::calcTax(){

    cout << "All earning individuals must pay tax regularly" << "\n";

    return;

}

void GovtEmp::getData(){

    Person::getData();
    cin >> this->AnnualSalary;

    return;

}

void GovtEmp::putData(){

    Person::putData();
    cout << "Salary: " << this->AnnualSalary << "\n";

    return;

}

void GovtEmp::calcTax(){

    float IncomeTax = (this->AnnualSalary - 500000) * 0.1;
    cout << "Income Tax: " << IncomeTax << "\n";

    return;

}

void PrivateEmp::getData(){

    Person::getData();
    cin >> this->Wages >> this->DaysWorked;

    return;

}

void PrivateEmp::putData(){

    Person::putData();

    cout << "Wages :" << this->Wages << "\n";
    cout << "Days Worked: " << this->DaysWorked << "\n";

    return; 

}

void PrivateEmp::calcTax(){

    float IncomeTax = ((this->Wages * this->DaysWorked) - 300000) * 0.2;
    cout << "Income Tax: " << IncomeTax << "\n";

    return;

}