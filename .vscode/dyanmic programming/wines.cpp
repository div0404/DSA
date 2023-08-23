#include<iostream>
#include<vector>
using namespace std;

//top down dp code
int wine(int dp[][10],int price[],int L,int R,int y){
    //base case
    if(L>R){
        return 0;
    }

    //if a state is already calculated
    if(dp[L][R]!=0){
        return dp[L][R];
    }

    //rec case
    int left_case = price[L]*y + wine(dp,price,L+1,R,y+1);
    int right_case = price[R]*y + wine(dp,price,L,R-1,y+1);

    return dp[L][R] = max(left_case,right_case);
}

//Bottom up dp
int bottomupdp(int price[],int n){
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    for(int i = n-1;i>=0;i--){
        //bottom to top filling
        for(int j=0;j<n;j++){
            int y = n-(j-i);
            if(i<j){
                int pick_left = price[i]*y + dp[i+1][j];
                int pick_right = price[j]*y + dp[i][j-1];

                dp[i][j] = max(pick_left,pick_right);    
            }
            else if(i==j){
                dp[i][j] = n*price[i];  //y=n-(j-i)=n;             
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
    int a[] = {2,3,5,1,4};
    int n = 5;

    int dp[10][10] = {0};

    cout<<wine(dp,a,0,n-1,1)<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<endl;
    
    cout<<bottomupdp(a,n)<<endl;

    return 0;
}