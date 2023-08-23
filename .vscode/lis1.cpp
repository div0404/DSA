#include<iostream>
#include<vector>
using namespace std;

int lis(vector<int> arr) {
    int n = arr.size();

    vector<int> dp(n+1,1);
    int len = 1;

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        len = max(len,dp[i]);
    }
    return len;
}

int main(){
    vector<int> arr = {50,4,10,8,30,100};

    cout<<"longest increasing subsequence : "<<lis(arr)<<endl;

    return 0;
}