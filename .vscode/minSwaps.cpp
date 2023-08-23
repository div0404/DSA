#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minSwaps(vector<int> arr){
    int n = arr.size();
    
    pair<int,int> ap[n];
    for(int i=0;i<n;i++){
        ap[i].first = arr[i];
        ap[i].second = i;
    }

    sort(ap,ap+n);

    vector<bool> visited(n,false);
    int ans = 0;
    for(int i=0;i<n;i++){
        //if element is already visited or at correct position
        int oldnode = ap[i].second;
        if(visited[i]==true or oldnode==i){
            continue;
        }
        //if visiting the node first time
        int element = 0;  //no of element in a cycle.
        int node = i;
        while(!visited[node]){
            visited[node] = true;
            int nextnode = ap[node].second;
            node = nextnode;
            element++;
        }
        ans += element-1;
    }
    return ans;
}

int main(){
    vector<int> arr = {10,11,5,4,3,2,1};
    cout<<minSwaps(arr)<<endl;
    return 0;
}