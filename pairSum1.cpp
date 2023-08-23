#include<iostream>
using namespace std;

bool pairSum(int arr[],int n,int key){
    int low = 0;
    int high = n-1;

    while(low<high){
        if(arr[low]+arr[high]==key){
            cout<<low<<" "<<high<<endl;
            return true;
        }
        else if(arr[low]+arr[high]<key){
            low++;
        }
        else{
            high--;
        }
    }
    return false;
}
int main(){
    int n=8;
    int key =31;

    int arr[] = {2,4,7,11,14,16,20,21};

    pairSum(arr,n,key);

    return 0;
}