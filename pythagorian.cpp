#include<iostream>
using namespace std;

bool pytha(int x,int y,int z){
    int a =max(x,max(y,z));
    int b,c;
    if(a==x){
        b=y;
        c=z;
    }
    else if(a==y){
        b=x;
        c=z;
    }
    else{
        b=x;
        c=y;
    }
    if(a*a == b*b + c*c){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int x,y,z;
    cin>>x>>y>>z;
    
    if(pytha(x,y,z)){
        cout<<"Pythagorian numbers";
    }
    else{
        cout<<"Not pythagorian numbers";
    }
    return 0;
}