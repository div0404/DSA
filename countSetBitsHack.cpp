#include<iostream>
using namespace std;

int countSetBitsHack(int n){
    int ans = 0;
    while (n>0)
    {
        // removes last set bit of current number
        n = n & (n-1);
        ans++;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    
    cout<<countSetBitsHack(n)<<endl;

    return 0;
}