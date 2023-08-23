#include<iostream>
using namespace std;

void print(int arr[][10],int n,int m){
    int start_row = 0;
    int end_col = m-1;
    int end_row = n-1;
    int start_col = 0;

    while(start_row <= end_row and start_col <= end_col){
        //start_row
        for(int col = start_col;col<=end_col;col++){
            cout<<arr[start_row][col]<<" ";
        }

        //end_col
        for(int row = start_row+1;row<=end_row;row++){
            cout<<arr[row][end_col]<<" ";
        }

        //end_row
        for(int col = end_col-1;col>=start_col;col--){
            if(start_row==end_row){
                break;
            }
            cout<<arr[end_row][col]<<" ";
        }

        //start_col
        for(int row= end_row-1;row>=start_col+1;row--){
            //duplicate
            if(start_col==end_col){
                break;
            }
            cout<<arr[row][start_col]<<" ";
        }

        start_row++;
        end_col--;
        end_row--;
        start_col++;
    }
}

int main(){
    int arr[][10]={
        {1,2,3,4},
        {6,9,11,13},
        {8,10,14,16},
        {5,7,15,17}
    };

    int n = 4;
    int m = 4;

    print(arr,n,m);

    return 0;
}