#include<iostream>
#include<climits>
using namespace std;

int kadens(int arr[],int n){
    int currSum = 0;
    int maxSum = INT_MIN;
    for(int i=0;i<n;i++){
        currSum += arr[i];
        if(currSum<0){
            currSum = 0;
        }
        maxSum = max(maxSum,currSum);
    }
    return maxSum;
}
int main(){
    int n;
    cin>>n;
    int arrSum = 0;
    int wrapSum;
    int nonWrapSum;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        arrSum += arr[i];
        arr[i] = -arr[i];
    }
    nonWrapSum = kadens(arr,n);
    wrapSum = arrSum - (-kadens(arr,n));
    int maxsubarraySum = max(wrapSum,nonWrapSum);
    cout<<maxsubarraySum<<endl;

    return 0;
}