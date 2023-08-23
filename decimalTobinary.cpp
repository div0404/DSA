#include<iostream>
using namespace std;

int decimalToBinary(int n){
    int base =1;
    int ans =0;

    while(base<=n){
    base *= 2;
    }
    base /=2;

    while(base>0){
        int lastdigit = n/base;
        n -= lastdigit*base;
        base/=2;
        ans = ans*10 + lastdigit;
        return ans;
    }

}
int main(){
    int n;
    cin>>n;

    cout<<decimalToBinary(n)<<endl;
    return 0;
}