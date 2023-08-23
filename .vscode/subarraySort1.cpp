#include<iostream>
#include<vector>
#include<climits>
using namespace std;

bool outOfOrder(vector<int> arr,int i){
    if(i==0){
        return arr[i]>arr[i+1];
    }
    if(i==arr.size()-1){
        return arr[i]<arr[i-1];
    }
    return arr[i]<arr[i-1] or arr[i]>arr[i+1];
}

pair<int,int> subarraySort(vector<int> arr){
    int n = arr.size();

    int smallest = INT_MAX;
    int largest = INT_MIN;

    for(int i=0;i<n;i++){
        int x = arr[i];

        if(outOfOrder(arr,i)){
            smallest = min(smallest,x);
            largest = max(largest,x);
        }

    }

    if(smallest == INT_MAX){
        return {-1,-1};
    }

    //find the corrent idx of smallest and largest
    int i = 0;
    int j = n-1;

    while(arr[i]<=smallest){
        i++;
    }

    while(arr[j]>largest){
        j--;
    }

    return {i,j};
}

int main(){
    vector<int> arr = {1,2,3,4,5,8,6,7,9,10,11};
    pair<int,int> ans = subarraySort(arr);

    cout<<ans.first<<",";
    cout<<ans.second<<endl;

    return 0;
}