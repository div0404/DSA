#include<iostream>
#include<vector>
using namespace std;


//Top dowp dp
int knapsack(int wts[],int price[],int N,int W){
    //base case
    if(N == 0 or W ==0){
        return 0;
    }
    //rec case
    int inc =0;int exc = 0;
    if(wts[N-1]<=W){
        inc = price[N-1] + knapsack(wts,price,N-1,W-wts[N-1]);
    }
    exc = 0 + knapsack(wts,price,N-1,W);

    return max(inc,exc);
}

//Bottom up dp
int knapsackdp(int wts[],int price[],int N,int W){
    vector<vector<int>> dp(N+1,vector<int> (W+1,0));
    
    for(int n=1;n<=N;n++){
        for(int w=1;w<=W;w++){
            int inc = 0;int exc = 0;

            if(wts[n-1]<=w){
                inc = price[n-1] + dp[n-1][w-wts[n-1]];
            }
            exc = dp[n-1][w];

            dp[n][w] = max(inc,exc);
        }
    }
    return dp[N][W];
}

int main(){
    int wts[] = {2,7,3,4};
    int price[] = {5,20,20,10};

    int N = 4;
    int W = 11;

    cout<<knapsack(wts,price,N,W)<<endl;
    cout<<knapsackdp(wts,price,N,W)<<endl;

    return 0;
}