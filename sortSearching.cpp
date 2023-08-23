#include<iostream>
using namespace std;

pair<int,int> stairCaseSearch(int arr[][10],int n,int m,int key){
    int i=0;
    int j=m-1;

    while(i<=n-1 and j>=0){
        if(arr[i][j]==key){
            return {i,j};
        }
        else if(arr[i][j]>key){
            j--;
        }
        else{
            i++;
        }
    }
    return {-1,-1};
}

int main(){
    int arr[][10] = {
        {10,20,30,40},
        {15,25,35,45},
        {27,29,37,48},
        {32,33,39,50}
    };

    int n=4;
    int m=4;
    int key;

    pair<int,int> coordinat = stairCaseSearch(arr,n,m,37);
    cout<<coordinat.first<<","<<coordinat.second<<endl;

    return 0;
}