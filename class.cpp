#include<iostream>
using namespace std;

// Poduct (shopping list)
class product{
    //data members  (properties)
  private:  
    int id;
    char name[100];
  public:  
    int mrp;
    int sellingPrice;
    int discount;
};

int main(){
    product camera;

    camera.mrp = 100;
    camera.discount = 20;
    camera.sellingPrice = 80;

    cout<<sizeof(camera)<<endl;

    cout<<"MRP:"<<camera.mrp<<endl;
    cout<<"Discount:"<<camera.discount<<endl;
    cout<<"Selling price:"<<camera.sellingPrice<<endl;

    return 0;
}