#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//Top down 
int minAraayJump(vector<int> arr,int n,vector<int> dp,int i){
    //base case
    if(i==n-1){
        return 0;
    }
    //corner case
    if(i>=n){
        dp[i] = INT_MAX;
    }

    //check if state is already computed
    if(dp[i]!=0){
        return dp[i];
    }

    //rec case
    int steps = INT_MAX;
    int max_jump = arr[i];

    for(int jump = 1;jump<=max_jump;jump++){
        int next_cell = i + jump;
        int subproblem = minAraayJump(arr,n,dp,next_cell);
        if(subproblem != INT_MAX){
            steps = min(steps,subproblem+1);
        }
    }
    return dp[i] = steps;
}

int main(){
    vector<int> arr = {3,4,2,1,2,3,7,1,1,1,2,5};
    int n = arr.size();
    vector<int>dp(n+1,0);

    cout<<"min steps : "<<minAraayJump(arr,n,dp,0)<<endl;

    return 0;
}