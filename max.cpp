#include<iostream>
using namespace std;

int main(){
    // max of three no.
    int a, b,c;
    cin>>a>>b>>c;

    if(a>b){
        if(a>c){
            cout<<"max no. "<<a<<endl;
        }
        else{
            cout<<"max no. "<<c<<endl;
        }
    }
    else{
        if(b>c){
            cout<<"max no. "<<b<<endl;
        }
        else{
            cout<<"max no. "<<c<<endl;
        }
    }
    return 0;
}