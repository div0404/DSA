#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> triplets(vector<int> arr,int targetSum){
    sort(arr.begin(),arr.end()); //o(nlogn)
    int n = arr.size();

    vector<vector<int>> ans;

    //for every arr[i] pair sum o(n*n)
    for(int i=0;i<=n-3;i++){
        int j = i+1;
        int k = n-1;

        //two pointer approach (when arr is sorted)
        while(j<k){
            int currentSum = arr[i];
            currentSum += arr[j];
            currentSum += arr[k];

            if(currentSum == targetSum){
                ans.push_back({arr[i],arr[j],arr[k]});
                j++;
                k--;
            }
            else if(currentSum>targetSum){
                k--;
            }
            else{
                j++;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,15};
    int s = 18;

    auto result = triplets(arr,s);
    for(auto v : result){
        for(auto no : v){
            cout<<no<<",";
        }
        cout<<endl;
    }

    return 0;
}
