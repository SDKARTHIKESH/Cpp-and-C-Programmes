#include <iostream>
#include <string>

using namespace std;

class Product{

    int Pno;
    string Pname, Pdesc;
    int Pprice;
    string Pcategory;

    static int Product_Count;

    public:

    Product();
    Product(int Pno, string Pname, string Pdesc, int Pprice, string Pcategory);
    Product(Product &P);

    void readProduct();
    void calcBill(int Units=1);

    static void display_count_objects();

};

int Product::Product_Count = 0;

int main(){

    Product P1;

    P1.readProduct();
    P1.calcBill(20);
    Product::display_count_objects();

    int Pno;
    string Pname, Pdesc;
    int Pprice;
    string Pcategory;

    cin >> Pno >> Pname >> Pdesc >> Pprice >> Pcategory;

    if(Pcategory != "Premium" and Pcategory != "Basic" and Pcategory != "Standard"){

        cout << "Invalid Category. The Category should be any one of (Premium, Basic, Standard)" << "\n";
        cout << "Re-enter the Category" << "\n";

        cin >> Pcategory;

    }

    Product P2(Pno, Pname, Pdesc, Pprice, Pcategory);

    P2.calcBill(10);
    Product::display_count_objects();

    Product P3 = P2;

    P3.calcBill();
    Product::display_count_objects();

    return 0;

}

Product::Product(){

    this->Pno = 0;
    this->Pname = "\0";
    this->Pdesc = "\0";
    this->Pprice = 0;
    this->Pcategory = "\0";

    Product_Count++;

    return;

}

Product::Product(int Pno, string Pname, string Pdesc, int Pprice, string Pcategory){

    this->Pno = Pno;
    this->Pname = Pname;
    this->Pdesc = Pdesc;
    this->Pprice = Pprice;
    this->Pcategory = Pcategory;

    Product_Count++;

    return;

}

Product::Product(Product &P){

    this->Pno = P.Pno;
    this->Pname = P.Pname;
    this->Pdesc = P.Pdesc;
    this->Pprice = P.Pprice;
    this->Pcategory = P.Pcategory;

    Product_Count++;

    return;

}

void Product::readProduct(){

    cin >> this->Pno >> this->Pname >> this->Pdesc >> this->Pprice >> this->Pcategory;

    if(this->Pcategory != "Premium" and this->Pcategory != "Basic" and this->Pcategory != "Standard"){

        cout << "Invalid Category. The Category should be any one of (Premium, Basic, Standard)" << "\n";
        cout << "Re-enter the Category" << "\n";

        cin >> this->Pcategory;

    }

    return;

}

void Product::calcBill(int Units){

    cout << "Bill Amount: " << this->Pprice * Units << "\n";

    return;

}

void Product::display_count_objects(){

    cout << "Current Number of Objects: " << Product_Count << "\n";

    return;

}