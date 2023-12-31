#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool canPlace(vector<int> b1,vector<int> b2){
    if(b1[0]<b2[0] and b1[1]<b2[1] and b1[2]<b2[2]){
        return true;
    }
    return false;
}

bool compare(vector<int> b1,vector<int> b2){
    return b1[2] < b2[2];
}

int maxHeight(vector<vector<int>> boxes){
    int n = boxes.size();

    //sorting the boxes vector acc to height
    sort(boxes.begin(),boxes.end(),compare);

    vector<int> dp(n+1);
    //initializing the dp vector
    for(int i=0;i<n;i++){
        dp[i] = boxes[i][2];
    }

    for(int i=1;i<n;i++){
        //iterate the prev boxes
        for(int j=0;j<i;j++){
            if(canPlace(boxes[j],boxes[i])){
                int current_height = boxes[i][2];
                if(current_height + dp[j] > dp[i]){
                    dp[i] = current_height + dp[j];
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;

    //iterate over the dp 
    int max_height = 0;
    for(int i=0;i<n;i++){
        max_height = max(max_height,dp[i]);
    }
    return max_height;
}

int main(){
    vector<vector<int>> boxes = {
        {2,1,2},
        {3,2,3},
        {2,2,8},
        {2,3,4},
        {2,2,1},
        {4,4,5}
    };

    int height = maxHeight(boxes);
    cout<<"max height : "<<height<<endl;

    return 0;
}