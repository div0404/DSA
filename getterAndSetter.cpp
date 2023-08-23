#include<iostream>
using namespace std;

class Product{
  private:
    int id;
    char name[100];
    int mrp;
    int sellingPrice;
  public:
    //setters

    void setMrp(int price){
        if(price>0){
            mrp = price;
        }
    }  

    void setSellingPrice(int price){
        //additional check
        if(price>mrp){
            sellingPrice = mrp;
        }
        else{
            sellingPrice  = price;
        }
    }

    //getters

    int getMrp(){
        return mrp;
    }

    int getsellingPrice(){
        return sellingPrice;
    }


};

int main(){

    Product camera;

    camera.setMrp(100);
    camera.setSellingPrice(95);

    cout<<"MRP : "<<camera.getMrp()<<endl;
    cout<<"Selling price :"<<camera.getsellingPrice()<<endl;

    return 0;
}