#include<iostream>
#include<vector>
using namespace std;

int highestPeak(vector<int> arr){
    int n = arr.size();

    int largest = 0;

    //1st and last element will not be a peak
    //finding the peaks

    for(int i=1;i<=n-2;){
        //if it is peak
        if(arr[i] > arr[i-1] and arr[i]>arr[i+1]){
            //do some work
            int cnt = 1;

            //cnt backwards (left)
            int j = i;
            while(arr[j]>arr[j-1] and j>=1){
                j--;
                cnt++;
            }

            //cnt forwards (right)
            while(i<=n-2 and arr[i]>arr[i+1]){
                i++;
                cnt++;
            }
            largest = max(cnt,largest);
        }
        else{
            i++;
        }
    }
    return largest;
}

int main(){
    vector<int> arr = {5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};

    cout<<highestPeak(arr)<<endl;
    
    return 0;
}