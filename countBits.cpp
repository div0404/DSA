#include<iostream>
using namespace std;

int countSetBits(int n){
    int cnt = 0;
    while(n>0){
        int lastDigit = (n&1);
        cnt += lastDigit;
        n = n>>1;
    }
    return cnt;
}

int main(){
    int n;
    cin>>n;

    cout<<countSetBits(n)<<endl;

    return 0;
}