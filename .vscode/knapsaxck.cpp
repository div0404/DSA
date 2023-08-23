#include<iostream>
#include<vector>
using namespace std;

//Recursive approach Top down DP
int knapsack(int wts[],int prices[],int W,int N){
    //base case
    if(N==0 or W==0){
        return 0;
    }
    
    // for every element there is two choice to include or execlude
    int inc = 0;
    int exc = 0;

    if(wts[N-1]<=W){
        inc = prices[N-1] + knapsack(wts,prices,(W-wts[N-1]),N-1);
    }
    exc = 0 + knapsack(wts,prices,W,N-1);

    return max(inc,exc);
}

//Bottom Up DP
int knapsax(int wts[],int prices[],int W,int N){
    vector<vector<int>> dp(N+1,vector<int>(W+1,0));

    for(int n=1;n<=N;n++){
        for(int w=1;w<=W;w++){
            int inc = 0,exc = 0;
            if(wts[n-1]<=w){
                inc = prices[n-1] + dp[n-1][w-wts[n-1]];
            }
            exc = 0 + dp[n-1][w];

            dp[n][w] = max(inc,exc);
        }
    }
    return dp[N][W];
}

int main(){
    int wts[] = {2,7,3,4};
    int prices[] = {5,20,20,10};
    int W = 11;
    int N = 4;

    cout<<knapsack(wts,prices,W,N)<<endl;
    cout<<knapsax(wts,prices,W,N)<<endl;

    return 0;
}