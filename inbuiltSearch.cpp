#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> arr = {4,8,10,45,3,7};
    int key;
    cin>>key;

    vector<int> :: iterator it = find(arr.begin(),arr.end(),key);
    
    if(it != arr.end()){
        cout<<"Index is :"<<it-arr.begin()<<endl;
    }
    else{
        cout<<"Key not found"<<endl;
    }

    return 0;
}