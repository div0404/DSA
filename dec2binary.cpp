#include<iostream>
using namespace std;

int decimal2binary(int n){
    int ans = 0;
    int p = 1;

    while(n>0){
        int remaider = n%2;
        ans += remaider*p;
        n = n/2;
        p *= 10;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<decimal2binary(n)<<endl;

    return 0;
}