#include<iostream>
using namespace std;

int powerFn(int a,int n){
    //base case
    if(n==0){
        return 1;
    }

    return a*powerFn(a,n-1);
}

// optimized fn
int fastpower(int a,int n){
    //base case
    if(n==0){
        return 1;
    }

    int subPower = fastpower(a,n/2);
    int subPowerSq = subPower*subPower;
    if(n&1){
        return a*subPowerSq;
    }
    else{
        return subPowerSq;
    }
}

int main(){
    int a,n;
    cin>>a>>n;

    cout<<powerFn(a,n)<<endl;
    cout<<fastpower(a,n)<<endl;

    return 0;
}