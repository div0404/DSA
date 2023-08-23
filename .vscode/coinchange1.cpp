#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int mincoins(int m,vector<int> denom){
    vector<int> dp(m+1,0);
    dp[0] = 0;
    for(int i=1;i<=m;i++){
        dp[i] = INT_MAX;
        for(int c : denom){
            if(i-c>=0 and dp[i-c]!=INT_MAX){
                dp[i] = min(dp[i],dp[i-c]+1);
            }
        }
    }
    return dp[m]==INT_MAX? -1 : dp[m];
}

int main(){

    vector<int> denom = {1,5,7,10};
    int m = 17;
    cout<<mincoins(m,denom)<<endl;

    return 0;
}