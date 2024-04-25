#include <iostream>
#include <string>

using namespace std;

class Employee{

    protected:

    int Eno;
    string Ename, Designation;
    int Salary;

    public:

    Employee();
    Employee(int Eno, string Ename, string Designation, int Salary);

    void readEmployee();
    void displayEmployee();

};

class Manager : public Employee{

    int Totalemp, Totalsupervisors;

    public:

    Manager();
    Manager(int Eno, string Ename, string Designation, int Salary, int Totalemp, int Totalsupervisors);

    void readManager();
    void displayManager();

};

int main(){

    int Len;
    cin >> Len;

    Manager Arr[Len];

    for(int x = 0; x < Len; x++){

        Arr[x].readManager();
        
    }

    for(int x = 0; x < Len; x++){

        Arr[x].displayManager();
        
    }

    return 0;
        
}

Employee::Employee(){

    this->Eno = 0;
    this->Ename = "\0";
    this->Designation = "\0";
    this->Salary = 0;

    return;

}

Employee::Employee(int Eno, string Ename, string Designation, int Salary){

    this->Eno = Eno;
    this->Ename = Ename;
    this->Designation = Designation;
    this->Salary = Salary;

    return;

}

void Employee::readEmployee(){

    cin >> this->Eno >> this->Ename >> this->Designation >> this->Salary;

    return;

}

void Employee::displayEmployee(){

    cout << "Eno: " << this->Eno << "\n";
    cout << "Ename: " << this->Ename << "\n";
    cout << "Designation: " << this->Designation << "\n";
    cout << "Salary: " << this->Salary << "\n";

    return;

}

Manager::Manager() : Employee(){

    this->Totalemp = 0;
    this->Totalsupervisors = 0;

    return;

}

Manager::Manager(int Eno, string Ename, string Designation, int Salary, int Totalemp, int Totalsupervisors) : Employee(Eno, Ename, Designation, Salary){

    this->Totalemp = Totalemp;
    this->Totalsupervisors = Totalsupervisors;

    return;

}

void Manager::readManager(){

    readEmployee();

    cin >> this->Totalemp >> this->Totalsupervisors;

    return;

}

void Manager::displayManager(){

    displayEmployee();

    cout << "Total Employees: " << this->Totalemp << "\n";
    cout << "Total Supervisors: " << this->Totalsupervisors << "\n";

    return;

}