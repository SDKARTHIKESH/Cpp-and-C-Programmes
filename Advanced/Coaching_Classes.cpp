#include <iostream>
#include <string>

using namespace std;

class Candidate{

    protected:

    int CandidateId;
    string Name;
    int Age;

    public:

    virtual void readData();
    virtual void printData();
    virtual void calcAmount();

};

class General : public Candidate{

    int PackageAmount;

    public:

    void readData();
    void printData();

};

class Customized : public Candidate{

    int GamesCount, HoursCount, TotalAmount;

    public:

    void readData();
    void printData();
    void calcAmount();

};

int main(){

    Candidate* P1;
    Candidate* P2;

    General G;
    P1 = &G;

    Customized C;
    P2 = &C;

    P1->readData();
    P2->readData();
    P2->calcAmount();

    P1->printData();    
    P2->printData();

    return 0;

}

void Candidate::readData(){

    cin >> this->CandidateId >> this->Name >> this->Age;

    return;

}

void Candidate::printData(){

    cout << "Candidate ID: " << this->CandidateId << "\n";
    cout << "Name: " << this->Name << "\n";
    cout << "Age: " << this->Age << "\n";

    return;

}

void Candidate::calcAmount(){}

void General::readData(){

    Candidate::readData();

    cin >> this->PackageAmount;

    return;

}

void General::printData(){

    Candidate::printData();

    cout << "Package Amount: " << this->PackageAmount << "\n";

    return;

}

void Customized::readData(){

    Candidate::readData();

    cin >> this->GamesCount >> this->HoursCount;

    return;

}

void Customized::printData(){

    Candidate::printData();

    cout << "Number of Games: " << this->GamesCount << "\n";
    cout << "Number of Hours: " << this->HoursCount << "\n";
    cout << "Total Amount: " << this->TotalAmount << "\n";

    return;

}

void Customized::calcAmount(){

    this->TotalAmount = this->GamesCount * this->HoursCount * 100;

    return;

}