#include<iostream>
#include<vector>
using namespace std;

//using recursion (exponential)
int countBST(int n){
    //base case
    if(n==0 || n==1){
        return 1;
    }

    //rec case
    int ans = 0;
    for(int i=1;i<=n;i++){
        int X = countBST(i-1);
        int Y = countBST(n-i);
        ans += X*Y;
    }
    return ans;
}

//using Top down O(n*n)
int countBSTTopdown(int n,vector<int> dp){
    //base case
    if(n==0 || n==1){
        return 1;
    } 

    //check the state
    if(dp[n]!=0){
        return dp[n];
    }

    //rec case
    int ans = 0;
    for(int i=1;i<=n;i++){
        int x = countBSTTopdown(i-1,dp);
        int y = countBSTTopdown(n-i,dp);

        ans += x*y;
    }
    return dp[n] = ans;
}

//Bottom up
int countBSTBU(int N){
    vector<int> dp(N+1,0);

    //initialisation
    dp[0] = dp[1] = 1;

    for(int n=2;n<=N;n++){
        for(int i=1;i<=n;i++){
            dp[n] += dp[i-1]*dp[n-i]; 
        }
    }
    return dp[N];
}

int main(){
    int n = 5;
    vector<int> dp(100);
    cout<<"NO. of BST using recursion: "<<countBST(n)<<endl;
    cout<<"NO. of BST using Top down: "<<countBSTTopdown(n,dp)<<endl;
    cout<<"NO. of BST using Bottom up: "<<countBSTBU(n)<<endl;

    return 0;
}