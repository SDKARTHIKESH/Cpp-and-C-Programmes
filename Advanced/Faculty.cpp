#include <iostream>
#include <string>

using namespace std;

class Faculty{

    protected:

    string Subject, Mode;

    public:

    void readFaculty();
    void printFaculty();

};

class Student{

    protected:

    string School, Regno;

    public:

    void readStudent();
    void printStudent();

};

class ResearchAsst : public Faculty, public Student{

    string Domain, Projects, Name;

    public:

    void readResearchAsst();
    void printResearchAsst();

};

int main(){

    Student Arr1[10];
    ResearchAsst Arr2[30];

    for(int x = 0; x < 10; x++){

        Arr1[x].readStudent();

    }

    for(int x = 0; x < 30; x++){

        Arr2[x].readResearchAsst();

    }

    for(int x = 0; x < 10; x++){

        Arr1[x].printStudent();

    }

    for(int x = 0; x < 10; x++){

        Arr2[x].printResearchAsst();

    }

    return 0;

}

void Faculty::readFaculty(){

    cin >> this->Subject >> this->Mode;

    return;

}

void Faculty::printFaculty(){

    cout << "Subject: " << this->Subject << "\n";
    cout << "Mode: " << this->Mode << "\n";

    return;

}

void Student::readStudent(){

    cin >> this->School >> this->Regno;

    return;

}

void Student::printStudent(){

    cout << "School: " << this->School << "\n";
    cout << "Regno: " << this->Regno << "\n";

    return;

}

void ResearchAsst::readResearchAsst(){

    readFaculty();
    readStudent();

    cin >> this->Domain >> this->Projects >> this->Name;

    return; 

}

void ResearchAsst::printResearchAsst(){

    printFaculty();
    printStudent();

    cout << "Domain: " << this->Domain << "\n";
    cout << "Projects: " << this->Projects << "\n";
    cout << "Name: " << this->Name << "\n";

    return;

}