//Imani Cage
//order.cpp

#include <iostream>
using namespace std;

class Order{
    private:
    string name;
    int itemID;
    double total;
    bool status;

    public:
    Order(){ // constructor for Default orders.
    name = "N/A";
    itemID = 0;
    total = 0;
    status = false;
    }
    void getOrder(); //getter function, with defaults to display.
    void setOrder(string str, int numID, double costs, bool active);
};

void Order::getOrder(){
    cout << "This is the getter function. This will only display the values and variables of the Order class.";
    cout << endl << "Name: " << name;
    cout << endl << "Item ID: " << itemID;
    cout << endl << "Total: " << total;
    if(!status){
    cout << endl << "Status: Inactive";
    }else{
        cout << endl << "Status: Active";
    }
}

void Order::setOrder(string str, int numID, double costs, bool active){
    name = str;
    itemID = numID;
    total = costs; 
    status = active; 
    cout << "This is the setter function. This will display the new values within the variables.";
    cout << endl << name;
    cout << endl << itemID;
    cout << endl << total;
    cout << endl << status;
}

int main(){
    Order example;

    cout << "This order was made without using the setter, only getter, and will display the default values" ;
    cout << endl << endl;
    example.getOrder();
    cout << endl << endl;
    cout << "The order is now using setter." ;
    cout << endl << endl;
    example.setOrder("Apple", 18740, 1.79, true);
    cout << endl << endl;
    cout << "This is now calling the getter file to see the change.";
    cout << endl << endl;
    example.getOrder();
    cout << endl;


    return 0;

}
