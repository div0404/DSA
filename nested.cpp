#include<iostream>
using namespace std;

int main (){
    int savings;
    cin>>savings;
    if(savings>5000){
        if(savings>12000){
            cout<<"Roadtrip with Sonakshi\n";
        }
        else{
            cout<<"Shopping with Sonakshi\n";
        }
    }
    return 0;
}