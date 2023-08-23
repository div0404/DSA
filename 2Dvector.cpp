#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<vector<int>> arr = {
        {1,41,62},
        {5,41,20},
        {2,5,15,9},
        {43,59}
    };

    //update
    arr[0][0] = 11;

    //print
    for(int i=0;i<arr.size();i++){
        for(int number : arr[i]){
            cout<<number<<" ";
        }
        cout<<endl;
    }
    return 0;
}