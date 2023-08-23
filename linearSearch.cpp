#include<iostream>
using namespace std;

int linearSearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            cout<<i<<endl;
        }
    }
    return -1;
}
int main(){
    int n;
    int key;
    cin>>n;
    cin>>key;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    linearSearch(arr,n,key);
    return 0;
}