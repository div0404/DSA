#include<iostream>
using namespace std;

int main (){
    int date;
    cin>>date;
    for(date=1;date<=30;date++){
        if(date%2==0){
            continue;
        }
        cout<<"Go out today!";
    }
    return 0;
}