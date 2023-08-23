#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    //Dynamic allocation
    int *arr = new int [n];

    for(int i=0;i<n;i++){
        // cin>>arr[i];
        cout<<i<<" ";
    }
    //delete
    delete [] arr;

    return 0;
}