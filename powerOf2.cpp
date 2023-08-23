#include<iostream>
using namespace std;

void powerOf2(int n){
    if((n & (n-1))==0){
        cout<<"Power of 2"<<endl;
    }
    else{
        cout<<"Not a power of 2"<<endl;
    }
}

int main(){
    int n;
    cin>>n;

    powerOf2(n);

    return 0;
}