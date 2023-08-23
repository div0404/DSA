#include<iostream>
using namespace std;

int firstOccurence(int arr[],int n,int key){
    //base case
    if(n==0){
        return -1;
    }

    //recursive case
    if(arr[0]==key){
        return 0;
    }
    int subIndex = firstOccurence(arr+1,n-1,key);
    if(subIndex != -1){
        return subIndex+1;
    }
    return -1;
}

int lastOccurence(int arr[],int n,int key){
    //base case
    if(n==0){
        return -1;
    }

    //recursive case

    int subIndex = lastOccurence(arr+1,n-1,key);
    if(subIndex==-1){
        if(arr[0]==key){
            return 0;
        }
        else{
            -1;
        }
    }
    else{
        return subIndex + 1;
    }
}

int main(){
    int arr[] = {2,4,15,9,8,6,15,9,10};
    int n = sizeof(arr)/sizeof(int);
    int key = 9;

    cout<<firstOccurence(arr,n,key)<<endl;
    cout<<lastOccurence(arr,n,key)<<endl;

    return 0;
}