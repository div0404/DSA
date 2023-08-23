#include<iostream>
#include<vector>
using namespace std;

//Top down
int countSubstring(string s1,string s2,int i,int j,vector<vector<int>> dp){
    // base case
    if((i == -1 and j == -1) or j == -1){
        return 1;
    }
    if(i == -1){
        return 0;
    }

    //check if state is already computed
    if(dp[i][j] != 0){
        return dp[i][j];
    }

    //rec case
    if(s1[i]!=s2[j]){
        return  dp[i][j] = countSubstring(s1,s2,i-1,j,dp);
    }
    return dp[i][j] = countSubstring(s1,s2,i-1,j-1,dp) + countSubstring(s1,s2,i-1,j,dp);
}

//bottom up
int countSubBU(string s1,string s2){
    int n1 = s1.length();
    int n2 = s2.length();

    vector<vector<int>> dp (n1+1,(vector<int> (n2+1,0)));

    //first col
    for(int i=0;i<=n1;i++){
        dp[i][0] = 1;
    }

    //first row
    for(int i=1;i<=n1;i++){
        dp[0][i] = 0;
    }

    //fill the dp
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n1][n2];
}

int main(){
    string s1 = "ABCDCE";
    string s2 = "ABC";
    int n1 = s1.length();
    int n2 = s2.length();

    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));

    cout<<"using top down : "<<countSubstring(s1,s2,n1-1,n2-1,dp)<<endl;
    cout<<"using bottom up : "<<countSubBU(s1,s2)<<endl;

    return 0;
}