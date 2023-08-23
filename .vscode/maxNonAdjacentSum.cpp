#include<iostream>
#include<vector>
#include<climits>
using namespace std;

/*int maxSum(vector<int> arr,int n,vector<int> dp,int i){
    //base case
    if(n==1){
        return arr[0];
    }
    if(n==2){
        return max(arr[0],arr[1]);
    }

    //check if state is already computed
    if(dp[n]!=0){
        return dp[n];
    }

    //rec case
    //if including the ith no
        int opt1 = arr[i] + maxSum(arr,n-1,dp,i-2);
    //if excluding the ith no
        int opt2 = maxSum(arr,n-1,dp,i-1);

    dp[i] = max(opt1,opt2);

    return dp[n];
}*/

//bottom up
int maxSumBU(vector<int> arr,int n,vector<int> dp,int i){
    //initialisation
    dp[0] = arr[0];
    dp[1] = max(arr[0],arr[1]);

    for(int i=2;i<n;i++){
        //including the ith element
        int opt1 = arr[i] + dp[i-2];
        //excluding the ith element
        int opt2 = dp[i-1];
        
        dp[i] = max(opt1,opt2);
    }
    return dp[n-1];
}

int main(){
    vector<int> arr = {6,10,12,7,9,14};
    int n = arr.size();

    vector<int> dp(n+1,0);

    //cout<<"max non adjacent sum using top down: "<<maxSum(arr,n,dp,0)<<endl;
    cout<<"max non adjacent sum using bottom up: "<<maxSumBU(arr,n,dp,0)<<endl;
    return 0;
}