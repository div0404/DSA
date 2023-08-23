#include<iostream>
#include<vector>
using namespace std;

int water(vector<int> heights){
    int n = heights.size();
    //corner case
    if(n<=2){
        return 0;
    }

    vector<int> left(n,0);
    vector<int> right(n,0);

    left[0] = heights[0];
    right[n-1] = heights[n-1];

    //updating the heighest left so far
    for(int i=1;i<n;i++){
        left[i] = max(left[i-1],heights[i]);
    }

    //updating the heighest right so far
    for(int i=n-2;i>=0;i--){
        right[i] = max(right[i+1],heights[i]);
    }

    //water
    int water = 0;
    for(int i=0;i<n;i++){
        water += min(left[i],right[i]) - heights[i];
    }

    return water;
}

int main(){
    vector<int> heights = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<water(heights)<<endl;
  
    return 0;
}