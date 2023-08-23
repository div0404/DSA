#include<iostream>
#include<vector>
using namespace std;

//Top down DP
int wines(int dp[][10],int prices[],int L,int R,int y){
    //base case
    if(L>R){
        return 0;
    }

    //check if state is already computed
    if(dp[L][R]!=0){
        return dp[L][R];    
    }

    //rec case
    int sell_left = prices[L]*y + wines(dp,prices,L+1,R,y+1);
    int sell_right = prices[R]*y + wines(dp,prices,L,R-1,y+1);

    return dp[L][R] = max(sell_left,sell_right); 
}

//Bottom up DP
int wines1(int prices[],int n){
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=n-1;j++){
            int y = n-(j-i);

            if(i==j){
                dp[i][j] = prices[i]*y;
            }
            if(i<j){
                int pick_left = prices[i]*y + dp[i+1][j];
                int pick_right = prices[j]*y + dp[i][j-1];
                dp[i][j] = max(pick_left,pick_right);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[0][n-1];
}

int main(){
    int prices[] = {2,3,5,1,4};
    int dp[10][10] = {0};
    int n = 5;
    cout<<"max profit : "<<wines(dp,prices,0,n-1,1)<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"max profit : "<<wines1(prices,n)<<endl;

    return 0;
}