#include<iostream>
#include<climits>
using namespace std;

//using recursion
int max_profit(int prices[],int n){
    //base case
    if(n<=0){
        return 0;
    }

    //rec case
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        int cut = i+1;  //length of the cut
        int current_ans = prices[i] + max_profit(prices,n-cut);
        ans = max(ans,current_ans);
    }
    return ans;
}

//Top down 
int maxProfit(int prices[],int n,int dp[]){
    //base case
    if(n<=0){
        return 0;
    }

    //check if state is computed
    if(dp[n]!=0){
        return dp[n];
    }
    
    //rec case
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        int cut = i+1;
        int currentAns = prices[i] + maxProfit(prices,n-cut,dp);
        ans = max(ans,currentAns);
    }
    return dp[n] = ans;
}

//Bottom up o(n^2)
int maxprofit(int prices[],int n,int dp[]){
    dp[0] = 0;

    for(int len = 1;len<=n;len++){
        int ans = INT_MIN;
        for(int i=0;i<len;i++){
            int cut = i+1;
            int currentAns = prices[i] + maxprofit(prices,len-cut,dp);
            ans = max(ans,currentAns);
        }
        dp[len] = ans;
    }
    return dp[n];
}

int main(){
    int prices[] = {1,5,8,9,10,17,17,20};
    int N = sizeof(prices)/sizeof(int);
    int dp[100] = {0};

    cout<<"max profit using recursion: "<<max_profit(prices,N)<<endl;
    cout<<"max profit using top down: "<<maxProfit(prices,N,dp)<<endl;
    cout<<"max profit using bottom up: "<<maxprofit(prices,N,dp)<<endl;

    return 0;
}