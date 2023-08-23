#include<iostream>
#include<vector>
using namespace std;

int rotatedSearch(vector<int> &arr,int key){
    int n = arr.size();
    int i = 0;
    int e = n-1;

    while(i<=e){
        int mid = (i+e)/2;

        if(key == arr[mid]){
            return mid;
        }
        // 2 cases
        if(arr[i]<=arr[mid]){
            if(key<=arr[mid] and key>=arr[i]){
                e = mid - 1;
            }
            else{
                i = mid + 1;
            }
        }
        else{
            if(key>=arr[mid] and key<=arr[e]){
                i = mid + 1;
            }
            else{
                e = mid -1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> arr{7,8,9,1,2,4,5};
    int key;
    cin>>key;

    cout<<rotatedSearch(arr,key)<<endl;

    return 0;
}