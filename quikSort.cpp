#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &a,int s,int e){
    int pivot = a[e];
    int i = s-1;
    for(int j=s;j<e;j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[e]);
    return i+1;
}

void quickSort(vector<int> &a,int s,int e){
    //base case
    if(s>=e){
        return; 
    }

    //rec case
    int p = partition(a,s,e);
    quickSort(a,s,p-1);
    quickSort(a,p+1,e);
    return;
}

int main(){
    vector<int> arr{2,7,6,9,4,5};
    int n = arr.size();

    quickSort(arr,0,n-1);
    for(int x : arr){
        cout<<x<<" ";
    }

    return 0;
}