#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//using recursion 
int lcs(string s1,string s2,int i,int j){
    //base case
    if(i == s1.length() || j == s2.length()){
        return 0;
    }

    //rec case
    //case 1
    if(s1[i]==s2[j]){
        return 1 + lcs(s1,s2,i+1,j+1);
    }
    
    //case 2
    int opt1 = lcs(s1,s2,i+1,j);
    int opt2 = lcs(s1,s2,i,j+1);
    return max(opt1,opt2);
}

//using top down
int lcsTD(string s1,string s2,vector<vector<int>> dp,int i,int j){
    //base case
    if(i==s1.length() || j==s2.length()){
        return 0;
    }

    //check the state
    if(dp[i][j] !=-1){
        return dp[i][j];
    }

    //rec case
    //case 1 
    if(s1[i] == s2[j]){
        return dp[i][j] = 1 + lcsTD(s1,s2,dp,i+1,j+1);
    }

    //case 2
    int opt1 = lcsTD(s1,s2,dp,i+1,j);
    int opt2 = lcsTD(s1,s2,dp,i,j+1);

    return dp[i][j] = max(opt1,opt2);
}

//using bottom up
int lcsBU(string s1,string s2){
    int n1 = s1.length();
    int n2 = s2.length();

    vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));

    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];            
            }
            else{
                int opt1 = dp[i-1][j];
                int opt2 = dp[i][j-1];
                dp[i][j] = max(opt1,opt2);
            }
        }
    } 

    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    vector<char> result;
    int i= n1, j = n2;
    while(i!=0 and j!=0){
        if(dp[i][j] == dp[i-1][j]){
            i--;
        }
        else if(dp[i][j] == dp[i][j-1]){
            j--;
        }
        else{
            result.push_back(s1[i-1]);
            i--;
            j--;
        }
    }
    reverse(result.begin(),result.end());

    for(auto x : result){
        cout<<x<<",";
    }
    cout<<endl;

    return dp[n1][n2];
}

int main(){
    string s2 = "ABCD";
    string s1 = "ABEDG";

    int n1 = s1.length();
    int n2 = s2.length();

    vector<vector<int>> dp(n1,vector<int> (n2,-1));

    cout<<"LCS using recursion : "<<lcs(s1,s2,0,0)<<endl;
    cout<<"LCS using top down : "<<lcsTD(s1,s2,dp,0,0)<<endl;
    cout<<"LCS using bottom up : "<<lcsBU(s1,s2)<<endl;

    return 0;
}