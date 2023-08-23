#include<iostream>
using namespace std;

void payingTax(int &money){
    float tax = 0.10;
    money = money - money*tax;
}

int main(){
    int income;
    cin>>income;
    
    payingTax(income);

    cout<<income<<endl;

    return 0;
}