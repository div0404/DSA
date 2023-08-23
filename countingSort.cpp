#include<iostream>
#include<vector>
using namespace std;

void countSort(int arr[], int n){
    int largestElement = -1;
    for(int i=0;i<n;i++){
        largestElement = max(largestElement,arr[i]);
    }

    vector<int> freq(largestElement+1,0);

    //update vector
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    for(int i=0;i<=largestElement;i++){
        cout<<freq[i]<<" ";
    }
    cout<<endl;

    int j=0;
    for(int i=0;i<=largestElement;i++){
        while(freq[i]>0){
            arr[j]=i;
            freq[i]--;
            j++;
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}    

int main(){
    int arr[]={3,2,7,1,4,6,2};
    int n = sizeof(arr)/sizeof(int);
    
    countSort(arr,n);

    return 0;
}