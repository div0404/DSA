#include<iostream>
using namespace std;

int tobinary(int n){
    int ans = 0;
    int p = 1;

    while(n>0){
        int lastBit = (n&1);
        ans += lastBit*p;
        p *= 10;
        n = n>>1;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;

    cout<<tobinary(n)<<endl;

    return 0;
}