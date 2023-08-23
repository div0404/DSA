#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//o(nlogn)
pair<int,int> subarraySort(vector<int> arr){
    int n = arr.size();
    vector<int> sorted(arr);

    sort(sorted.begin(),sorted.end());

    int i = 0;
    int j = n-1;

    //finding the left 
    while(i<n and arr[i]==sorted[i]){
        i++;
    }
    //finding the right
    while(j>0 and arr[j]==sorted[j]){
        j--;
    }

    if(i==n-1){
        return {-1,-1};
    }
    
    return {i,j};
}

int main(){
    vector<int> arr = {1,2,3,4,5,8,6,7,9,10,11};
    pair<int,int> ans = subarraySort(arr);
    cout<<ans.first<<endl;
    cout<<ans.second<<endl;
    
    return 0;
}