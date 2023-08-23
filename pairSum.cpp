#include<iostream>
using namespace std;

bool pairSum(int arr[],int n,int key){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==key){
                cout<<i<<" "<<j<<endl;
                return true;
            }
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    int arr[] = {2,4,7,11,14,16,20,21};
    int key = 31;
    pairSum(arr,n,key);
    return 0;
}