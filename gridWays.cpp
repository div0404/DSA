#include<iostream>
using namespace std;

int gridWays(int i,int j,int m,int n){
    //base case 
    if(i == m-1 and j == n-1){
        return 1;
    }
    
    //corner case
    if(i>=m or j>=n){
        return 0;
    }

    //rec case
    int ways = gridWays(i,j+1,m,n) + gridWays(i+1,j,m,n);
    return ways;
}

int main(){
    int m,n;
    cin>>m>>n;

    cout<<gridWays(0,0,m,n);

    return 0;
}