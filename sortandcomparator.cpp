#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a,int b){
    return a < b;
}
int main(){
    int arr[] = {10,5,4,11,7,3,8};
    int n = sizeof(arr)/sizeof(int);

    //sort(arr,arr+n,compare);
    
    //reverse order print
    sort(arr,arr+n,greater<int> ());
    
   // reverse(arr,arr+n);

    for(int x : arr){
        cout<<x<<" ";
    }

    return 0;
}