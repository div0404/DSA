#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//Top down approach



//Bottom Up approach
int minCoinsForChange(int m,vector<int> denom){
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
    return dp[m]==INT_MAX ? -1 : dp[m];
}

int main(){
    int m;
    cin>>m;

    vector<int> denom = {1,5,7,10};//types coin

    cout<<minCoinsForChange(m,denom)<<endl;

    return 0;
}