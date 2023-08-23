#include<iostream>
#include<climits>
using namespace std;

//brute force approach
void subarraySum(int arr[], int n){
  int maxSum = INT_MIN;
                                               //O(n^3)
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
        //cout<<"("<<i<<","<<j<<") ";
        int currSum = 0;
      for(int k=i;k<=j;k++){
        //print all subarray of a given array
        //cout<<arr[k]<<" ";

        //subarrray sum
        currSum += arr[k];
      }
       //cout<<currSum;
        maxSum = max(maxSum,currSum);
    } 
  }
  cout<<maxSum<<endl;
}

//using prefix sum
void prefixSum(int arr[], int n){
  int maxSum = INT_MIN;                               //O(n^2)

  int prefix[100] = {0};        //storing cumulative sum
  prefix[0] = arr[0];

  for(int i=1;i<n;i++){
    prefix[i] = prefix[i-1] + arr[i];
  }

  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
      int subarraySum = i>0 ? prefix[j] - prefix[i-1] : prefix[j];
      maxSum = max(maxSum,subarraySum);
    }
  }
  cout<<maxSum<<endl;
}

int main(){
  int arr[] = {-2,5,-7,11,3};
  int n = sizeof(arr)/sizeof(int);

  subarraySum(arr,n);
  prefixSum(arr,n);
}

  // we can use kadens algorithm for max subarray sum with O(n) (next)