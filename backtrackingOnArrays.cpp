#include<iostream>
using namespace std;

void print(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void fillingArray(int *arr, int i,int n,int val){
    // base case
    if(i==n){
        print(arr,n);
        return;
    }

    // rec case
    arr[i] = val;
    fillingArray(arr,i+1,n,val+1);

    //backtracking step
    arr[i] = -1*arr[i];
}

int main(){
    int arr[] = {0};
    int n;
    cin>>n;

    fillingArray(arr,0,n,1);
    print(arr,n);

    return 0;
}