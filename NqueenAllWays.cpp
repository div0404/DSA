#include<iostream>
using namespace std;

void print(int board[][20],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool canPlace(int board[][20],int n,int x,int y){
    //column
    for(int k=0;k<x;k++){
        if(board[k][y] == 1){
            return false;
        }
    }

    // left diaganol
    int i = x;
    int j = y;

    while(i>=0 and j>=0){
        if(board[i][j] == 1){
            return false;
        }
        i--,j--;
    }

    //right diagonal
    i = x;
    j = y;
    while(i>=0 and j<n){
        if(board[i][j] == 1){
            return false;
        }
        i--,j++;
    }
    return true;
}

int solveNqueen(int n,int board[][20],int i){
    //base case
    if(i == n){
        //print thre board
        print(board,n);
        return 1;
    }

    //rec case
    //try to place queen in every row
    int ways = 0;

    for(int j=0;j<n;j++){
        if(canPlace(board,n,i,j)){
            board[i][j] = 1;
            ways  += solveNqueen(n,board,i+1);
            
            //backtracking
            board[i][j] = 0;
        }
    }
    return ways;
}

int main(){
    int board[20][20] = {0};
    int n;
    cin>>n;

    solveNqueen(n,board,0);

    return 0;
}