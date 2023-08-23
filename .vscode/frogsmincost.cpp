#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//Top down 
int mincost(vector<int> height,int n,vector<int> dp,int i){
    //base case
    if(i==n-1){
        return 0;
    }

    //corner case
    if(i>=n){
        dp[i] = INT_MAX;    
    }

    //check if the state is already computed
    if(dp[i]!=0){
        return dp[i];
    }

    //rec case
    int minCost = INT_MAX;
    int maxJump = 2;
    for(int jump = 1;jump<=maxJump;jump++){
        int nextrock = i + jump;
        int subproblem = mincost(height,n,dp,nextrock);
        if(subproblem!=INT_MAX){
            minCost = min(minCost,(abs(height[i]-height[nextrock]) + subproblem));
        }
    }
    return dp[i] = minCost;
}

//bottom up
int mincostBU(vector<int> height,int n,vector<int> dp,int i){
    //initialisation
    dp[0] = 0;
    dp[1] = abs(height[1] - height[0]) + dp[0];

    for(int i=2;i<n;i++){
        //one step jump 
        int opt1 = abs(height[i] - height[i-1]) + dp[i-1];
        //two step jump
        int opt2 = abs(height[i] - height[i-2]) + dp[i-2];

        dp[i] = min(opt1,opt2);
    }
    return dp[n-1];
}

int main(){
    vector<int> height = {10,30,40,20};
    int n = height.size();

    vector<int> dp(n+1,0);
    cout<<"min cost top down : "<<mincost(height,n,dp,0)<<endl;
    cout<<"min cost using bottom up: "<<mincostBU(height,n,dp,0)<<endl;

    return 0;
}