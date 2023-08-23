#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int largestBand(vector<int> arr){
    int n = arr.size();
    int largestLen = 1;

    unordered_set<int> s;
    for(auto i : arr){
        s.insert(i);
    }

    for(int element : s){
        int parent = element-1;

        if(s.find(parent)==s.end()){
            //find band, chain starting from element
            int next_no = element + 1;
            int cnt = 1;

            while(s.find(next_no)!=s.end()){
                cnt++;
                next_no++;
            }
            if(cnt>largestLen){
                largestLen = cnt;
            }
        }
    }
    return largestLen;
}

int main(){
    vector<int> arr = {1,9,3,0,18,5,2,10,7,4,12,6};

    cout<<largestBand(arr)<<endl;

    return 0;
}