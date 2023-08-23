#include<iostream>
#include<cstring>
using namespace std;

class Product{
    private: 
    int id;
    char * name;

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

        name = new char[strlen(n)+1];
        strcpy(name,n);
    }

    //defining copy constructor
    Product(Product &X){
        id = X.id;
        name = new char[strlen(X.name)+1];
        strcpy(name,X.name);
        mrp = X.mrp;
        sellingPrice = X.sellingPrice;
    } 

    //defining copy assignment operator
    void operator=(Product &X){
        //Creating Deep copy inside copy assignment operator
        id = X.id;
        name = new char[strlen(X.name)+1];
        strcpy(name,X.name);
        mrp = X.mrp;
        sellingPrice = X.sellingPrice;
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

    void setName(char * name){
        strcpy(this->name,name);
    }

    void showDetails(){
        cout<<"Name : "<<name<<endl;
        cout<<"ID : "<<id<<endl;
        cout<<"Selling price : "<<sellingPrice<<endl;
        cout<<"MRP : "<<mrp<<endl;
    }

    //destructor
    ~Product(){
        cout<<"Deleting : "<<name<<endl;
        if(name!= NULL){
            delete [] name;
            name = NULL;
        }    
    }
};

int main(){
    Product camera(123,"MOTOG62",14999,14749);
    Product oldCmaera;  //constructor

    //copy assignment operator
    oldCmaera = camera;

    oldCmaera.setName("SONY");


    //oldCmaera.setName("MOTOG71");
    //oldCmaera.setSellingPrice(1000);

    oldCmaera.showDetails();
    cout<<"---------------"<<endl;
    camera.showDetails();

    //copy can be created by using a special constructor --> copy constructor
    //Product webCam(camera);

    //Product handycam = camera;

    //camera.setMrp(100);
    //camera.setSellingPrice(90);

    /*camera.showDetails();
    cout<<"-------------------"<<endl;
    webCam.showDetails();
    cout<<"---------------------"<<endl;
    handycam.setMrp(1001);
    handycam.showDetails();*/

    //cout<<camera.getMrp()<<endl;
    //cout<<camera.getSellingPrice()<<endl;
    //cout<<camera.getName()<<endl;

    return 0;
}