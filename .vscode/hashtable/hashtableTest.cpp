#include<iostream>
#include "header.h"
using namespace std;

int main(){
    HashTable<int> h;

    h.insertion("Apple",100);
    h.insertion("Banana",140);
    h.insertion("Mango",160);
    h.insertion("Papaya",180);
    h.insertion("Watermelon",200);
    h.insertion("Pineapple",220);
    h.insertion("Litchi",240);

    h.print();

    string fruit;
    cin>>fruit;

    int *price = h.search(fruit);

    if(price!=NULL){
        cout<<"Price of fruit is :"<<*price<<endl;
    }
    else{
        cout<<"Fruit is not present"<<endl;
    }

    return 0;
}