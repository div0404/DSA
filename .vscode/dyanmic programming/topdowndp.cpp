#include<iostream>
using namespace std;

int fib(int n,int dp[]){
    if(n == 0 || n == 1){
        return n;
    }

    //check the current state
    if(dp[n] != 0){
        return dp[n];
    }

    //otherwise calculate and store it
    return dp[n] = fib(n-1,dp) + fib(n-2,dp);

}

int main(){
    int n;
    cin>>n;
    int dp[n+1] = {0};

    cout<<fib(n,dp)<<endl;

    return 0;
}