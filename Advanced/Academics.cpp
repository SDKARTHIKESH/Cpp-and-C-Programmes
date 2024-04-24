#include <iostream>
#include <string>

using namespace std;

class Academics{

    friend class Fee;

    int RegNo;
    string Name;
    int Mark[5], Total, Scholarship;

    public:

    void readData();
    void printData();

};

class Fee{

    int FeeToBePaid;

    public:

    Fee();

    void getFee();
    void printFee(Academics &A);

};

int main(){

    Academics A1;
    Fee F1;

    A1.readData();
    F1.getFee();

    A1.printData();
    F1.printFee(A1);

    return 0;

}

void Academics::readData(){

    cin >> this->RegNo >> this->Name;

    for(int x=0; x<5; x++){

        cin >> this->Mark[x];
        this->Total += Mark[x];

    }

    return;

}

void Academics::printData(){

    if(this->Total > 450) this->Scholarship = 50000;
    else if(this->Total > 400 and this->Total <= 450) this->Scholarship = 30000;
    else if(this->Total > 350 and this->Total <= 400) this->Scholarship = 10000;
    else this->Scholarship = 0;

    cout << "Registration Number : " << this->RegNo << "\n";
    cout << "Name : " << this->Name << "\n";

    cout << "Marks : ";
    for(int x=0; x<5; x++) cout << this->Mark[x] << " ";
    cout << "\n";

    cout << "Total : " << this->Total << "\n";
    cout << "Scholarship : " << this->Scholarship << "\n";

    return;

}

Fee::Fee(){

    this->FeeToBePaid = 0;

    return;

}

void Fee::getFee(){

    cin >> this->FeeToBePaid;

    return;

}

void Fee::printFee(Academics &A){

    cout << "Fees to be Paid : " << this->FeeToBePaid - A.Scholarship << "\n";

    return;

}