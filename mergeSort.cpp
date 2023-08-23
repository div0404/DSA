#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr,int s,int e){
    int i = s;
    int m = (s+e)/2;
    int j = m+1;

    // creating temp arr
    vector<int> temp;
    
    // compare elements from left and right and pushback to temp arr
    while(i<=m and j<=e){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    // copy back rem elements from left arr
    while(i<=m){
        temp.push_back(arr[i++]);
    }

    // copy back rem elements from right arr
    while(j<=e){
        temp.push_back(arr[j++]);
    }

    // copy back temp to original arr
    int k = 0;
    for(int idx = s;idx <= e; idx++){
        arr[idx] = temp[k++];
    }
    
    return;
}
void mergeSort(vector<int> &arr,int s,int e){
    //base case
    if(s>=e){
        return;
    }

    //rec case
    int mid = (s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    return merge(arr,s,e);
}

int main(){

    vector<int> arr = {2,5,0,7,9,1,6}; 
    int s = 0;
    int e = arr.size() - 1;
    
    mergeSort(arr,s,e);
    for(int x : arr){
        cout<<x<<",";
    }

    return 0;
}