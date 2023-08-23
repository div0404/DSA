#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    int maxno = INT_MIN;
    int minno = INT_MAX;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    for(int i=0;i<n;i++){
         maxno = max(maxno,arr[i]);
         minno = min(minno,arr[i]);
    }
    cout<<"max: "<<maxno<<endl;
    cout<<"min: "<<minno<<endl;
   
    return 0;
}