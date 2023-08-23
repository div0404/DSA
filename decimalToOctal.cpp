#include<iostream>
using namespace std;

int decToOctal(int n){
    int base =1;
    int ans =0;

    while(base<=n){
        base *= 8;
    }
    base/=8;

    while(base>0){
        int lastdigit = n/base;
        n -= lastdigit*base;
        base/=8;
        ans = ans*10 + lastdigit;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;

    cout<<decToOctal(n)<<endl;

    return 0;
}