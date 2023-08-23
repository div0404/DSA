#include<iostream>
#include<cstring>
using namespace std;

class Product{
    private: 
    int id;
    char name[100];

    int mrp;
    int sellingPrice;

    public :

    //constructor
    Product(){
        cout<<"Inside the constructor"<<endl;
    }
    
    //parameterised constructor
    Product(int id,char *n,int mrp,int sellingPrice){
        this->id = id;
        this->mrp = mrp;
        this->sellingPrice = sellingPrice;
        strcpy(name,n);
    }

    //setter
    void setMrp(int price){
        if(price>0){
            mrp = price;
        }
    }

    void setSellingPrice(int price){
        if(price>mrp){
            sellingPrice = mrp;
        }
        else{
            sellingPrice = price;
        }
    }

    //getters
    int getMrp(){
        return mrp;
    }

    int getSellingPrice(){
        return sellingPrice;
    }

    string getName(){
        return name;
    }
};

int main(){
    Product camera(123,"MOTOG62",14999,14749);

    //camera.setMrp(100);
    //camera.setSellingPrice(90);

    cout<<camera.getMrp()<<endl;
    cout<<camera.getSellingPrice()<<endl;
    cout<<camera.getName()<<endl;

    return 0;
}