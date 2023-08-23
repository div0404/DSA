#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<int> getPairs(vector<int> arr,int sum){
    int n = arr.size();

    vector<int> ans;
    unordered_set<int> s;

    for(int i=0;i<n;i++){
        int compliment = sum - arr[i];
        if(s.find(compliment) != s.end()){
            ans.push_back(arr[i]);
            ans.push_back(compliment);
            return ans;
        }
        s.insert(arr[i]);
    }
    return {};
}

int main(){
    vector<int> arr = {10,5,2,3,-6,9,11};
    int s = 4;

    auto output = getPairs(arr,s);
    for(auto it : output){
        cout<<it<<",";
    }

    return 0;
}