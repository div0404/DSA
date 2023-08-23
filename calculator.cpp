#include<iostream>
using namespace std;

int main(){
    int a,b;
    cout<<"Enter two numbers: "<<endl;
    cin>>a>>b;
    char op;
    cout<<"Enter a operator: "<<endl;
    cin>>op;
    
    switch(op){
        case '+' : 
        cout<<a+b<<endl;
        break;

        case '-' :
        cout<<a-b<<endl;
        break;

        case '*' :
        cout<<a*b<<endl;
        break;

        case '/' :
        cout<<a/b<<endl;
        break;

        default :
        cout<<"Enter another operator"<<endl;
    }
    return 0;
}