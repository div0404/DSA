#include<iostream>
using namespace std;

int fib2(int n,int dp[]){
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;

    int dp[n+1] = {0};

    cout<<fib2(n,dp)<<endl;

    return 0;
}