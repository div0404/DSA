#include<iostream>
#include<vector>
using namespace std;

//Recursion
//Top down
//Bottom Up 
//Bottom up optimised

//recursion O(k^n)
int countWays(int n,int k){
    //base case
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }

    //rec case
    int ans = 0;
    for(int jump=1;jump<=k;jump++){
        ans += countWays(n-jump,k);
    }
    return ans;
}

//top down (recursdion + memorisation) O(k*n)
int countWaysTD(int n,int k,vector<int> dp){
    //base case
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }

    //check if state is already computed
    if(dp[n]!=0){
        return dp[n];
    }

    //rec case
    int ans = 0;
    for(int jump =1;jump<=k;jump++){
        ans += countWaysTD(n-jump,k,dp); 
    }
    return dp[n] = ans;
}

//Bottom up O(k*n)
int countWaysBU(int n,int k,vector<int> dp){
    //initialisation
    dp[0] = 1;

    //iterative method
    for(int i=1;i<=n;i++){
        //can take atmost k jumps
        for(int jump = 1;jump<=k;jump++){
            if(i-jump>=0){
                dp[i] += dp[i-jump];
            }
        } 
    }
    return dp[n];
}

// Bottom up optimised
int countWaysOpt(int n,int k,vector<int> dp){
    dp[0] = 1;
    dp[1] = 1;

    //iterative method
    for(int i=2;i<=n;i++){
        if(i-k-1>=0){
            dp[i] = (2*dp[i-1]) - dp[i-k-1];
        }
        else{
            dp[i] = 2*dp[i-1];
        }
    }
    return dp[n];
}


int main(){
    int n,k;
    cin>>n>>k;

    vector<int> dp(n+1,0);

    cout<<"using recursion : "<<countWays(n,k)<<endl;
    cout<<"using top down : "<<countWaysTD(n,k,dp)<<endl;
    cout<<"using bottom up : "<<countWaysBU(n,k,dp)<<endl;
    cout<<"using optimised bottom up : "<<countWaysOpt(n,k,dp)<<endl;

    return 0;
}